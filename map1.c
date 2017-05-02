#include "fmap.h"
#include "variable.h"
#include "SDL/SDL_ttf.h"

#define SGN(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))
#define ABS(X) ((((X)<0)?(-(X)):(X)))

void RecupererVecteur(Input* in,int* vx,int* vy, int* varianteclip2)
{
	int vitesse = 6;
	*vx = *vy = 0;
	
	if (in->key[SDLK_UP] || in->key[SDLK_w])
		{
        *vy = -vitesse;
		testvitesse++;
		if ( *varianteclip2 < 9 || *varianteclip2 > 11)
		    *varianteclip2 = 9;
		if (testvitesse > 2)
		{
            testdepla ++;
            testvitesse = 0;
		    *varianteclip2 = 9 + testdepla;
		    if (*varianteclip2 > 11)
		        {*varianteclip2 = 9;
		        testdepla = 0;}
        }
        }
        
	if (in->key[SDLK_DOWN] || in->key[SDLK_s])
		{*vy = vitesse;
		testvitesse++;
		if ( *varianteclip2 < 0 || *varianteclip2 > 2)
		    *varianteclip2 = 0;
		if (testvitesse > 2)
		{
            testvitesse = 0;
		    *varianteclip2 = *varianteclip2 + 1;
		    if (*varianteclip2 > 2)
		        *varianteclip2 = 0;
        }
        }
        
	if (in->key[SDLK_LEFT] || in->key[SDLK_a])
		{*vx = -vitesse;
		testvitesse++;
		if ( *varianteclip2 < 3 || *varianteclip2 > 5)
		    *varianteclip2 = 3;
		if (testvitesse > 2)
		{
            testdepla ++;
            testvitesse = 0;
		    *varianteclip2 = 3 + testdepla;
		    if (*varianteclip2 > 5)
		        {*varianteclip2 = 3;
		        testdepla = 0;}
        }
        }
		
	if (in->key[SDLK_RIGHT] || in->key[SDLK_d])
		{*vx = vitesse;
		testvitesse++;
		if ( *varianteclip2 < 6 || *varianteclip2 > 8)
		    *varianteclip2 = 6;
		if (testvitesse > 2)
		{
            testdepla ++;
            testvitesse = 0;
		    *varianteclip2 = 6 + testdepla;
		    if (*varianteclip2 > 8)
		        {*varianteclip2 = 6;
		        testdepla = 0;}
        }
        }
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

void Evolue(Input* in,Map* carte,SDL_Rect* perso,int LARGEUR_TILE,int HAUTEUR_TILE, int *variantenclip, AffObjet* personnage)
{
	int vx,vy, varianteclip2 = *variantenclip;
	RecupererVecteur(in,&vx,&vy, &varianteclip2);
	Deplace(carte,perso,vx,vy,LARGEUR_TILE,HAUTEUR_TILE);
	*variantenclip = varianteclip2;
}

void AfficherPerso(SDL_Rect* perso,SDL_Surface* screen,int xscroll,int yscroll, SDL_Rect* clip, AffObjet* personnage,SDL_Surface* imagePerso)
{
	SDL_Rect positionsurecran = *perso;
	positionsurecran.x -= xscroll;
	positionsurecran.y -= yscroll;
	SDL_BlitSurface(imagePerso, clip + (personnage->nclip), screen, &positionsurecran);
}

int map1(SDL_Surface* ecran, int *continuer2)
{
	SDL_Rect limit, clip[ 12 ], perso, centrage;
	SDL_Surface *screen, *imagePerso = NULL;
	
    SDL_Event event;
	
	int variantenclip = clipvarie;
	int tempsPrecedent = 0, tempsActuel = 0;
	
	AffObjet personnage = {0};
    sprintf(zone, "Maison");
    
    clip[ 0 ].x = 0;
    clip[ 0 ].y = 0;
    clip[ 0 ].w = 32;
    clip[ 0 ].h = 32;

    clip[ 1 ].x = 32;
    clip[ 1 ].y = 0;
    clip[ 1 ].w = 32;
    clip[ 1 ].h = 32;
    
    clip[ 2 ].x = 64;
    clip[ 2 ].y = 0;
    clip[ 2 ].w = 32;
    clip[ 2 ].h = 32;
    
    clip[ 3 ].x = 0;
    clip[ 3 ].y = 32;
    clip[ 3 ].w = 32;
    clip[ 3 ].h = 32;

    clip[ 4 ].x = 32;
    clip[ 4 ].y = 32;
    clip[ 4 ].w = 32;
    clip[ 4 ].h = 32;
    
    clip[ 5 ].x = 64;
    clip[ 5 ].y = 32;
    clip[ 5 ].w = 32;
    clip[ 5 ].h = 32;
    
    clip[ 6 ].x = 0;
    clip[ 6 ].y = 64;
    clip[ 6 ].w = 32;
    clip[ 6 ].h = 32;

    clip[ 7 ].x = 32;
    clip[ 7 ].y = 64;
    clip[ 7 ].w = 32;
    clip[ 7 ].h = 32;
    
    clip[ 8 ].x = 64;
    clip[ 8 ].y = 64;
    clip[ 8 ].w = 32;
    clip[ 8 ].h = 32;
    
    clip[ 9 ].x = 0;
    clip[ 9 ].y = 96;
    clip[ 9 ].w = 32;
    clip[ 9 ].h = 32;

    clip[ 10 ].x = 32;
    clip[ 10 ].y = 96;
    clip[ 10 ].w = 32;
    clip[ 10 ].h = 32;
    
    clip[ 11 ].x = 64;
    clip[ 11 ].y = 96;
    clip[ 11 ].w = 32;
    clip[ 11 ].h = 32;
    
	Map* carte;
	Input in;
	int LARGEUR_TILE,HAUTEUR_TILE, Tcombat, x = 1;
	LARGEUR_TILE = 32;
	HAUTEUR_TILE = 32;
	memset(&in,0,sizeof(in));
	
	imagePerso = SDL_LoadBMP("images/chara/images.bmp");
	SDL_SetColorKey(imagePerso, SDL_SRCCOLORKEY, SDL_MapRGB(imagePerso->format, 255, 43, 64));
    	
	carte = ChargerMap("images/map/Introduction/map1/tileset.bmp","images/map/Introduction/map1/level.bmp","images/map/Introduction/map1/corresp.bmp","images/map/Introduction/map1/tileprop.txt",LARGEUR_TILE,HAUTEUR_TILE,tailleecranL, tailleecranl);
    screen = SDL_SetVideoMode(carte->largeur_fenetre,carte->hauteur_fenetre,32,SDL_HWSURFACE/*SDL_FULLSCREEN*/|SDL_DOUBLEBUF);
	
	centrage.x = 620;
	centrage.y = 412;
	centrage.w = 32;
	centrage.h = 32;
	
    perso.x = positionx[0];
	perso.y = positiony[0];
	perso.w = 32;
	perso.h = 32;
	limit.x = 200;
	limit.y = 150;
	limit.w = 400;
	limit.h = 300;
	
	while(x != 0 & *continuer2 != 0)
	{
        tempsActuel = SDL_GetTicks();
        
        if (tempsActuel - tempsPrecedent > 30)
        {	
            UpdateEvents(&in,&x, &continuer2, ecran);
       	    Evolue(&in,carte,&perso,LARGEUR_TILE,HAUTEUR_TILE, &variantenclip, &personnage);
            positionx[0] = perso.x;
            positiony[0] = perso.y;
            FocusScrollCenter(carte,&centrage);
		    FocusScrollBox(carte,&centrage,&limit);
            AfficherMap(carte,screen);
    		personnage.nclip = clipvarie = variantenclip;
	    	AfficherPerso(&perso,screen,carte->xscroll,carte->yscroll, clip , &personnage, imagePerso);
		    SDL_Flip(ecran);
		
		    if (perso.x > 660 & perso.x <704 & perso.y == 544 )
            {
                variablevent = 1;
        	    positionx[0] = 448;
             	positiony[0] = 825;
                *continuer2 = 2;
                x = 0;
            }
            
            while (x == 5)
            {
                ecranmenu(screen, &x, &continuer2);
            }

            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
	}
	
	SDL_FreeSurface (imagePerso);
	SDL_FreeSurface (screen);
	LibererMap(carte);
}
