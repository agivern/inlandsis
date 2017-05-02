#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#include "jeux.h"
#include "variable.h"

void equipement(SDL_Surface* ecran, int **continuer, int *x)
{   
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    
    SDL_Event event;
    char level[40] ={"0"};
    
    TTF_Font *police = NULL;
    SDL_Color couleurBlanche = {255, 255, 255};
    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    
    police = TTF_OpenFont("texte/cambria.ttc", 35);
    texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
    position.x = tailleecranL - tailleecranL / 2 - 50;
    position.y = 15;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = IMG_Load("images/test.bmp");
    SDL_SetColorKey(texte, SDL_SRCCOLORKEY, SDL_MapRGB(texte->format, 224, 128, 64));
    position.x = tailleecranL - tailleecranL / 2 - 52;
    position.y = 85;
    SDL_BlitSurface(texte, NULL , ecran, &position);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police); 
      
    police = TTF_OpenFont("texte/cambria.ttc", 17);
    texte = TTF_RenderText_Blended(police, "Niveau", couleurBlanche);
    position.x = tailleecranL - tailleecranL / 2 - 37;
    position.y = 50;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    sprintf(level, "%d", niveau);
    texte = TTF_RenderText_Blended(police, level, couleurBlanche);
    position.x = tailleecranL - tailleecranL / 2 +18;
    position.y = 50;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
    
    police = TTF_OpenFont("texte/cambria.ttc", 23);
    texte = TTF_RenderText_Blended(police, "Armes équipé", couleurBlanche);
    position.x = 50;
    position.y = 230;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Armures équipé", couleurBlanche);
    position.x = tailleecranL / 2 - 75;
    position.y = 230;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Bijoux équipé", couleurBlanche);
    position.x = tailleecranL - 190;;
    position.y = 230;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
    
    police = TTF_OpenFont("texte/cambria.ttc", 18);
    texte = TTF_RenderText_Blended(police, arme[0].nom, couleurBlanche);
    position.x = 50;
    position.y = 275;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, armure[0].nom, couleurBlanche);
    position.x = tailleecranL / 2 - 75;
    position.y = 275;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    SDL_Flip (ecran);
    
    do
    { 
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                **continuer = 0;
                *x = 0;
                break;
                
            case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_RETURN:
                            *x = 1;
                        break;
                    }break;
        }
        
    }while (*x == 3 & **continuer != 0 );
    
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
}
