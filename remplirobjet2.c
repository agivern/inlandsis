#include "objet.h"
#include "variable.h"

void AfficheHerbe(SDL_Surface* ecran, int *continuer)
{    
    SDL_Surface *texte = NULL;
    SDL_Rect positionTexte;
    
    SDL_Event event;
    
    int tempsPrecedent = 0, tempsActuel = 0, lepoint = 81, valeur = 0;
    
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 25);
    SDL_Color couleurBlanche = {255, 255, 255};
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL, tailleecranl, 32, 0, 0, 0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    positionTexte.x = 0;
    positionTexte.y = 0;
    SDL_BlitSurface(texte, NULL , ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL - 12, tailleecranl - 12, 32, 0, 0, 0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    positionTexte.x = 6;
    positionTexte.y = 6;
    SDL_BlitSurface(texte, NULL , ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "De l'herbe fraichement ceuillie, on dit qu'elle a des vertu medicinal", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 350;
    positionTexte.y = tailleecranl - 200;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Redonne 10 points de vie", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 125;
    positionTexte.y = tailleecranl - 150;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Utiliser", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 35;
    positionTexte.y = tailleecranl - 90;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Retour", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 33;
    positionTexte.y = tailleecranl - 50;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont (police);
    
    police = TTF_OpenFont("texte/times.ttf", 50);
    texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 52;
    positionTexte.y = tailleecranl - 40 - lepoint;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    SDL_Flip (ecran);
    
    while (*continuer != 0 & valeur == 0)
    { 
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);

        if (tempsActuel - tempsPrecedent > 30)	
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    *continuer = 0;
                    break;
                
                case SDL_KEYDOWN:
                     switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            lepoint += 40;
                            break;
                        
                        case SDLK_DOWN:
                            lepoint -= 40;
                            break;
                            
                        case SDLK_RETURN:  
                            valeur = 1;
                            break;
                    }
                    break;
            }
            
            event.key.keysym.sym = 0;
            
            if (lepoint < 41)
                lepoint = 41;
            else if ( lepoint > 81)
                lepoint = 81;
                
            texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, 100, 32, 0, 0,0, 0);
            SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            positionTexte.x = tailleecranL / 2 - 60;
            positionTexte.y = tailleecranl - 120;
            SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
            SDL_FreeSurface(texte);
        
            texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
            positionTexte.x = tailleecranL / 2 - 52;
            positionTexte.y = tailleecranl - 40 - lepoint;
            SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
            SDL_FreeSurface(texte);
                    
            if (valeur == 1 & lepoint == 81)
            {
                Resources[0].nombre -= 1;
                pointdevierestant += 10;
                if (pointdevierestant > pointdevie)
                    pointdevierestant = pointdevie;
            }
                    
            SDL_Flip(ecran);
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    TTF_CloseFont (police);
}



void Afficheboisdecerf(SDL_Surface* ecran, int *continuer)
{    
    SDL_Surface *texte = NULL;
    SDL_Rect positionTexte;
    
    SDL_Event event;
    
    int tempsPrecedent = 0, tempsActuel = 0, lepoint = 41, valeur = 0;
    
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 25);
    SDL_Color couleurBlanche = {255, 255, 255};
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL, tailleecranl, 32, 0, 0, 0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    positionTexte.x = 0;
    positionTexte.y = 0;
    SDL_BlitSurface(texte, NULL , ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL - 12, tailleecranl - 12, 32, 0, 0, 0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    positionTexte.x = 6;
    positionTexte.y = 6;
    SDL_BlitSurface(texte, NULL , ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Bois d'un cerf vigoureux, c'est un materiaux très resistant.", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 240;
    positionTexte.y = tailleecranl - 150;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Il semblerait que l'on puisse l'utiliser en artisanat.", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 250;
    positionTexte.y = tailleecranl - 100;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Retour", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 33;
    positionTexte.y = tailleecranl - 50;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont (police);
    
    police = TTF_OpenFont("texte/times.ttf", 50);
    texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 52;
    positionTexte.y = tailleecranl - 40 - lepoint;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    SDL_Flip (ecran);
    
    while (*continuer != 0 & valeur == 0)
    { 
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);

        if (tempsActuel - tempsPrecedent > 30)	
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    *continuer = 0;
                    break;
                
                case SDL_KEYDOWN:
                     switch (event.key.keysym.sym)
                    {
                        case SDLK_RETURN:  
                            valeur = 1;
                            break;
                    }
                    break;
            }
            
            event.key.keysym.sym = 0;
                   
            SDL_Flip(ecran);
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    TTF_CloseFont (police);
}

void Affichecrocdeloup(SDL_Surface* ecran, int *continuer)
{    
    SDL_Surface *texte = NULL;
    SDL_Rect positionTexte;
    
    SDL_Event event;
    
    int tempsPrecedent = 0, tempsActuel = 0, lepoint = 41, valeur = 0;
    
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 25);
    SDL_Color couleurBlanche = {255, 255, 255};
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL, tailleecranl, 32, 0, 0, 0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    positionTexte.x = 0;
    positionTexte.y = 0;
    SDL_BlitSurface(texte, NULL , ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL - 12, tailleecranl - 12, 32, 0, 0, 0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    positionTexte.x = 6;
    positionTexte.y = 6;
    SDL_BlitSurface(texte, NULL , ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Canine arraché d'un loup, elle est très resistante.", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 240;
    positionTexte.y = tailleecranl - 150;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Il semblerait que l'on puisse l'utiliser en artisanat.", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 250;
    positionTexte.y = tailleecranl - 100;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Retour", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 33;
    positionTexte.y = tailleecranl - 50;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont (police);
    
    police = TTF_OpenFont("texte/times.ttf", 50);
    texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 52;
    positionTexte.y = tailleecranl - 40 - lepoint;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    SDL_Flip (ecran);
    
    while (*continuer != 0 & valeur == 0)
    { 
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);

        if (tempsActuel - tempsPrecedent > 30)	
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    *continuer = 0;
                    break;
                
                case SDL_KEYDOWN:
                     switch (event.key.keysym.sym)
                    {
                        case SDLK_RETURN:  
                            valeur = 1;
                            break;
                    }
                    break;
            }
            
            event.key.keysym.sym = 0;
                   
            SDL_Flip(ecran);
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    TTF_CloseFont (police);
}

