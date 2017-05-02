#include "magie.h"
#include "variable.h"

void AfficheMagie1(SDL_Surface* ecran, int *continuer)
{    
    SDL_Surface *texte = NULL;
    SDL_Rect positionTexte;
    
    SDL_Event event;
    
    int tempsPrecedent = 0, tempsActuel = 0, valeur = 0;
    
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
    
    texte = TTF_RenderText_Blended(police, "Envoie des projectiles magique sur la cible,", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 235;
    positionTexte.y = tailleecranl - 200;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "lui infligeant ainsi des dégats.", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 163;
    positionTexte.y = tailleecranl - 145;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);

    police = TTF_OpenFont("texte/cambria.ttc", 20);    
    texte = TTF_RenderText_Blended(police, "Degats magique : 1-5", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 95;
    positionTexte.y = tailleecranl - 95;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Coût en mana : 3", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 75;
    positionTexte.y = tailleecranl - 65;
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
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
}



void AfficheMagie2(SDL_Surface* ecran, int *continuer)
{    
    SDL_Surface *texte = NULL;
    SDL_Rect positionTexte;
    
    SDL_Event event;
    
    int tempsPrecedent = 0, tempsActuel = 0, valeur = 0;
    
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
    
    texte = TTF_RenderText_Blended(police, "Envoie un projectiles enflammé sur la cible,", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 235;
    positionTexte.y = tailleecranl - 200;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "lui infligeant ainsi des dégats.", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 163;
    positionTexte.y = tailleecranl - 145;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);

    police = TTF_OpenFont("texte/cambria.ttc", 20);    
    texte = TTF_RenderText_Blended(police, "Degats de feu : 10-15", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 100;
    positionTexte.y = tailleecranl - 95;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Coût en mana : 7", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 75;
    positionTexte.y = tailleecranl - 65;
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
            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
}

