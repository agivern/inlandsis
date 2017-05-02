#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "variable.h"
#include <time.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

void choixmenu (SDL_Surface* ecran, int *continuer)
{
     int x = 1;
     
     while (x != 0 & *continuer != 0)
     {
           if (x == 1)
               jeux (ecran, &continuer, &x);
               
           else if (x == 2)
               objet (ecran, &continuer, &x);
               
           else if (x == 3)
               equipement (ecran, &continuer, &x);
               
           else if (x == 4)
               statut (ecran, &continuer, &x); 
               
           else if (x == 5)
               magie (ecran, &continuer, &x);
               
           else if (x == 6)
               technique (ecran, &continuer, &x);
               
           else if (x == 7)
               expertise (ecran, &continuer, &x);
               
           else if (x == 8)
               abestire (ecran, &continuer, &x);
     }
     
     if (*continuer != 0 )
         *continuer = EmplacementMap;
}
     
