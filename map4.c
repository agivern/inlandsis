#include "fmap.h"
#include "variable.h"
#include "SDL/SDL_ttf.h"

#define SGN(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))
#define ABS(X) ((((X)<0)?(-(X)):(X)))

void RecupererVecteur4(Input* in,int* vx,int* vy, int* varianteclip2)
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

int EssaiDeplacement4(Map* carte,SDL_Rect* perso,int vx,int vy)
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

void Deplace4(Map* carte,SDL_Rect* perso,int vx,int vy,int LARGEUR_TILE,int HAUTEUR_TILE)
{
	int i;
	if (vx>=LARGEUR_TILE || vy>=HAUTEUR_TILE)
	{
		Deplace4(carte,perso,vx/2,vy/2,LARGEUR_TILE,HAUTEUR_TILE);
		Deplace4(carte,perso,vx-vx/2,vy-vy/2,LARGEUR_TILE,HAUTEUR_TILE);
		return;
	}
	if (EssaiDeplacement4(carte,perso,vx,vy)==1)
		return;
		
	for(i=0;i<ABS(vx);i++)
	{
		if (EssaiDeplacement4(carte,perso,SGN(vx),0)==0)
			break;
	}
	for(i=0;i<ABS(vy);i++)
	{
		if (EssaiDeplacement4(carte,perso,0,SGN(vy))==0)
			break;			
	}
}

void Evolue4(Input* in,Map* carte,SDL_Rect* perso,int LARGEUR_TILE,int HAUTEUR_TILE, int *variantenclip, AffObjet* personnage)
{
	int vx,vy, varianteclip2 = *variantenclip;
	RecupererVecteur4(in,&vx,&vy, &varianteclip2);
	Deplace(carte,perso,vx,vy,LARGEUR_TILE,HAUTEUR_TILE);
	*variantenclip = varianteclip2;
}

void AfficherPerso4(SDL_Rect* perso,SDL_Surface* screen,int xscroll,int yscroll, SDL_Rect* clip, AffObjet* personnage,SDL_Surface* imagePerso)
{
	SDL_Rect positionsurecran = *perso;
	positionsurecran.x -= xscroll;
	positionsurecran.y -= yscroll;
	SDL_BlitSurface(imagePerso, clip + (personnage->nclip), screen, &positionsurecran);
}

