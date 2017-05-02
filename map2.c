#include "fmap.h"
#include "variable.h"

#define SGN(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))
#define ABS(X) ((((X)<0)?(-(X)):(X)))

void RecupererVecteur2(Input* in,int* vx,int* vy, int* varianteclip2)
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

int EssaiDeplacement2(Map* carte,SDL_Rect* perso,int vx,int vy)
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

void Deplace2(Map* carte,SDL_Rect* perso,int vx,int vy,int LARGEUR_TILE,int HAUTEUR_TILE)
{
	int i;
	if (vx>=LARGEUR_TILE || vy>=HAUTEUR_TILE)
	{
		Deplace2(carte,perso,vx/2,vy/2,LARGEUR_TILE,HAUTEUR_TILE);
		Deplace2(carte,perso,vx-vx/2,vy-vy/2,LARGEUR_TILE,HAUTEUR_TILE);
		return;
	}
	if (EssaiDeplacement2(carte,perso,vx,vy)==1)
		return;
// affine
	for(i=0;i<ABS(vx);i++)
	{
		if (EssaiDeplacement2(carte,perso,SGN(vx),0)==0)
			break;
	}
	for(i=0;i<ABS(vy);i++)
	{
		if (EssaiDeplacement2(carte,perso,0,SGN(vy))==0)
			break;			
	}
}

void Evolue2(Input* in,Map* carte,SDL_Rect* perso,int LARGEUR_TILE,int HAUTEUR_TILE, int *variantenclip, AffObjet* personnage)
{
	int vx,vy, varianteclip2 = *variantenclip;
	RecupererVecteur(in,&vx,&vy, &varianteclip2);
	Deplace(carte,perso,vx,vy,LARGEUR_TILE,HAUTEUR_TILE);
	*variantenclip = varianteclip2;
}

void AfficherPerso2(SDL_Rect* perso,SDL_Surface* ecran,int xscroll,int yscroll, SDL_Rect* clip, AffObjet* personnage,SDL_Surface* imagePerso)
{
	SDL_Rect positionsurecran = *perso;
	positionsurecran.x -= xscroll;
	positionsurecran.y -= yscroll;
	SDL_BlitSurface(imagePerso, clip + (personnage->nclip), ecran, &positionsurecran);
}

