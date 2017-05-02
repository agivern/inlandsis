#include "fmap.h"
#include "variable.h"
#include <SDL/SDL.h>
#include "SDL/SDL_ttf.h"

#define SGN(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))
#define ABS(X) ((((X)<0)?(-(X)):(X)))

void RecupererVecteur6(Input* in,int* vx,int* vy, int* varianteclip2)
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

int EssaiDeplacement6(Map* carte,SDL_Rect* perso,int vx,int vy)
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

void Deplace6(Map* carte,SDL_Rect* perso,int vx,int vy,int LARGEUR_TILE,int HAUTEUR_TILE)
{
	int i;
	if (vx>=LARGEUR_TILE || vy>=HAUTEUR_TILE)
	{
		Deplace6(carte,perso,vx/2,vy/2,LARGEUR_TILE,HAUTEUR_TILE);
		Deplace6(carte,perso,vx-vx/2,vy-vy/2,LARGEUR_TILE,HAUTEUR_TILE);
		return;
	}
	if (EssaiDeplacement6(carte,perso,vx,vy)==1)
		return;
// affine
	for(i=0;i<ABS(vx);i++)
	{
		if (EssaiDeplacement6(carte,perso,SGN(vx),0)==0)
			break;
	}
	for(i=0;i<ABS(vy);i++)
	{
		if (EssaiDeplacement6(carte,perso,0,SGN(vy))==0)
			break;			
	}
}

void Evolue6(Input* in,Map* carte,SDL_Rect* perso,int LARGEUR_TILE,int HAUTEUR_TILE, int *variantenclip, AffObjet* personnage)
{
	int vx,vy, varianteclip2 = *variantenclip;
	RecupererVecteur6(in,&vx,&vy, &varianteclip2);
	Deplace6(carte,perso,vx,vy,LARGEUR_TILE,HAUTEUR_TILE);
	*variantenclip = varianteclip2;
}

void AfficherPerso6(SDL_Rect* perso,SDL_Surface* screen,int xscroll,int yscroll, SDL_Rect* clip, AffObjet* personnage,SDL_Surface* imagePerso)
{
	SDL_Rect positionsurecran = *perso;
	positionsurecran.x -= xscroll;
	positionsurecran.y -= yscroll;
	SDL_BlitSurface(imagePerso, clip + (personnage->nclip), screen, &positionsurecran);
}

