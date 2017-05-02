#include "fmap.h"
#include "variable.h"
#include "SDL/SDL_ttf.h"

#define SGN(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))
#define ABS(X) ((((X)<0)?(-(X)):(X)))

void RecupererVecteur5(Input* in,int* vx,int* vy, int* varianteclip2)
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

int EssaiDeplacement5(Map* carte,SDL_Rect* perso,int vx,int vy)
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

void Deplace5(Map* carte,SDL_Rect* perso,int vx,int vy,int LARGEUR_TILE,int HAUTEUR_TILE)
{
	int i;
	if (vx>=LARGEUR_TILE || vy>=HAUTEUR_TILE)
	{
		Deplace5(carte,perso,vx/2,vy/2,LARGEUR_TILE,HAUTEUR_TILE);
		Deplace5(carte,perso,vx-vx/2,vy-vy/2,LARGEUR_TILE,HAUTEUR_TILE);
		return;
	}
	if (EssaiDeplacement5(carte,perso,vx,vy)==1)
		return;
// affine
	for(i=0;i<ABS(vx);i++)
	{
		if (EssaiDeplacement5(carte,perso,SGN(vx),0)==0)
			break;
	}
	for(i=0;i<ABS(vy);i++)
	{
		if (EssaiDeplacement5(carte,perso,0,SGN(vy))==0)
			break;			
	}
}

void Evolue5(Input* in,Map* carte,SDL_Rect* perso,int LARGEUR_TILE,int HAUTEUR_TILE, int *variantenclip, AffObjet* personnage)
{
	int vx,vy, varianteclip2 = *variantenclip;
	RecupererVecteur5(in,&vx,&vy, &varianteclip2);
	Deplace5(carte,perso,vx,vy,LARGEUR_TILE,HAUTEUR_TILE);
	*variantenclip = varianteclip2;
}

void AfficherPerso5(SDL_Rect* perso,SDL_Surface* screen,int xscroll,int yscroll, SDL_Rect* clip, AffObjet* personnage,SDL_Surface* imagePerso)
{
	SDL_Rect positionsurecran = *perso;
	positionsurecran.x -= xscroll;
	positionsurecran.y -= yscroll;
	SDL_BlitSurface(imagePerso, clip + (personnage->nclip), screen, &positionsurecran);
}

