#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_ttf.h"

int main (int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    
    srand(time(NULL));
    SDL_ShowCursor(SDL_DISABLE);
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE/*, SDL_FULLSCREEN*/);
    SDL_WM_SetCaption("Inlandsis", NULL);
    int continuer;
    
    demarage(ecran, &continuer);
    while (continuer != 0)
    {
        if (continuer < 99)
            switch (continuer)
            {       
                case 1:
                    map5(ecran, &continuer);
                    break;
                    
                case 2:
                    map2(ecran, &continuer);
                    break;
        
                case 3:
                    map3(ecran, &continuer);
                    break;
            
                case 4:
                    map4(ecran, &continuer);
                    break;
                    
                case 5:
                    map1(ecran, &continuer);
                    break;
                    
                case 6:
                    map6(ecran, &continuer);
                    break;
                    
                default:
                    break;
            }
            
        else if (continuer == 99)
            choixmenu(ecran, &continuer);
    }
    TTF_Quit;
    SDL_Quit;
    EXIT_SUCCESS;    
}
   