void map2(SDL_Surface* ecran, int *continuer2)
{
	SDL_Rect limit, clip[ 12 ], pnj1, perso, perso2, positionnuage;
	SDL_Surface *imagePerso = NULL, *imagePnj = NULL, *nuage2 = NULL;
	int positionnuagex, positionnuagey;
	SDL_Event event;
	
	int variantenclip = clipvarie;
	int tempsPrecedent = 0, tempsActuel = 0;
	
	AffObjet personnage = {0};
	AffObjet personnageNJ = {0};
	
	sprintf(zone, "Yolgan");
    
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
    
	Map* carte2;
	Input in;
	int LARGEUR_TILE,HAUTEUR_TILE, x = 1;
	LARGEUR_TILE = 32;
	HAUTEUR_TILE = 32;
	memset(&in,0,sizeof(in));
	
    nuage2 = SDL_LoadBMP("nuage.bmp");;
   	SDL_SetColorKey(nuage2, SDL_SRCCOLORKEY, SDL_MapRGB(nuage2->format, 255, 255, 255));
	SDL_SetAlpha(nuage2, SDL_SRCALPHA, 128);
	
	imagePerso = SDL_LoadBMP("images/chara/images.bmp");
	SDL_SetColorKey(imagePerso, SDL_SRCCOLORKEY, SDL_MapRGB(imagePerso->format, 255, 43, 64));
	
	imagePnj = SDL_LoadBMP("images/map/Introduction/map2/PNJ1.bmp");
	SDL_SetColorKey(imagePnj, SDL_SRCCOLORKEY, SDL_MapRGB(imagePnj->format, 255, 104, 104));

	carte2 = ChargerMap("images/map/Introduction/map2/tileset.bmp","images/map/Introduction/map2/level.bmp","images/map/Introduction/map2/corresp.bmp","images/map/Introduction/map2/tileprop.txt",LARGEUR_TILE,HAUTEUR_TILE,tailleecranL,tailleecranl);
	ecran = SDL_SetVideoMode(carte2->largeur_fenetre,carte2->hauteur_fenetre,32,SDL_HWSURFACE/*SDL_FULLSCREEN*/|SDL_DOUBLEBUF);
    
    positionnuage.x = positionx[1] + 500;
    positionnuage.y = positiony[1];
    
	perso.x = positionx[0];
	perso.y = positiony[0];
    perso.w = 32;
	perso.h = 32;
	
	pnj1.x = 352;
	pnj1.y = 697;
	pnj1.w = 32;
	pnj1.h = 32;
	
	limit.x = 200;
	limit.y = 150;
	limit.w = 400;
	limit.h = 300;
	
    while(x != 0 & *continuer2 != 0)
    {
        tempsActuel = SDL_GetTicks();
        
        if (tempsActuel - tempsPrecedent > 30)
        {	
            perso2 = perso;
		    UpdateEvents(&in, &x, &continuer2, ecran);
		    Evolue2(&in,carte2,&perso,LARGEUR_TILE,HAUTEUR_TILE, &variantenclip, &personnage);
   	        positionx[0] = perso.x;
            positiony[0] = perso.y;
            if (collisionPNJ(&perso, &pnj1)==0)
                perso = perso2;
            FocusScrollCenter(carte2,&perso);
		    FocusScrollBox(carte2,&perso,&limit);
		    AfficherMap(carte2,ecran);
		    personnage.nclip = clipvarie = variantenclip;
            AfficherPerso2(&pnj1,ecran,carte2->xscroll,carte2->yscroll, clip + 1, &personnageNJ, imagePnj);
            AfficherPerso2(&perso,ecran,carte2->xscroll,carte2->yscroll, clip , &personnage, imagePerso);
            
            
            positiony[1] = positiony[1] + 1;
            positionx[1] = positionx[1] + 1;
            if (positionx[1]>1100)
            {
                positionx[1] = -525;
                positiony[1] = -523;
            }
            positionnuage.x = positionx[1] - carte2->xscroll + 500;
            positionnuage.y = positiony[1] - carte2->yscroll;
            SDL_BlitSurface(nuage2, NULL, ecran, &positionnuage);
            
            positiony[2] = positiony[2] + 1;
            positionx[2] = positionx[2] + 1;
            if (positiony[2]>560)
            {   
                positionx[2] = -523;
                positiony[2] = -523;
            }
            positionnuage.x = positionx[2] - carte2->xscroll;
            positionnuage.y = positiony[2] - carte2->yscroll + 1000;
            SDL_BlitSurface(nuage2, NULL, ecran, &positionnuage);
            
            positiony[3] = positiony[3] + 1;
            positionx[3] = positionx[3] + 1;
            if (positionx[3]>2660)
            {   
                positionx[3] = -523;
                positiony[3] = -523;
            }
            positionnuage.x = positionx[3] - carte2->xscroll - 1000;
            positionnuage.y = positiony[3] - carte2->yscroll - 750;
            SDL_BlitSurface(nuage2, NULL, ecran, &positionnuage);
      
            SDL_Flip (ecran);
	        if (perso.x > 1088 & perso.x < 1152 & perso.y > 767 & perso.y < 801)
            {
                positionx[0] = 607;
      	        positiony[0] = 518;
                *continuer2 = 1;
                x = 0;
            }
             
   		    else if (perso.x > 416 & perso.x < 480 & perso.y > 767 & perso.y < 801)
	        {
    	        positionx[0] = 674;
         	    positiony[0] = 524;
                *continuer2 = 5;
                x = 0;
            }
            
   		    else if (perso.x > 760 & perso.x < 832 & perso.y > 310 & perso.y < 320)
	        {
    	        positionx[0] = 638;
         	    positiony[0] = 614;
                *continuer2 = 6;
                x = 0;
            }
            
   		    else if (perso.x > 58 & perso.x < 1509 & perso.y > 1567)
	        {
    	        positionx[0] = 730 + perso.x - 58;
         	    positiony[0] = 10;
                *continuer2 = 3;
                x = 0;
            }
            
            else if (x == 5)
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
	
	LibererMap(carte2);
	SDL_FreeSurface (imagePerso);
	SDL_FreeSurface (imagePnj);
	SDL_FreeSurface (nuage2);
}
