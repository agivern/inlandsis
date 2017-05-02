#define _CRT_SECURE_NO_DEPRECATE   // pour visual C++ qui met des warning pour fopen et fscanf : aucun effet negatif pour les autres compilos.
#include <string.h>
#include "fmap.h"


char LocatePixInCorr(SDL_Surface* corr,Uint32 pix)
{
	int i,j;
	for(j=0;j<corr->h;j++)
		for(i=0;i<corr->w;i++)
			if (GetPixel32(corr,i,j)==pix)
				return (char)(j*corr->w + i);
	return 0;
}

TileProp* ChargerProps(const char* tileprop,int nombre_props)
{
	char buf[500];
	FILE* F;
	int i;
	int useless;
	TileProp* res = calloc(nombre_props,sizeof(TileProp)); // alloue et met tout a 0.
	F = fopen(tileprop,"r");
	if (F==NULL)
	{
		printf("fichier %s introuvable !!\n",tileprop);
		exit(-1);
	}
	for(i=0;i<nombre_props;i++)
	{
		fscanf(F,"%d %s",&useless,buf);
		if (strcmp(buf,"mur")==0)
			res[i].mur = 1;
	}
	fclose(F);
	return res;
}

void CalculerSDLRects(TileProp* tabprops,int nombre_props,int nombre_tiles_largeur,int largeur_tile,int hauteur_tile)
{
	int i;
	for(i=0;i<nombre_props;i++)
	{
		tabprops[i].R.w = largeur_tile;
		tabprops[i].R.h = hauteur_tile;
		tabprops[i].R.x = largeur_tile*(i%nombre_tiles_largeur);
		tabprops[i].R.y = hauteur_tile*(i/nombre_tiles_largeur);
	}
}


Map* ChargerMap(const char* tileset,const char* image_schema,const char* image_corr,const char* tileprop,int largeur_tile,
				int hauteur_tile,int largeur_fenetre,int hauteur_fenetre)
{
	int i,j;
	Map* res;
	SDL_Surface* schema,*corr;
	Uint32 pix;
	res = malloc(sizeof(Map));
	res->LARGEUR_TILE = largeur_tile;
	res->HAUTEUR_TILE = hauteur_tile;
	res->tileset = LoadImage32(tileset,1);  // charge le tileset en VRAM pour meilleur vitesse de Blit.
	schema = LoadImage32(image_schema,0);
	corr = LoadImage32(image_corr,0);
	res->nbtiles = (res->tileset->w / largeur_tile) * (res->tileset->h / hauteur_tile);
	res->props = ChargerProps(tileprop,res->nbtiles);
	CalculerSDLRects(res->props,res->nbtiles,res->tileset->w / largeur_tile,largeur_tile,hauteur_tile);
	res->nbtiles_largeur_monde = schema->w;
	res->nbtiles_hauteur_monde = schema->h;
	res->schema = malloc(schema->w * sizeof(char*));
	for(i=0;i<schema->w;i++)
	{
		res->schema[i] = malloc(schema->h * sizeof(char));
		for(j=0;j<schema->h;j++)
		{
			pix = GetPixel32(schema,i,j);
			res->schema[i][j] = LocatePixInCorr(corr,pix);
		}
	}
	SDL_FreeSurface(schema);
	SDL_FreeSurface(corr);
	res->largeur_fenetre = largeur_fenetre;
	res->hauteur_fenetre = hauteur_fenetre;
	res->xscroll = 0;
	res->yscroll = 0;
	return res;
}


int AfficherMap(Map* m,SDL_Surface* screen)
{
	int i,j;
	SDL_Rect Rect_dest;
	int numero_tile;
	int minx,maxx,miny,maxy;
	minx = m->xscroll / m->LARGEUR_TILE;
	miny = m->yscroll / m->HAUTEUR_TILE;
	maxx = (m->xscroll + m->largeur_fenetre)/m->LARGEUR_TILE;
	maxy = (m->yscroll + m->hauteur_fenetre)/m->HAUTEUR_TILE;
	for(i=minx;i<=maxx;i++)
	{
		for(j=miny;j<=maxy;j++)
		{
			Rect_dest.x = i*m->LARGEUR_TILE - m->xscroll;
			Rect_dest.y = j*m->HAUTEUR_TILE - m->yscroll;
			numero_tile = m->schema[i][j];
			SDL_BlitSurface(m->tileset,&(m->props[numero_tile].R),screen,&Rect_dest);
		}
	}
	return 0;
}

