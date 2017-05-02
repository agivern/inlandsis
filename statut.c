#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#include "jeux.h"
#include "variable.h"

void statut (SDL_Surface* ecran, int **continuer, int *x)
{   
    SDL_Surface *texte = NULL, *imageSeparation = NULL;
    SDL_Rect position;
    
    SDL_Event event;
    
    int tempsPrecedent = 0, tempsActuel = 0;
    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_Flip (ecran);
    
    imageSeparation = IMG_Load("images/test.bmp");
    SDL_SetColorKey(imageSeparation, SDL_SRCCOLORKEY, SDL_MapRGB(imageSeparation->format, 224, 128, 64));
    position.x = tailleecranL - tailleecranL / 2 - 52;
    position.y = 85;
    SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
    SDL_FreeSurface(imageSeparation);
    
    remplir_statut (ecran);
    SDL_Flip (ecran);
   
    do
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
                        case SDLK_RETURN:
                            *x = 1;
                        break;
                    }break;
            }
            
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
        
    }while (*x == 4);

}

