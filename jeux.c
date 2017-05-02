#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "jeux.h"
#include "variable.h"

void jeux (SDL_Surface* ecran, int **continuer, int *x)
{
    SDL_Surface *imageSeparation = NULL, *texte = NULL;
    SDL_Rect positionSeparation, positionTexte;
    
    SDL_Event event;
    
    int lepoint = 0, y = 0;
    int tempsPrecedent = 0, tempsActuel = 0;
    
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 25);
    SDL_Color couleurBlanche = {255, 255, 255};
    
                pointdevie = 20 + constitution;
                mana = 5 + intelligence;
                    
                Precision = 20 + dexterite / 5;
                TauxDeCritique = 1 + dexterite / 10;
                AttPhyMin = 1 + force + arme[0].DegatMin;
                AttPhyMax = 5 + force + arme[0].DegatMax;
                AttMagMin = 1 + intelligence + arme[0].DegatMagMin;
                AttMagMax = 5 + intelligence + arme[0].DegatMagMax;
                DegMinCri = (force + dexterite) + arme[0].DegatMin;
                DegMaxCri = 5 + force + dexterite + arme[0].DegatMax;
                
                Blocage = 0;
                DefPhy = constitution + armure[0].DefPhy;
                DefMag = sagesse + armure[0].DefMag;
                Esquive = dexterite / 2;

    positionSeparation.x = tailleecranL * 25 / 100;
    positionSeparation.y = 0;
    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_Flip(ecran);
    
    imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 3, tailleecranl, 32, 0, 0, 0, 0);
    SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 50, 186, 255));
    SDL_BlitSurface(imageSeparation, NULL , ecran, &positionSeparation);
    SDL_FreeSurface(imageSeparation);

    texte = TTF_RenderText_Blended(police, "Inventaire", couleurBlanche);
    positionTexte.x = 30;
    positionTexte.y = 50;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Equipement", couleurBlanche);
    positionTexte.x = 30;
    positionTexte.y = 100;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Statut", couleurBlanche);
    positionTexte.x = 30;
    positionTexte.y = 150;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Magie", couleurBlanche);
    positionTexte.x = 30;
    positionTexte.y = 200;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Technique", couleurBlanche);
    positionTexte.x = 30;
    positionTexte.y = 250;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Expertise", couleurBlanche);
    positionTexte.x = 30;
    positionTexte.y = 300;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Nauratium", couleurBlanche);
    positionTexte.x = 30;
    positionTexte.y = 350;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Retour", couleurBlanche);
    positionTexte.x = 30;
    positionTexte.y = 400;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont (police);
    
    imageSeparation = IMG_Load("images/test.bmp");
    SDL_SetColorKey(imageSeparation, SDL_SRCCOLORKEY, SDL_MapRGB(imageSeparation->format, 224, 128, 64));
    positionSeparation.x = tailleecranL - 125;
    positionSeparation.y = 30;
    SDL_BlitSurface(imageSeparation, NULL , ecran, &positionSeparation);
    
    remplir_choix_perso(ecran);
    
    police = TTF_OpenFont("texte/times.ttf", 50);
    
    texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
    positionTexte.x = 10;
    positionTexte.y = 20 + lepoint;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    SDL_Flip (ecran);
    
    while (*x == 1 & **continuer != 0)
    { 
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);

        if (tempsActuel - tempsPrecedent > 30)	
        {
            switch(event.type)
            {
                case SDL_QUIT:
                {
                    **continuer = 0;
                    *x = 0;
                    break;
                }
                
                case SDL_KEYDOWN:
                     switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            lepoint -= 50;
                            break;
                        
                        case SDLK_DOWN:
                            lepoint += 50;
                            break;
                            
                        case SDLK_RETURN:  
                            y = 1;
                            break;
                            
                        case SDLK_i:  
                            *x = 0;
                            break;
                    }
                    break;
            }
            
            event.key.keysym.sym = 0;
            
            if (lepoint > 350)
                lepoint = 350; 

            if (lepoint < 0)
                lepoint = 0;
                
            texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, 450, 32, 0, 0,0, 0);
            SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            positionTexte.x = 0;
            positionTexte.y = 0;
            SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
            SDL_FreeSurface(texte);

            texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
            positionTexte.x = 10;
            positionTexte.y = 20 + lepoint;
            SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
            SDL_FreeSurface(texte);
            
            if (lepoint == 350 & y == 1)
                *x = 0;
                
            else if (lepoint == 0 & y == 1)
                *x = 2;
                
            else if (lepoint == 150 & y == 1)
                *x = 5;
                
            else if (lepoint == 300 & y == 1)
                *x = 8;
                
            else if (lepoint == 100 & y == 1)
                *x = 4;
                
            else if (lepoint == 250 & y == 1)
                *x = 7;
                
            else if (lepoint == 200 & y == 1)
                *x = 6;
                
                
            else if (lepoint == 50 & y == 1)
                *x = 3;
                
            SDL_Flip(ecran);
            y = 0;
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    SDL_FreeSurface(imageSeparation);
}
