#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_ttf.h"
#include "Event.h"
#include "variable.h"

void event1(SDL_Surface *ecran, int **continuer2)
{
    SDL_Surface *imageFond = NULL, *texte2 = NULL;
    SDL_Rect positionfond, positionTexte2;
    
    SDL_Event event;
    
    int x = 1, y = 0;
    
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 17);
    SDL_Color couleurBlanche = {255, 255, 255};
    
    imageFond = SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 200, 32, 0, 0, 0, 0);
    SDL_FillRect(imageFond, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_SetAlpha(imageFond, SDL_SRCALPHA, 190);
    
    positionfond.x = 0;
    positionfond.y = 400;
    SDL_BlitSurface(imageFond, NULL , ecran, &positionfond);
    
    while (x)
    { 
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                {
                    **continuer2 = 0;
                    x = 0;
                }
                
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                   case SDLK_RETURN:
                       y++;
                }
        }
        
        if (y == 0 & x != 0 )
        {
            texte2 = TTF_RenderText_Blended(police, "Faites attention !!", couleurBlanche);
            positionTexte2.x = 20;
            positionTexte2.y = 420;
            SDL_BlitSurface(texte2, NULL, ecran, &positionTexte2);
            SDL_FreeSurface(texte2);
            
            texte2 = TTF_RenderText_Blended(police, "Une goule attaque le village", couleurBlanche);
            positionTexte2.x = 20;
            positionTexte2.y = 435;
            SDL_BlitSurface(texte2, NULL, ecran, &positionTexte2);
            
            SDL_Flip(ecran);
            SDL_FreeSurface(texte2);
        }
        
        else if (y == 1 & x != 0)
        { 
            x = 0;
            variablevent = 2;
        }
        
    }
    
    SDL_FreeSurface(imageFond);
    TTF_CloseFont(police);
}
