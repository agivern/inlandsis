#include "fmap.h"

#define SGN(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))
#define ABS(X) ((((X)<0)?(-(X)):(X)))

void RecupererVecteur(Input* in,int* vx,int* vy)
{
	int vitesse = 2;
	*vx = *vy = 0;
	if (in->key[SDLK_UP])
		*vy = -vitesse;
	if (in->key[SDLK_DOWN])
		*vy = vitesse;
	if (in->key[SDLK_LEFT])
		*vx = -vitesse;
	if (in->key[SDLK_RIGHT])
		*vx = vitesse;
}

int EssaiDeplacement(Map* carte,SDL_Rect* perso,int vx,int vy)
{
	SDL_Rect test;
	test = *perso;
	test.x+=vx;
	test.y+=vy;
	if (CollisionDecor(carte,&test)==0)
	{
		*perso = test;
		return 1;
	}
	return 0;
}

void Deplace(Map* carte,SDL_Rect* perso,int vx,int vy,int LARGEUR_TILE,int HAUTEUR_TILE)
{
	int i;
	if (vx>=LARGEUR_TILE || vy>=HAUTEUR_TILE)
	{
		Deplace(carte,perso,vx/2,vy/2,LARGEUR_TILE,HAUTEUR_TILE);
		Deplace(carte,perso,vx-vx/2,vy-vy/2,LARGEUR_TILE,HAUTEUR_TILE);
		return;
	}
	if (EssaiDeplacement(carte,perso,vx,vy)==1)
		return;
// affine
	for(i=0;i<ABS(vx);i++)
	{
		if (EssaiDeplacement(carte,perso,SGN(vx),0)==0)
			break;
	}
	for(i=0;i<ABS(vy);i++)
	{
		if (EssaiDeplacement(carte,perso,0,SGN(vy))==0)
			break;			
	}
}

void Evolue(Input* in,Map* carte,SDL_Rect* perso,int LARGEUR_TILE,int HAUTEUR_TILE)
{
	int vx,vy;
	RecupererVecteur(in,&vx,&vy);
	Deplace(carte,perso,vx,vy,LARGEUR_TILE,HAUTEUR_TILE);
}

void AfficherPerso(SDL_Rect* perso,SDL_Surface* screen,int xscroll,int yscroll)
{
	SDL_Rect positionsurecran = *perso;
	positionsurecran.x -= xscroll;
	positionsurecran.y -= yscroll;
	SDL_FillRect(screen,&positionsurecran,0x00FF00); 
}

void maping(SDL_Surface* ecran, int *continuer2)
{
	SDL_Rect perso,limit;
	SDL_Surface* screen;
	Map* carte;
	Input in;
	int LARGEUR_TILE,HAUTEUR_TILE;
	LARGEUR_TILE = 24;
	HAUTEUR_TILE = 16;
	memset(&in,0,sizeof(in));
	SDL_Init(SDL_INIT_VIDEO);		// preapare SDL
	carte = ChargerMap("tileset1.bmp","level2.bmp","corresp1.bmp","tileprop1.txt",LARGEUR_TILE,HAUTEUR_TILE,800,600);
	screen = SDL_SetVideoMode(carte->largeur_fenetre,carte->hauteur_fenetre,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	perso.x = 150;
	perso.y = 150;
	perso.w = 24;
	perso.h = 32;
	limit.x = 200;
	limit.y = 150;
	limit.w = 400;
	limit.h = 300;
	while(x == 1 & *continuer2 != 0)
	{
		UpdateEvents(&in);
		Evolue(&in,carte,&perso,LARGEUR_TILE,HAUTEUR_TILE);
		FocusScrollCenter(carte,&perso);
		//FocusScrollBox(carte,&perso,&limit);
		AfficherMap(carte,screen);
		AfficherPerso(&perso,screen,carte->xscroll,carte->yscroll);
        
        if (Tcombat == 1)
           {combat(ecran, continuer2);
            memset(&in,0,sizeof(in));
            Tcombat = 0;}
            
        SDL_Flip(screen);
	}
	LibererMap(carte);
}
