#include "objet.h"
#include "variable.h"

void AffichePotion(SDL_Surface* ecran, int *continuer)
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
    
    texte = TTF_RenderText_Blended(police, "Contenant un liquide rouge, cette potion a la vertu de redonner de la vie.", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 400;
    positionTexte.y = tailleecranl - 250;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Ce phénomène reste inexpliqué à ce jour, et l'alchimiste qui l'a conçut est mort.", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 430;
    positionTexte.y = tailleecranl - 200;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Redonne 30 points de vie", couleurBlanche);
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
                Objets[0].nombre -= 1;
                pointdevierestant += 30;
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



void AfficheEnergisant(SDL_Surface* ecran, int *continuer)
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
    
    texte = TTF_RenderText_Blended(police, "Contenant un liquide bleu, cette potion a la vertu de redonner de l'energie.", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 400;
    positionTexte.y = tailleecranl - 250;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Ce phénomène reste inexpliqué à ce jour, et l'alchimiste qui l'a conçut est mort.", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 430;
    positionTexte.y = tailleecranl - 200;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Redonne 10 points de mana", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 140;
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
                Objets[2].nombre -= 1;
                manarestant += 10;
                if (manarestant > mana)
                    manarestant = mana;
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