void Parlechef (SDL_Surface* ecran, int **continuer2)
{
    SDL_Surface *imageFond = NULL, *texte = NULL;
    SDL_Rect positionfond, positionTexte;
    
    SDL_Event event;
    
    int x = 1, y = 0;
   	int tempsPrecedent = 0, tempsActuel = 0;
    	
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 30);
    SDL_Color couleurBlanche = {255, 255, 255};
    SDL_Color couleurOrange = {255, 106, 0};
    
    imageFond = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL, 200, 32, 0, 0, 0, 0);
    SDL_FillRect(imageFond, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    
    positionfond.x = 0;
    positionfond.y = tailleecranl - tailleecranl / 4;
    SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
    
    while (x != 0 & **continuer2 != 0 & NumDeQuete[0].active == 0)
    { 
        tempsActuel = SDL_GetTicks();
        
        if (tempsActuel - tempsPrecedent > 30)	
        {
            SDL_PollEvent(&event);
            switch(event.type)
            {
                case SDL_QUIT:
                    **continuer2 = 0;
                    break;
                
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_RETURN:
                        y++;
                        event.key.keysym.sym = 0;
                    }
            }
            
            if (y == 0 & x != 0 )
            {
                texte = TTF_RenderText_Blended(police, "Chef du village", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Glaof Keithy, cela fesait longtemps que je ne t'avais pas vue.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, "Qu'est-ce qui me vaut ta visite?", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 70;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                y++;
                SDL_Flip(ecran);
                TTF_CloseFont(police);
            }
        
            else if (y == 2 & x != 0 )
            {
                SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
                police = TTF_OpenFont("texte/cambria.ttc", 30);
                texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Glaof Chef!", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, "Je viens vous voir car j'aimerais devenir le nouveau \"Gardien du Temple\".", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 70;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                y++;
                SDL_Flip(ecran);
            }
            
            else if (y == 4 & x != 0 )
            {
                SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
                police = TTF_OpenFont("texte/cambria.ttc", 30);
                texte = TTF_RenderText_Blended(police, "Chef du village", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Hmm, c'est une tâche très importante et même très difficile.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, "Tu ne dois pas la sous - estimé.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 75;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                y++;
                SDL_Flip(ecran);
            }
            
            else if (y == 6 & x != 0 )
            {
                SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
                police = TTF_OpenFont("texte/cambria.ttc", 30);
                texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Oui je le sais, mais mon choix est fait, je suis certaine de vouloir le devenir!", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, "Et je crois que c'est un acte que je dois réaliser afin de remercier Nilveîn.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 75;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                y++;
                SDL_Flip(ecran);
            }
            
            else if (y == 8 & x != 0 )
            {
                SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
                police = TTF_OpenFont("texte/cambria.ttc", 30);
                texte = TTF_RenderText_Blended(police, "Chef du village", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Grumph... Je vois, mais avant tout,", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = TTF_RenderText_Blended(police, "il va falloir que tu apprenne a en être plus proche.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 75;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                y++;
                SDL_Flip(ecran);
            }
            
            else if (y == 10 & x != 0 )
            {
                SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
                police = TTF_OpenFont("texte/cambria.ttc", 30);
                texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Mais comment ?!?", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                y++;
                SDL_Flip(ecran);
            }
            
            else if (y == 12 & x != 0 )
            {
                SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
                police = TTF_OpenFont("texte/cambria.ttc", 30);
                texte = TTF_RenderText_Blended(police, "Chef du village", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Il faut que tu aies foi en Elle, que tu fasses se qu'elle attend de toi!", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                y++;
                SDL_Flip(ecran);
            }
                
            else if (y == 14 & x != 0 )
            {
                SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
                police = TTF_OpenFont("texte/cambria.ttc", 30);
                texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Mais oui bien sur, merci grand chef, je vais allez au temple voir si je peux aidez.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = TTF_RenderText_Blended(police, "Elle sera fier de moi.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 75;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                y++;
                SDL_Flip(ecran);
            }
            
            else if (y == 16 & x != 0 )
            {
                SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
                police = TTF_OpenFont("texte/cambria.ttc", 30);
                texte = TTF_RenderText_Blended(police, "Chef du village", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Bonne chance Keithy.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = TTF_RenderText_Blended(police, "Reviens me voir quand tu penseras être prête pour devenir le \"Gardien du temple\"!", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 75;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                y++;
                SDL_Flip(ecran);
            }
            
            else if (y == 18 & x != 0 )
            {
                SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                
                police = TTF_OpenFont("texte/cambria.ttc", 50);
                texte = TTF_RenderText_Blended(police, "~QUETE ACTIVE~", couleurOrange);
                positionTexte.x = tailleecranL / 2 - 190;
                positionTexte.y = 20;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont (police);
    
                police = TTF_OpenFont("texte/cambria.ttc", 35);
                texte = TTF_RenderText_Blended(police, "Devenir le nouveau Gardien du temple", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 280;
                positionTexte.y = 100;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont (police);
    
                police = TTF_OpenFont("texte/cambria.ttc", 25);
                texte = TTF_RenderText_Blended(police, "Objectif : Obtenir 500 points de reputation pour Nilveïn", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 300;
                positionTexte.y = 225;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
    
                texte = TTF_RenderText_Blended(police, "Recompense : titre de \"Gardien du temple\"", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 225;
                positionTexte.y = 275;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
    
                police = TTF_OpenFont("texte/cambria.ttc", 15);
                texte = TTF_RenderText_Blended(police, "Appuyez sur Entrer", couleurBlanche);
                positionTexte.x = tailleecranL - tailleecranL / 2 - 60;
                positionTexte.y = tailleecranl - 25;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                y++;
                SDL_Flip(ecran);
            }
            
            else if (y == 20 & x != 0)
            { 
                NumDeQuete[0].active = 1;
                x = 0;
            }
            
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    
    while (x != 0 & **continuer2 != 0 & NumDeQuete[0].active == 1)
    { 
        tempsActuel = SDL_GetTicks();
        
        if (tempsActuel - tempsPrecedent > 30)	
        {
            SDL_PollEvent(&event);
            switch(event.type)
            {
                case SDL_QUIT:
                    **continuer2 = 0;
                    break;
                
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_RETURN:
                        y++;
                        event.key.keysym.sym = 0;
                    }
            }
            
            if (y == 0 & x != 0 )
            {
                texte = TTF_RenderText_Blended(police, "Chef du village", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Tu n'es pas encore prête.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, "Reviens me voir quand tu le sauras !", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 70;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                y++;
                SDL_Flip(ecran);
                TTF_CloseFont(police);
            }
            
            else if (y == 2 & x != 0)
            { 
                x = 0;          
            }
            
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    SDL_FreeSurface(imageFond);
}


int map6(SDL_Surface* ecran, int *continuer2)
{
	SDL_Rect limit, clip[ 12 ], perso, perso2, centrage, ecrantest, pchefvillage;
	SDL_Surface *screen = NULL, *imagePerso = NULL, *ChefVilage = NULL;
	
    SDL_Event event;
	
	int variantenclip = clipvarie;
	int tempsPrecedent = 0, tempsActuel = 0;
	
	AffObjet personnage = {0};
	AffObjet chefvillage = {0};
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
    	
    ChefVilage = SDL_LoadBMP("images/map/Introduction/map6/Chef-village.bmp");
	SDL_SetColorKey(ChefVilage, SDL_SRCCOLORKEY, SDL_MapRGB(ChefVilage->format, 72, 0, 255));
	
	carte = ChargerMap("images/map/Introduction/map6/tileset.bmp","images/map/Introduction/map6/level.bmp","images/map/Introduction/map6/corresp.bmp","images/map/Introduction/map6/tileprop.txt",LARGEUR_TILE,HAUTEUR_TILE,tailleecranL, tailleecranl);
    screen = SDL_SetVideoMode(carte->largeur_fenetre,carte->hauteur_fenetre,32,SDL_HWSURFACE/*SDL_FULLSCREEN*/|SDL_DOUBLEBUF);
	
	centrage.x = 645;
	centrage.y = 412;
	centrage.w = 32;
	centrage.h = 32;
	
    perso.x = positionx[0];
	perso.y = positiony[0];
	perso.w = 32;
	perso.h = 32;
	
    pchefvillage.x = 639;
	pchefvillage.y = 410;
	pchefvillage.w = 32;
	pchefvillage.h = 32;
	
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
            UpdateEvents(&in,&x, &continuer2, ecran);
       	    Evolue6(&in,carte,&perso,LARGEUR_TILE,HAUTEUR_TILE, &variantenclip, &personnage);
            positionx[0] = perso.x;
            positiony[0] = perso.y;
            if (collisionPNJ(&perso, &pchefvillage)==0)
                perso = perso2;
            FocusScrollCenter(carte,&centrage);
		    FocusScrollBox(carte,&centrage,&limit);
            AfficherMap(carte,screen);
    		personnage.nclip = clipvarie = variantenclip;
            AfficherPerso(&pchefvillage,screen,carte->xscroll,carte->yscroll, clip , &chefvillage, ChefVilage);
    		AfficherPerso(&perso,screen,carte->xscroll,carte->yscroll, clip , &personnage, imagePerso);
		    SDL_Flip(screen);
		
		    if (perso.x > 600 & perso.x <704 & perso.y >= 640 )
            {
        	    positionx[0] = 782;
             	positiony[0] = 330;
                *continuer2 = 2;
                x = 0;
            }
            
            while (x == 5)
             {
                 ecranmenu(ecran, &x, &continuer2);
             }
             
             while (x == 4)
             {
                 if (perso.x > 626 & perso.x <662 & perso.y >= 490 & perso.y < 495)
                     Parlechef (ecran, &continuer2);
                 x = 1;
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