void LibererMap(Map* m)
{
	int i;
	for(i=0;i<m->nbtiles_hauteur_monde;i++)
		free(m->schema[i]);
	free(m->schema);
	free(m->props);
	free(m);
}

int CollisionDecor(Map* carte,SDL_Rect* perso)
{
	int xmin,xmax,ymin,ymax,i,j,indicetile;
	xmin = (perso->x + 5) / (carte->LARGEUR_TILE );
	ymin = (perso->y + 20) / (carte->HAUTEUR_TILE );
	xmax = (perso->x + perso->w - 5) / carte->LARGEUR_TILE;
	ymax = (perso->y + perso->h - 1) / carte->HAUTEUR_TILE;
	if ((perso->x + 37) / (carte->LARGEUR_TILE ) < 1 || (perso->y + 34) / (carte->HAUTEUR_TILE ) < 1 || xmax>=carte->nbtiles_largeur_monde || ymax>=carte->nbtiles_hauteur_monde)
		return 1;
	for(i=xmin;i<=xmax;i++)
	{
		for(j=ymin;j<=ymax;j++)
		{
			indicetile = carte->schema[i][j];
			if (carte->props[indicetile].mur)
				return 1;
		}
	}
	return 0;
}

void ClampScroll(Map* m)
{
	if (m->xscroll<0)
		m->xscroll=0;
	if (m->yscroll<0)
		m->yscroll=0;
	if (m->xscroll>m->nbtiles_largeur_monde*m->LARGEUR_TILE-m->largeur_fenetre-1)
		m->xscroll=m->nbtiles_largeur_monde*m->LARGEUR_TILE-m->largeur_fenetre-1;
	if (m->yscroll>m->nbtiles_hauteur_monde*m->HAUTEUR_TILE-m->hauteur_fenetre-1)
		m->yscroll=m->nbtiles_hauteur_monde*m->HAUTEUR_TILE-m->hauteur_fenetre-1;
}

int FocusScrollCenter(Map* carte,SDL_Rect* perso)
{
	carte->xscroll = perso->x + perso->w/2 - carte->largeur_fenetre/2;
	carte->yscroll = perso->y + perso->h/2 - carte->hauteur_fenetre/2;
	ClampScroll(carte);
	return 0;
}

int FocusScrollBox(Map* carte,SDL_Rect* perso,SDL_Rect* limit)
{
	int cxperso,cyperso,xlimmin,xlimmax,ylimmin,ylimmax;
	cxperso = perso->x + perso->w/2;
	cyperso = perso->y + perso->h/2;
	xlimmin = carte->xscroll + limit->x;
	ylimmin = carte->yscroll + limit->y;
	xlimmax = xlimmin + limit->w;
	ylimmax = ylimmin + limit->h;
	if (cxperso<xlimmin)
		carte->xscroll -= (xlimmin-cxperso);
	if (cyperso<ylimmin)
		carte->yscroll -= (ylimmin-cyperso);
	if (cxperso>xlimmax)
		carte->xscroll += (cxperso-xlimmax);
	if (cyperso>ylimmax)
		carte->yscroll += (cyperso-ylimmax);
	ClampScroll(carte);
	return 0;
}

int collisionPNJ (SDL_Rect* perso, SDL_Rect* pnj)
{
     if (perso->y < pnj->y + 18 & perso->y > pnj->y + 4 & perso->x < pnj->x + 20 & perso->x > pnj->x - 20)
         return 0;
     
     if (perso->y + 32 > pnj->y  & perso->y + 32 < pnj->y + 10 & perso->x > pnj->x - 20 & perso->x < pnj->x + 20 )
         return 0;
     
     if (perso->x + 32 > pnj->x + 12 & perso->x + 32 < pnj->x + 32 & perso->y + 32 > pnj->y & perso->y < pnj->y + 18)
         return 0;
     
     if (perso->x > pnj->x & perso->x < pnj->x + 20 & perso->y + 32 > pnj->y & perso->y < pnj->y + 18)
         return 0;
         
     else
         return 1;
}