void moine1 (SDL_Surface* ecran, int **continuer2)
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
    
    imageFond = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL, 400, 32, 0, 0, 0, 0);
    SDL_FillRect(imageFond, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    
    positionfond.x = 0;
    positionfond.y = tailleecranl - tailleecranl / 4;
    SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
    
    while (x != 0 & **continuer2 != 0 & NumDeQuete[1].active == 0 & NumDeQuete[0].active == 1)
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
                texte = TTF_RenderText_Blended(police, "Moine", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Glaof jeune fille.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
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
                texte = TTF_RenderText_Blended(police, "Glaof moine,", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, "Avez-vous un travail pour un futur Gardien du temple?", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "Moine", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Hahaha, Gardien dis-tu...", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, "He bien je ne sais trop...", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "Allez dite!", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                y++;
                SDL_Flip(ecran);
            }
            
            else if (y == 8 & x != 0 )
            {
                SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
                police = TTF_OpenFont("texte/cambria.ttc", 30);
                texte = TTF_RenderText_Blended(police, "Moine", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Il y aurait bien quelques chose, mais ce n'est vraiment pas grand chose.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = TTF_RenderText_Blended(police, "Loïc, le bucheron du village a emprunté un de mes grimmoires", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 75;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = TTF_RenderText_Blended(police, "Pourrais-tu allé le recupérer?", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 100;
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
                texte = TTF_RenderText_Blended(police, "Bien sûr, j'y vais de ce pas, je reviens vite!", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "Moine", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Merci, futur Gardien.", couleurBlanche);
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
                SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                
                police = TTF_OpenFont("texte/cambria.ttc", 50);
                texte = TTF_RenderText_Blended(police, "~QUETE ACTIVE~", couleurOrange);
                positionTexte.x = tailleecranL / 2 - 190;
                positionTexte.y = 20;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont (police);
    
                police = TTF_OpenFont("texte/cambria.ttc", 35);
                texte = TTF_RenderText_Blended(police, "Le grimoire du moine", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 150;
                positionTexte.y = 100;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont (police);
    
                police = TTF_OpenFont("texte/cambria.ttc", 25);
                texte = TTF_RenderText_Blended(police, "Objectif : Recupérer le grimmoire chez Loïc", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 215;
                positionTexte.y = 225;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
    
                texte = TTF_RenderText_Blended(police, "Recompense : ???", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 75;
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
            
            else if (y == 16 & x != 0)
            { 
                NumDeQuete[1].active = 1;
                x = 0;
            }
            
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    
    while (x != 0 & **continuer2 != 0 & NumDeQuete[1].active == 1)
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
                texte = TTF_RenderText_Blended(police, "Moine", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Tu as retrouvé le grimoire?", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
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
    
    while (x != 0 & **continuer2 != 0 & NumDeQuete[1].active == 2)
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
                texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Me revoila!", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
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
                texte = TTF_RenderText_Blended(police, "Moine", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Keithy, tu as été rapide dis donc.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, "Tu me ramènes mon grimoire?", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Oui, le voici.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
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
                texte = TTF_RenderText_Blended(police, "Moine", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Tu as fait du bon boulot à ce que je vois.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                texte = TTF_RenderText_Blended(police, "Mais je n'es rien a te remettre pour te remercier, je suis désolé.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 75;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                y++;
                SDL_Flip(ecran);
            }
            
            else if (y == 8 & x != 0 )
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
                texte = TTF_RenderText_Blended(police, "Ce n'est pas grave vous savez.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = TTF_RenderText_Blended(police, "Je n'ai nulment besoin de recompense!", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "Moine", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Hahaha, tu deviendra un grand Gardien, ça c'est sûr!", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Merci, je ne vous decevrait pas.", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "Moine", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Allez, va.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                y++;
                SDL_Flip(ecran);
            }
            
            else if (y == 16 & x != 0 )
            {
                 SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                
                police = TTF_OpenFont("texte/cambria.ttc", 50);
                texte = TTF_RenderText_Blended(police, "~QUETE TERMINE~", couleurOrange);
                positionTexte.x = tailleecranL / 2 - 210;
                positionTexte.y = 20;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont (police);
    
                police = TTF_OpenFont("texte/cambria.ttc", 35);
                texte = TTF_RenderText_Blended(police, "Le Grimoire du moine", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 150;
                positionTexte.y = 100;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont (police);
                
                police = TTF_OpenFont("texte/cambria.ttc", 25);
                texte = TTF_RenderText_Blended(police, "Recompense : 150 points de réputation de Nilveïn", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 275;
                positionTexte.y = 225;
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
            
            else if (y == 18 & x != 0)
            { 
                NumDeQuete[1].active = 3;
                Dieu[0].valeur += 150;
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

void map4(SDL_Surface* ecran, int *continuer2)
{
	SDL_Rect limit, clip[ 12 ], pnj1, perso, perso2;
	SDL_Surface *screen, *imagePerso = NULL, *imagePnj1 = NULL;
	
	SDL_Event event;
	
	int variantenclip = clipvarie, nombremob;
	int tempsPrecedent = 0, tempsActuel = 0;
	
	AffObjet personnage = {0};
	AffObjet monstre = {0};
	
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
    
	Map* carte4;
	Input in;
	int LARGEUR_TILE,HAUTEUR_TILE, x = 1;
	LARGEUR_TILE = 32;
	HAUTEUR_TILE = 32;
	memset(&in,0,sizeof(in));
	
	imagePerso = SDL_LoadBMP("images/chara/images.bmp");
	SDL_SetColorKey(imagePerso, SDL_SRCCOLORKEY, SDL_MapRGB(imagePerso->format, 255, 43, 64));
	
	imagePnj1 = SDL_LoadBMP("images/map/Introduction/map4/moines.bmp");
	SDL_SetColorKey(imagePnj1, SDL_SRCCOLORKEY, SDL_MapRGB(imagePnj1->format, 55, 255, 10));
	
	carte4 = ChargerMap("images/map/Introduction/map4/tileset.bmp","images/map/Introduction/map4/level.bmp","images/map/Introduction/map4/corresp.bmp","images/map/Introduction/map4/tileprop.txt",LARGEUR_TILE,HAUTEUR_TILE,tailleecranL,tailleecranl);
	screen = SDL_SetVideoMode(carte4->largeur_fenetre,carte4->hauteur_fenetre,32,SDL_HWSURFACE/*SDL_FULLSCREEN*/|SDL_DOUBLEBUF);
	
	perso.x = positionx[0];
	perso.y = positiony[0];
    perso.w = 32;
	perso.h = 32;
	
	pnj1.x = 895;
	pnj1.y = 390;
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
		    Evolue4(&in,carte4,&perso,LARGEUR_TILE,HAUTEUR_TILE, &variantenclip, &personnage);
 	        positionx[0] = perso.x;
            positiony[0] = perso.y;
            if (collisionPNJ(&perso, &pnj1)==0)
                perso = perso2;
            FocusScrollCenter(carte4,&perso);
		    FocusScrollBox(carte4,&perso,&limit);
		    AfficherMap(carte4,screen);
		    personnage.nclip = clipvarie = variantenclip;
		    AfficherPerso4(&pnj1,screen,carte4->xscroll,carte4->yscroll, clip +1, &monstre, imagePnj1);
            AfficherPerso4(&perso,screen,carte4->xscroll,carte4->yscroll, clip , &personnage, imagePerso);
            SDL_Flip (screen);
        
	        if (perso.y > 850 & perso.x >= 1156 & perso.y < 892)
            {
                positionx[0] = 1;
     	        positiony[0] = perso.y + 8;
                *continuer2 = 3;
                x = 0;
            }
        
             while (x == 5)
             {
                 ecranmenu(ecran, &x, &continuer2);
             }
             
             while (x == 4)
             {
                 if (perso.x + 32 > pnj1.x - 2 & perso.x < pnj1.x + 34 & perso.y + 32 > pnj1.y - 8 & perso.y < pnj1.y + 34)
                     moine1 (ecran, &continuer2);
                 x = 1;
             }
             tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
	}  
	
	LibererMap(carte4);
	SDL_FreeSurface (imagePerso);
	SDL_FreeSurface (imagePnj1);
	SDL_FreeSurface (screen);
}