void parleloic (SDL_Surface* ecran, int **continuer2)
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
    
    if (NumDeQuete[2].active == 1 & Resources[1].nombre > 4 & Resources[2].nombre > 0)
        NumDeQuete[2].active = 2;

    while (x != 0 & **continuer2 != 0 & NumDeQuete[1].active == 1 & NumDeQuete[2].active == 0)
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
                texte = TTF_RenderText_Blended(police, "Loic", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Glaof Keithy.", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "Glaof Loic.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
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
                texte = TTF_RenderText_Blended(police, "Loic", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Alors ton projet de devenir le nouveau Gardien, ça avance?", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Oui, justement je viens vous voir à ce sujet.", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "Loic", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Super, tu as besoin de mon aide?", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
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
                texte = TTF_RenderText_Blended(police, "Il y a un moine qui m'a demandé de venir vous réclamer un grimoire", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "Loic", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Hmmm... Desole mais j'en ai encore besoin pour creer ma hache!", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "He bien je pourrais peut-être vous aidez!", couleurBlanche);
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
                SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
                police = TTF_OpenFont("texte/cambria.ttc", 30);
                texte = TTF_RenderText_Blended(police, "Loic", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Si tu veux, comme ça je pourrais rendre le grimoire.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = TTF_RenderText_Blended(police, "Donc ce qu'il me faut c'est 5 canines de loups et 1 bois de cerf", couleurBlanche);
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
                SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
                police = TTF_OpenFont("texte/cambria.ttc", 30);
                texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Très bien, je vais allez en chercher!", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                y++;
                SDL_Flip(ecran);
            }
            
            else if (y == 20 & x != 0 )
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
                texte = TTF_RenderText_Blended(police, "La hache de Loïc", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 105;
                positionTexte.y = 100;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont (police);
    
                police = TTF_OpenFont("texte/cambria.ttc", 25);
                texte = TTF_RenderText_Blended(police, "Objectif : Recupérer 5 canines de loups & 1 bois de cerf", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 275;
                positionTexte.y = 225;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
    
                texte = TTF_RenderText_Blended(police, "Recompense : Grimoire du moine", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 140;
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
            
            else if (y == 22 & x != 0)
            { 
                NumDeQuete[2].active = 1;
                x = 0;
            }
            
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    
    while (x != 0 & **continuer2 != 0 & NumDeQuete[2].active == 1)
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
                texte = TTF_RenderText_Blended(police, "Loic", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Il t'en manque encore.", couleurBlanche);
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
    
    while (x != 0 & **continuer2 != 0 & NumDeQuete[2].active == 2)
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
                texte = TTF_RenderText_Blended(police, "Voila j'ai tout récupéré!", couleurBlanche);
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
                texte = TTF_RenderText_Blended(police, "Loic", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Fais voir...", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = TTF_RenderText_Blended(police, "Le compte est bon, tu es magnifique Keithy, merci beacoup.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 75;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                y++;
                SDL_Flip(ecran);
                TTF_CloseFont(police);
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
                texte = TTF_RenderText_Blended(police, "De rien Loic, ça m'a permit de m'entrainer.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                y++;
                SDL_Flip(ecran);
                TTF_CloseFont(police);
            }
            
            else if (y == 6 & x != 0 )
            {
                SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
                police = TTF_OpenFont("texte/cambria.ttc", 30);
                texte = TTF_RenderText_Blended(police, "Loic", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Haha, je suis sûr que tu deviendras un grand Gardien!", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = TTF_RenderText_Blended(police, "Tiens, tu peux  ramener le grimoire. Merci encore Keithy.", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 75;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                y++;
                SDL_Flip(ecran);
                TTF_CloseFont(police);
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
                texte = TTF_RenderText_Blended(police, "Au revoir!", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 50;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                y++;
                SDL_Flip(ecran);
                TTF_CloseFont(police);
            }
            
            else if (y == 10 & x != 0 )
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
                texte = TTF_RenderText_Blended(police, "La hache de Loïc", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 115;
                positionTexte.y = 100;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont (police);
                
                police = TTF_OpenFont("texte/cambria.ttc", 25);
                texte = TTF_RenderText_Blended(police, "Recompense : Grimoire du moine", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 170;
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
            
            else if (y == 12 & x != 0)
            { 
                NumDeQuete[2].active = 3;
                Resources[1].nombre -= 5;
                Resources[2].nombre -= 1;
                NumDeQuete[1].active = 2;
                x = 0;
            }
            
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    
    while (x != 0 & **continuer2 != 0 & (NumDeQuete[2].active == 3 || NumDeQuete[1].active == 0))
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
                texte = TTF_RenderText_Blended(police, "Loic", couleurBlanche);
                positionTexte.x = 10;
                positionTexte.y = tailleecranl - tailleecranl / 4 + 1;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police);
                    
                police = TTF_OpenFont("texte/cambria.ttc", 20);
                texte = TTF_RenderText_Blended(police, "Je suis occupé.", couleurBlanche);
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
    SDL_FreeSurface(imageFond);
}

int map5(SDL_Surface* ecran, int *continuer2)
{
	SDL_Rect limit, clip[ 12 ], perso, centrage, ecrantest, pLoic, perso2;
	SDL_Surface *screen = NULL, *imagePerso = NULL, *Loic = NULL;
	
    SDL_Event event;
	
	int variantenclip = clipvarie;
	int tempsPrecedent = 0, tempsActuel = 0;
	
	AffObjet personnage = {0};
	AffObjet pnj = {0};
    sprintf(zone, "Maison de Loic");
    
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
	
	Loic = SDL_LoadBMP("images/map/Introduction/map5/Loic.bmp");
	SDL_SetColorKey(Loic, SDL_SRCCOLORKEY, SDL_MapRGB(Loic->format, 133, 255, 76));
    	
	carte = ChargerMap("images/map/Introduction/map5/tileset.bmp","images/map/Introduction/map5/level.bmp","images/map/Introduction/map1/corresp.bmp","images/map/Introduction/map5/tileprop.txt",LARGEUR_TILE,HAUTEUR_TILE,tailleecranL, tailleecranl);
    screen = SDL_SetVideoMode(carte->largeur_fenetre,carte->hauteur_fenetre,32,SDL_HWSURFACE/*SDL_FULLSCREEN*/|SDL_DOUBLEBUF);
	
	centrage.x = 620;
	centrage.y = 412;
	centrage.w = 32;
	centrage.h = 32;
	
    perso.x = positionx[0];
	perso.y = positiony[0];
	perso.w = 32;
	perso.h = 32;
	
    pLoic.x = 605;
	pLoic.y = 408;
	pLoic.w = 32;
	pLoic.h = 32;
	
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
       	    Evolue5(&in,carte,&perso,LARGEUR_TILE,HAUTEUR_TILE, &variantenclip, &personnage);
            positionx[0] = perso.x;
            positiony[0] = perso.y;
            if (collisionPNJ(&perso, &pLoic)==0)
                perso = perso2;
            FocusScrollCenter(carte,&centrage);
		    FocusScrollBox(carte,&centrage,&limit);
            AfficherMap(carte,screen);
    		personnage.nclip = clipvarie = variantenclip;
    		AfficherPerso(&pLoic,screen,carte->xscroll,carte->yscroll, clip + 4, &pnj, Loic);
	    	AfficherPerso(&perso,screen,carte->xscroll,carte->yscroll, clip , &personnage, imagePerso);
		    SDL_Flip(screen);
                        
            if (perso.x >= 571 & perso.x <= 632 & perso.y == 544 )
            {
        	    positionx[0] = 1118;
             	positiony[0] = 832;
                *continuer2 = 2;
                x = 0;
            }
            while (x == 5)
             {
                 ecranmenu(screen, &x, &continuer2);
             }
             
            while (x == 4)
            {
                if (perso.x + 32 > pLoic.x - 2 & perso.x < pLoic.x + 34 & perso.y + 32 > pLoic.y - 8 & perso.y < pLoic.y + 34)
                {
                    parleloic (ecran, &continuer2);
                }
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
	SDL_FreeSurface (Loic);
	LibererMap(carte);
}
