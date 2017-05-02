#include "fmap.h"
#include "variable.h"

#define SGN(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))
#define ABS(X) ((((X)<0)?(-(X)):(X)))

int test, variablemvt, nbrmvt;
void RecupererVecteur3(Input* in,int* vx,int* vy, int* varianteclip2, int *Tcombat)
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
            *Tcombat = (rand() % (100)) + 1;
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
            *Tcombat = (rand() % (100)) + 1; 
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
            *Tcombat = (rand() % (100)) + 1;  
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
            *Tcombat = (rand() % (100)) + 1;
            testdepla ++;
            testvitesse = 0;
		    *varianteclip2 = 6 + testdepla;
		    if (*varianteclip2 > 8)
		        {*varianteclip2 = 6;
		        testdepla = 0;}
        }
        }
}

int EssaiDeplacement3(Map* carte,SDL_Rect* perso,int vx,int vy)
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

void Deplace3(Map* carte,SDL_Rect* perso,int vx,int vy,int LARGEUR_TILE,int HAUTEUR_TILE)
{
	int i;
	if (vx>=LARGEUR_TILE || vy>=HAUTEUR_TILE)
	{
		Deplace3(carte,perso,vx/2,vy/2,LARGEUR_TILE,HAUTEUR_TILE);
		Deplace3(carte,perso,vx-vx/2,vy-vy/2,LARGEUR_TILE,HAUTEUR_TILE);
		return;
	}
	if (EssaiDeplacement3(carte,perso,vx,vy)==1)
		return;
// affine
	for(i=0;i<ABS(vx);i++)
	{
		if (EssaiDeplacement3(carte,perso,SGN(vx),0)==0)
			break;
	}
	for(i=0;i<ABS(vy);i++)
	{
		if (EssaiDeplacement3(carte,perso,0,SGN(vy))==0)
			break;			
	}
}

void Evolue3(Input* in,Map* carte,SDL_Rect* perso,int LARGEUR_TILE,int HAUTEUR_TILE, int *variantenclip, AffObjet* personnage, int *Tcombat)
{
	int vx,vy, varianteclip2 = *variantenclip;
	int combataleatoire = 1;
	RecupererVecteur3(in,&vx,&vy, &varianteclip2, &combataleatoire);
	Deplace(carte,perso,vx,vy,LARGEUR_TILE,HAUTEUR_TILE);
	*variantenclip = varianteclip2;
	*Tcombat = combataleatoire;
}

void AfficherPerso3(SDL_Rect* perso,SDL_Surface* screen,int xscroll,int yscroll, SDL_Rect* clip, AffObjet* personnage,SDL_Surface* imagePerso)
{
	SDL_Rect positionsurecran = *perso;
	positionsurecran.x -= xscroll;
	positionsurecran.y -= yscroll;
	SDL_BlitSurface(imagePerso, clip + (personnage->nclip), screen, &positionsurecran);
}

void map3(SDL_Surface* ecran, int *continuer2)
{
	SDL_Rect limit, clip[ 16 ], pnj1, pnj2, perso;
	SDL_Surface *screen, *imagePerso = NULL;
	
	SDL_Event event;
	
	int variantenclip = clipvarie, testage, nombremob;
	int tempsPrecedent = 0, tempsActuel = 0;
	
	AffObjet personnage = {0};
	
	sprintf(zone, "La plaine");
    
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
    
	Map* carte3;
	Input in;
	int LARGEUR_TILE,HAUTEUR_TILE, Tcombat = 1, x = 1, levelMonstre;
	LARGEUR_TILE = 32;
	HAUTEUR_TILE = 32;
	memset(&in,0,sizeof(in));
	
	imagePerso = SDL_LoadBMP("images/chara/images.bmp");
	SDL_SetColorKey(imagePerso, SDL_SRCCOLORKEY, SDL_MapRGB(imagePerso->format, 255, 43, 64));

	carte3 = ChargerMap("images/map/Introduction/map3/tileset.bmp","images/map/Introduction/map3/level.bmp","images/map/Introduction/map3/corresp.bmp","images/map/Introduction/map3/tileprop.txt",LARGEUR_TILE,HAUTEUR_TILE,tailleecranL,tailleecranl);
	screen = SDL_SetVideoMode(carte3->largeur_fenetre,carte3->hauteur_fenetre,32,SDL_HWSURFACE/*SDL_FULLSCREEN*/|SDL_DOUBLEBUF);
	
	perso.x = positionx[0];
	perso.y = positiony[0];
    perso.w = 32;
	perso.h = 32;
	limit.x = 200;
	limit.y = 150;
	limit.w = 400;
	limit.h = 300;
	test = 0;
	variablemvt = 2;
	
    while(x != 0 & *continuer2 != 0)
    {
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > 30)
        {	 
		    UpdateEvents(&in, &x, &continuer2, ecran);
		    Evolue3(&in,carte3,&perso,LARGEUR_TILE,HAUTEUR_TILE, &variantenclip, &personnage, &Tcombat);
 	        positionx[0] = perso.x;
            positiony[0] = perso.y;
            FocusScrollCenter(carte3,&perso);
		    FocusScrollBox(carte3,&perso,&limit);
		    AfficherMap(carte3,screen);
		    personnage.nclip = clipvarie = variantenclip;
            AfficherPerso3(&perso,screen,carte3->xscroll,carte3->yscroll, clip , &personnage, imagePerso);
            SDL_Flip (screen);
        
	        if (perso.y < 5 & perso.x > 730 & perso.x < 2181)
            {
  	            positionx[0] = perso.x + 58 - 730;
     	        positiony[0] = 1565;
                *continuer2 = 2;
                x = 0;
            }
            
   	        if (perso.x < 0 & perso.y > 858 & perso.y < 896)
            {
  	            positionx[0] = 1154;
     	        positiony[0] = perso.y - 8;
                *continuer2 = 4;
                x = 0;
            }
   		     /*if (perso.y > 2 & variablevent == 2 & *continuer2 != 0)
	         {
                 combat(ecran, continuer2);
                 memset(&in,0,sizeof(in));
             }*/
        
             while (Tcombat > 98)
             {
                 levelMonstre = (rand() % (1) + 1);
                 if (niveau < 3)
                    nombreMonstre = (rand() % (2) + 1);
                 else
                    nombreMonstre = (rand() % (3) + 1);
                 combat(ecran, continuer2, levelMonstre);
                 memset(&in,0,sizeof(in));
                 Tcombat = 0;
             }
             
             while (x == 5)
             {
                 ecranmenu(ecran, &x, &continuer2);
             }
             tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
	}  
	

	SDL_FreeSurface (imagePerso);
}
