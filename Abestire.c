#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#include "jeux.h"
#include "variable.h"

void abestire (SDL_Surface* ecran, int **continuer, int *x)
{   
    SDL_Surface *texte = NULL, *imageSeparation = NULL, *texte2 = NULL;
    SDL_Rect position, positionT;
    
    SDL_Event event;
    
    int tempsPrecedent = 0, tempsActuel = 0, letrait = 0, descendre = 0, retourvaleur = 0, laisserouvert = 1;
    char temps[40];
    
    TTF_Font *police = NULL; 
    police = TTF_OpenFont("texte/cambria.ttc", 20);
    SDL_Color couleurBlanche = {255, 255, 255};
    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_Flip (ecran);
    
    imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 32, 32, 32, 0, 0,0, 0);
    SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    
    if (niveau <= 10)
    {
        texte = TTF_RenderText_Blended(police, "1", couleurBlanche);
        position.x = 16;
        position.y = tailleecranl / 4 - 84;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        
        position.x = 5;
        position.y = tailleecranl / 2 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        texte = TTF_RenderText_Blended(police, "2", couleurBlanche);
        position.x = (tailleecranL - 37) / 9 + 11;
        position.y = tailleecranl / 4 - 84;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        
        position.x = (tailleecranL - 37) / 9;
        position.y = tailleecranl / 3 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = (tailleecranL - 37) / 9;
        position.y = 2 * tailleecranl / 3 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        texte = TTF_RenderText_Blended(police, "3", couleurBlanche);
        position.x = 2 * (tailleecranL - 37) / 9 + 11;
        position.y = tailleecranl / 4 - 84;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        
        position.x = 2 * (tailleecranL - 37) / 9;
        position.y = tailleecranl / 4 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 2 * (tailleecranL - 37) / 9;
        position.y = 2 * tailleecranl / 4- 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 2 * (tailleecranL - 37) / 9;
        position.y = 3 * tailleecranl / 4 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        texte = TTF_RenderText_Blended(police, "4", couleurBlanche);
        position.x = 3 * (tailleecranL - 37) / 9 + 11;
        position.y = tailleecranl / 4 - 84;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        
        position.x = 3 * (tailleecranL - 37) / 9;
        position.y = tailleecranl / 3 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 3 * (tailleecranL - 37) / 9;
        position.y = 2 * tailleecranl / 3 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        texte = TTF_RenderText_Blended(police, "5", couleurBlanche);
        position.x = 4 * (tailleecranL - 37) / 9 + 11;
        position.y = tailleecranl / 4 - 84;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        
        position.x = 4 * (tailleecranL - 37) / 9;
        position.y = tailleecranl / 4 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 4 * (tailleecranL - 37) / 9;
        position.y = 2 * tailleecranl / 4- 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 4 * (tailleecranL - 37) / 9;
        position.y = 3 * tailleecranl / 4 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        texte = TTF_RenderText_Blended(police, "6", couleurBlanche);
        position.x = 5 * (tailleecranL - 37) / 9 + 11;
        position.y = tailleecranl / 4 - 84;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        
        position.x = 5 * (tailleecranL - 37) / 9;
        position.y = tailleecranl / 3 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 5 * (tailleecranL - 37) / 9;
        position.y = 2 * tailleecranl / 3 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        texte = TTF_RenderText_Blended(police, "7", couleurBlanche);
        position.x = 6 * (tailleecranL - 37) / 9 + 11;
        position.y = tailleecranl / 4 - 84;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        
        position.x = 6 * (tailleecranL - 37) / 9;
        position.y = tailleecranl / 2 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        texte = TTF_RenderText_Blended(police, "8", couleurBlanche);
        position.x = 7 * (tailleecranL - 37) / 9 + 11;
        position.y = tailleecranl / 4 - 84;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        
        position.x = 7 * (tailleecranL - 37) / 9;
        position.y = tailleecranl / 3 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 7 * (tailleecranL - 37) / 9;
        position.y = 2 * tailleecranl / 3 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        texte = TTF_RenderText_Blended(police, "9", couleurBlanche);
        position.x = 8 * (tailleecranL - 37) / 9 + 11;
        position.y = tailleecranl / 4 - 84;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        
        position.x = 8 * (tailleecranL - 37) / 9;
        position.y = tailleecranl / 2 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        texte = TTF_RenderText_Blended(police, "10", couleurBlanche);
        position.x = tailleecranL - 33;
        position.y = tailleecranl / 4 - 84;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        
        position.x = tailleecranL - 37;
        position.y = tailleecranl / 4 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = tailleecranL - 37;
        position.y = 2 * tailleecranl / 4 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = tailleecranL - 37;
        position.y = 3 * tailleecranl / 4 - 16;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        SDL_FreeSurface(imageSeparation);



        
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 28, 28, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 178, 0, 255));
        
        position.x = 7;
        position.y = tailleecranl / 2 - 14;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        if ( abestirevariable[0] > 0)
        {
            position.x = (tailleecranL - 37) / 9 + 2;
            position.y = tailleecranl / 3 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[1] > 0)
        {
            position.x = (tailleecranL - 37) / 9 + 2;
            position.y = 2 * tailleecranl / 3 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[2] > 0)
        {
            position.x = 2 * (tailleecranL - 37) / 9 + 2;
            position.y = tailleecranl / 4 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[3] > 0)
        {
            position.x = 2 * (tailleecranL - 37) / 9 + 2;
            position.y = 2 * tailleecranl / 4- 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[4] > 0)
        {
            position.x = 2 * (tailleecranL - 37) / 9 + 2;
            position.y = 3 * tailleecranl / 4 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[5] > 0)
        {
            position.x = 3 * (tailleecranL - 37) / 9 + 2;
            position.y = tailleecranl / 3 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[6] > 0)
        {
            position.x = 3 * (tailleecranL - 37) / 9 + 2;
            position.y = 2 * tailleecranl / 3 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[7] > 0)
        {
            position.x = 4 * (tailleecranL - 37) / 9 + 2;
            position.y = tailleecranl / 4 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[8] > 0)
        {
            position.x = 4 * (tailleecranL - 37) / 9 + 2;
            position.y = 2 * tailleecranl / 4- 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[9] > 0)
        {
            position.x = 4 * (tailleecranL - 37) / 9 + 2;
            position.y = 3 * tailleecranl / 4 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[10] > 0)
        {
            position.x = 5 * (tailleecranL - 37) / 9 + 2;
            position.y = tailleecranl / 3 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[11] > 0)
        {
            position.x = 5 * (tailleecranL - 37) / 9 + 2;
            position.y = 2 * tailleecranl / 3 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[12] > 0)
        {
            position.x = 6 * (tailleecranL - 37) / 9 + 2;
            position.y = tailleecranl / 2 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[13] > 0)
        {
            position.x = 7 * (tailleecranL - 37) / 9 + 2;
            position.y = tailleecranl / 3 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[14] > 0)
        {
            position.x = 7 * (tailleecranL - 37) / 9 + 2;
            position.y = 2 * tailleecranl / 3 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[15] > 0)
        {
            position.x = 8 * (tailleecranL - 37) / 9 + 2;
            position.y = tailleecranl / 2 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[16] > 0)
        {
            position.x = tailleecranL - 37 + 2;
            position.y = tailleecranl / 4 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        if ( abestirevariable[17] > 0)
        {
            position.x = tailleecranL - 37 + 2;
            position.y = 2 * tailleecranl / 4 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable[18] > 0)
        {
            position.x = tailleecranL - 37 + 2;
            position.y = 3 * tailleecranl / 4 - 16 + 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        SDL_FreeSurface(imageSeparation);


        
        
        
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE,((tailleecranL - 37) / 9 - 32) / 2, 3, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        
        position.x = 35;
        position.y = tailleecranl / 2;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = (tailleecranL - 37) / 9 + 32;
        position.y = tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = (tailleecranL - 37) / 9 + 32;
        position.y = 2 * tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 2 * tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 2 * (tailleecranL - 37) / 9 + 32;
        position.y = tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 2 * (tailleecranL - 37) / 9 + 32;
        position.y = 2 * tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 2 * (tailleecranL - 37) / 9 + 32;
        position.y = 3 * tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 2 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 2 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2 - 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 2 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2 + 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 2 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 3 * tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 3 * (tailleecranL - 37) / 9 + 32;
        position.y = tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 3 * (tailleecranL - 37) / 9 + 32;
        position.y = 2 * tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 3 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 3 + 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 3 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 2 * tailleecranl / 3 - 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 3 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 3 - 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 3 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 2 * tailleecranl / 3 + 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 4 * (tailleecranL - 37) / 9 + 32;
        position.y = tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 4 * (tailleecranL - 37) / 9 + 32;
        position.y = 2 * tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 4 * (tailleecranL - 37) / 9 + 32;
        position.y = 3 * tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 4 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 4 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2 - 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 4 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2 + 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 4 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 3 * tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 5 * (tailleecranL - 37) / 9 + 32;
        position.y = tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 5 * (tailleecranL - 37) / 9 + 32;
        position.y = 2 * tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 5 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 3 + 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 5 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 2 * tailleecranl / 3 - 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 5 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 3 - 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 5 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 2 * tailleecranl / 3 + 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 6 * (tailleecranL - 37) / 9 + 32;
        position.y = tailleecranl / 2;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 6 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 7 * (tailleecranL - 37) / 9 + 32;
        position.y = tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 7 * (tailleecranL - 37) / 9 + 32;
        position.y = 2 * tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 7 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 7 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 2 * tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 8 * (tailleecranL - 37) / 9 + 32;
        position.y = tailleecranl / 2;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 8 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);

        position.x = tailleecranL - 37 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = tailleecranL - 37 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 2 * tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = tailleecranL - 37 - ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 3 * tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        SDL_FreeSurface(imageSeparation);
    
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, tailleecranl / 6 + 3, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        
        position.x = 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2 - tailleecranl / 6;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 5 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2 - tailleecranl / 6;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 5 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 6 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2 - tailleecranl / 6;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 6 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 7 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2 - tailleecranl / 6;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 7 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        SDL_FreeSurface(imageSeparation);
        
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, tailleecranl / 3 - tailleecranl / 4 + 3, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        
        position.x = (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 2 * tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 3 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 3 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 2 * tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        SDL_FreeSurface(imageSeparation);
        
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, tailleecranl / 4 + 3, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        
        position.x = 8 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2 - tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 8 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        SDL_FreeSurface(imageSeparation);
        
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, tailleecranl / 2 - tailleecranl / 3, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        
        position.x = (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 2 * tailleecranl / 4 + 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 2 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 3 + 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 2 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 3 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 3 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2 + 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 4 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 3 + 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 4 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 2;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        SDL_FreeSurface(imageSeparation);
        
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, tailleecranl / 3 - tailleecranl / 4, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        
        position.x = 2 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 2 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 2 * tailleecranl / 3 + 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        
        position.x = 4 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = tailleecranl / 4;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        position.x = 4 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
        position.y = 2 * tailleecranl / 3 + 3;
        SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        SDL_FreeSurface(imageSeparation);
        
        
        
        
        
        
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE,((tailleecranL - 37) / 9 - 32) / 2, 3, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 178, 0, 255));
        
        if (abestirevariable [0] == 1 || abestirevariable [1] == 1)
        {
            position.x = 35;
            position.y = tailleecranl / 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [2] == 1 || abestirevariable [3] == 1)
        {   position.x = (tailleecranL - 37) / 9 + 32;
            position.y = tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [3] == 2 || abestirevariable [4] == 1)
        {
            position.x = (tailleecranL - 37) / 9 + 32;
            position.y = 2 * tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [0] == 1)
        {
            position.x = (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [1] == 1)
        {
            position.x = (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 2 * tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [5] == 1)
        {
            position.x = 2 * (tailleecranL - 37) / 9 + 32;
            position.y = tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [5] == 2 || abestirevariable [6] == 2)
        {
            position.x = 2 * (tailleecranL - 37) / 9 + 32;
            position.y = 2 * tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [6] == 1)
        {
            position.x = 2 * (tailleecranL - 37) / 9 + 32;
            position.y = 3 * tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [2] == 1)
        {
            position.x = 2 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [3] == 1)
        {
            position.x = 2 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2 - 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [3] == 2)
        {
            position.x = 2 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2 + 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [4] == 1)
        {
            position.x = 2 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 3 * tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [7] == 1 || abestirevariable [8] == 1)
        {
            position.x = 3 * (tailleecranL - 37) / 9 + 32;
            position.y = tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [8] == 2 || abestirevariable [9] == 1)
        {
            position.x = 3 * (tailleecranL - 37) / 9 + 32;
            position.y = 2 * tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [5] == 2)
        {
            position.x = 3 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 3 + 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [6] == 2)
        {
            position.x = 3 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 2 * tailleecranl / 3 - 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [5] == 1)
        {
            position.x = 3 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 3 - 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [6] == 1)
        {
            position.x = 3 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 2 * tailleecranl / 3 + 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [10] == 1 )
        {
            position.x = 4 * (tailleecranL - 37) / 9 + 32;
            position.y = tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [10] == 2 || abestirevariable [11] == 2)
        {
            position.x = 4 * (tailleecranL - 37) / 9 + 32;
            position.y = 2 * tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [11] == 1 )
        {
            position.x = 4 * (tailleecranL - 37) / 9 + 32;
            position.y = 3 * tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [7] == 1 )
        {
            position.x = 4 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [8] == 1 )
        {
            position.x = 4 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2 - 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [8] == 2 )
        {
            position.x = 4 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2 + 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [9] == 1 )
        {
            position.x = 4 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 3 * tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
            
        if (abestirevariable [12] == 1 )
        {
            position.x = 5 * (tailleecranL - 37) / 9 + 32;
            position.y = tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [12] == 2 )
        {
            position.x = 5 * (tailleecranL - 37) / 9 + 32;
            position.y = 2 * tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [10] == 2)
        {
            position.x = 5 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 3 + 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [11] == 2)
        {
            position.x = 5 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 2 * tailleecranl / 3 - 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [10] == 1)
        {
            position.x = 5 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 3 - 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [11] == 1)
        {
            position.x = 5 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 2 * tailleecranl / 3 + 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [13] == 1 || abestirevariable [14] == 1 )
        {
            position.x = 6 * (tailleecranL - 37) / 9 + 32;
            position.y = tailleecranl / 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [12] > 0)
        {
            position.x = 6 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [15] == 1)
        {
            position.x = 7 * (tailleecranL - 37) / 9 + 32;
            position.y = tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [15] == 2)
        {
            position.x = 7 * (tailleecranL - 37) / 9 + 32;
            position.y = 2 * tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [13] == 1)
        {
            position.x = 7 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [14] == 1)
        {
            position.x = 7 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 2 * tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [16] == 1 || abestirevariable [17] == 1 || abestirevariable [18] == 1)
        {
            position.x = 8 * (tailleecranL - 37) / 9 + 32;
            position.y = tailleecranl / 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [15] > 0)
        {
            position.x = 8 * (tailleecranL - 37) / 9 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }

        if (abestirevariable [16] == 1)
        {
            position.x = tailleecranL - 37 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        if (abestirevariable [17] == 1)
        {
            position.x = tailleecranL - 37 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 2 * tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if (abestirevariable [18] == 1)
        {
            position.x = tailleecranL - 37 - ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 3 * tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        SDL_FreeSurface(imageSeparation);
    
    
    
    
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, tailleecranl / 6 + 3, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 178, 0, 255));
        
        if ( abestirevariable [0] == 1)
        {
            position.x = 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2 - tailleecranl / 6;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [1] == 1)
        {
            position.x = 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [12] == 1 & abestirevariable [10] > 0)
        {
            position.x = 5 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2 - tailleecranl / 6;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [12] > 0 & abestirevariable [11] > 0)
        {
            position.x = 5 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [13] == 1)
        {
            position.x = 6 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2 - tailleecranl / 6;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [14] == 1)
        {
            position.x = 6 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [15] == 1 & abestirevariable [13] > 0)
        {
            position.x = 7 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2 - tailleecranl / 6;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [15] > 0 & abestirevariable [14] > 0)
        {
            position.x = 7 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        SDL_FreeSurface(imageSeparation);
        
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, tailleecranl / 3 - tailleecranl / 4 + 3, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 178, 0, 255));
        
        if ( abestirevariable [2] == 1)
        {
            position.x = (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [4] == 1)
        {
            position.x = (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 2 * tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [7] == 1)
        {
            position.x = 3 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [9] == 1)
        {    
            position.x = 3 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 2 * tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        SDL_FreeSurface(imageSeparation);
        
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, tailleecranl / 4 + 3, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 178, 0, 255));
        
        if ( abestirevariable [16] == 1)
        {
            position.x = 8 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2 - tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [18] == 1)
        {
            position.x = 8 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        SDL_FreeSurface(imageSeparation);
        
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, tailleecranl / 2 - tailleecranl / 3, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 178, 0, 255));
        
        if ( abestirevariable [3] == 2)
        {
            position.x = (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 2 * tailleecranl / 4 + 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [3] == 1)
        {
            position.x = (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [5] == 2)
        {
            position.x = 2 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 3 + 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [6] == 2)
        {
            position.x = 2 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [8] == 1)
        {
            position.x = 3 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [8] == 2)
        {
            position.x = 3 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2 + 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [10]== 2)
        {
            position.x = 4 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 3 + 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [11] == 2)
        {
            position.x = 4 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 2;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        SDL_FreeSurface(imageSeparation);
        
        imageSeparation = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, tailleecranl / 3 - tailleecranl / 4, 32, 0, 0,0, 0);
        SDL_FillRect(imageSeparation, NULL, SDL_MapRGB(ecran->format, 178, 0, 255));
        
        if ( abestirevariable [5] == 1)
        {
            position.x = 2 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [6] == 1)
        {
            position.x = 2 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 2 * tailleecranl / 3 + 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        
        if ( abestirevariable [10] == 1)
        {
            position.x = 4 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = tailleecranl / 4;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
            SDL_FreeSurface(imageSeparation);
        }
        
        if ( abestirevariable [11] == 1)
        {
            position.x = 4 * (tailleecranL - 37) / 9 + 32 + ((tailleecranL - 37) / 9 - 32) / 2;
            position.y = 2 * tailleecranl / 3 + 3;
            SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
        }
        SDL_FreeSurface(imageSeparation);
        SDL_Flip (ecran);
        
        imageSeparation = IMG_Load("images/combat/curseur.bmp");
        SDL_SetColorKey(imageSeparation, SDL_SRCCOLORKEY, SDL_MapRGB(imageSeparation->format, 91, 255, 66));
        texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 32, 32, 32, 0, 0,0, 0);
        SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        
        sprintf(temps, "Niveau %d", niveau);
        texte2 = TTF_RenderText_Blended(police, temps, couleurBlanche);
        positionT.x = 5;
        positionT.y = 5;
        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
        SDL_FreeSurface(texte2);
        sprintf(temps, "points disponible %d", pointaatribuer);
        texte2 = TTF_RenderText_Blended(police, temps, couleurBlanche);
        positionT.x = tailleecranL - 175;
        positionT.y = 5;
        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
        SDL_FreeSurface(texte2);
        
        position.y = tailleecranl / 2 - 55;
        position.x = letrait;
        positionT.x = 5;
        positionT.y = tailleecranl - 25;
        
        do
        { 
            tempsActuel = SDL_GetTicks();
            SDL_PollEvent(&event);
            
            retourvaleur = 0;
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
                                retourvaleur = 1;
                                break;
                                
                            case SDLK_ESCAPE:
                                *x = 1;
                                break;
                                
                            case SDLK_RIGHT:
                                letrait += (tailleecranL - 37) / 9;
                                break;
                                
                            case SDLK_LEFT:
                                letrait -= (tailleecranL - 37) / 9;
                                break;
                                
                            case SDLK_UP:
                                descendre --;
                                break;
                                
                            case SDLK_DOWN:
                                descendre ++;
                                break;
                                
                        }break;
                }
                event.key.keysym.sym = 0;
                
                SDL_BlitSurface(texte, NULL , ecran, &position);
                
                if (descendre < 0)
                    descendre = 0;
                
                if (letrait > (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + 
                (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9)
                letrait = (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + 
                (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9;
                    
                else if (letrait < 5)
                    letrait = 5;
                    
                position.x = letrait;
                
                if (letrait == (tailleecranL - 37) / 9 + 5 || letrait == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 || letrait == (tailleecranL - 37) / 9 + 5 +
                (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9|| letrait == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + 
                (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9)
                {
                    if (descendre > 1)
                        descendre = 1;
                        
                    if (descendre == 0)
                        position.y = tailleecranl / 3 - 55;
                    else
                        position.y = 2 * tailleecranl / 3 - 55;
                }
                
                if (letrait == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 || letrait == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 || letrait == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + 
                (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9)
                {
                    if (descendre > 2)
                        descendre = 2;
                        
                    if (descendre == 0)
                        position.y = tailleecranl / 4 - 55;
                    else if (descendre == 1)
                        position.y = 2 * tailleecranl / 4 - 55;
                    else
                        position.y = 3 * tailleecranl / 4 - 55;
                }
                
                if (letrait == 5|| letrait == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9|| letrait == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + 
                (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9)
                {
                    descendre = 0;
                    position.y = tailleecranl / 2 - 55;
                }
                SDL_BlitSurface(imageSeparation, NULL , ecran, &position);
                SDL_Flip (ecran);







                if (retourvaleur & pointaatribuer > 0)
                {
                    if (niveau > 1 & position.x == (tailleecranL - 37) / 9 + 5 & position.y == tailleecranl / 3 - 55 &
                    abestirevariable[0] == 0 & abestirevariable[1] == 0)
                    {
                        abestirevariable[0] = 1;
                        intelligence += 5;
                        constitution += 5;
                        force += 5;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    else if (niveau > 1 & position.x == (tailleecranL - 37) / 9 + 5 & position.y == 2 * tailleecranl / 3 - 55 &
                    abestirevariable[0] == 0 & abestirevariable[1] == 0)
                    {
                        abestirevariable[1] = 1;
                        dexterite += 5;
                        constitution += 5;
                        force += 5;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 2 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 & position.y == tailleecranl / 4 - 55 &
                    abestirevariable[0] == 1 & abestirevariable[3] == 0 & abestirevariable[2] == 0)
                    {
                        abestirevariable[2] = 1;
                        intelligence += 5;
                        sagesse += 5;
                        magies[0].nombre = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 2 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 & position.y == 2 * tailleecranl / 4 - 55 &
                    abestirevariable[0] == 1 & abestirevariable[2] == 0 & abestirevariable[3] == 0)
                    {
                        abestirevariable[3] = 1;
                        force += 5;
                        constitution += 5;
                        techniques[0].nombre = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 2 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 & position.y == 2 * tailleecranl / 4 - 55 &
                    abestirevariable[1] == 1 & abestirevariable[2] == 0 & abestirevariable[3] == 0)
                    {
                        abestirevariable[3] = 2;
                        force += 5;
                        constitution += 5;
                        techniques[0].nombre = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 2 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 & position.y == 3 * tailleecranl / 4 - 55 &
                    abestirevariable[1] == 1 & abestirevariable[3] == 0 & abestirevariable[4] == 0)
                    {
                        abestirevariable[4] = 1;
                        dexterite += 5;
                        charisme += 5;
                        expertises[1].nombre = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 3 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == tailleecranl / 3 - 55 &
                    abestirevariable[2] == 1 & abestirevariable[5] == 0 & abestirevariable[6] == 0)
                    {
                        abestirevariable[5] = 1;
                        sagesse += 5;
                        constitution += 5;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 3 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == tailleecranl / 3 - 55 &
                    abestirevariable[3] > 0 & abestirevariable[5] == 0 & abestirevariable[6] == 0)
                    {
                        abestirevariable[5] = 2;
                        sagesse += 5;
                        constitution += 5;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 3 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == 2 * tailleecranl / 3 - 55 &
                    abestirevariable[4] == 1 & abestirevariable[5] == 0 & abestirevariable[6] == 0)
                    {
                        abestirevariable[6] = 1;
                        charisme += 5;
                        constitution += 5;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 3 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == 2 * tailleecranl / 3 - 55 &
                    abestirevariable[3] > 0 & abestirevariable[5] == 0 & abestirevariable[6] == 0)
                    {
                        abestirevariable[6] = 2;
                        charisme += 5;
                        constitution += 5;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 4 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == tailleecranl / 4 - 55 &
                    abestirevariable[5] > 0 & abestirevariable[7] == 0 & abestirevariable[8] == 0)
                    {
                        abestirevariable[7] = 1;
                        intelligence += 10;
                        expertises[2].nombre = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 4 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == 2 * tailleecranl / 4 - 55 &
                    abestirevariable[5] > 0 & abestirevariable[7] == 0 & abestirevariable[8] == 0)
                    {
                        abestirevariable[8] = 1;
                        force += 10;
                        expertises[2].nombre = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 4 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == 2 * tailleecranl / 4 - 55 &
                    abestirevariable[6] > 0 & abestirevariable[8] == 0 & abestirevariable[9] == 0)
                    {
                        abestirevariable[8] = 2;
                        force += 10;
                        expertises[2].nombre = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 4 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == 3 * tailleecranl / 4 - 55 &
                    abestirevariable[6] > 0 & abestirevariable[8] == 0 & abestirevariable[9] == 0)
                    {
                        abestirevariable[9] = 1;
                        dexterite += 10;
                        expertises[2].nombre = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 5 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == tailleecranl / 3 - 55 &
                    abestirevariable[7] == 1 & abestirevariable[10] == 0 & abestirevariable[11] == 0)
                    {
                        abestirevariable[10] = 1;
                        sagesse += 5;
                        constitution += 5;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 5 & position.x  == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == tailleecranl / 3 - 55 &
                    abestirevariable[8] > 0 & abestirevariable[10] == 0 & abestirevariable[11] == 0)
                    {
                        abestirevariable[10] = 2;
                        sagesse += 5;
                        constitution += 5;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 5 & position.x  == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == 2 * tailleecranl / 3 - 55 &
                    abestirevariable[9] == 1 & abestirevariable[10] == 0 & abestirevariable[11] == 0)
                    {
                        abestirevariable[11] = 1;
                        charisme += 5;
                        constitution += 5;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 5 & position.x  == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == 2 * tailleecranl / 3 - 55 &
                    abestirevariable[8] > 0 & abestirevariable[10] == 0 & abestirevariable[11] == 0)
                    {
                        abestirevariable[11] = 2;
                        charisme += 5;
                        constitution += 5;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 6 & position.x  == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == tailleecranl / 2 - 55 &
                    abestirevariable[10] > 0 & abestirevariable[12] == 0)
                    {
                        abestirevariable[12] = 1;
                        charisme += 5;
                        force += 5;
                        sagesse += 5;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 6 & position.x  == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == tailleecranl / 2 - 55 &
                    abestirevariable[11] > 0 & abestirevariable[12] == 0)
                    {
                        abestirevariable[12] = 2;
                        charisme += 5;
                        force += 5;
                        sagesse += 5;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 7 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9  + (tailleecranL - 37) / 9 & position.y == tailleecranl / 3 - 55 &
                    abestirevariable[12] > 0 & abestirevariable[13] == 0 & abestirevariable[14] == 0)
                    {
                        abestirevariable[13] = 1;
                        intelligence += 10;
                        force += 5;
                        sagesse += 5;
                        magies[1].nombre = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    else if (niveau > 7 & position.x == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == 2 * tailleecranl / 3 - 55 &
                    abestirevariable[12] > 0 & abestirevariable[13] == 0 & abestirevariable[14] == 0)
                    {
                        abestirevariable[14] = 1;
                        dexterite += 10;
                        force += 5;
                        charisme += 5;
                        techniques[1].nombre = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 8 & position.x  == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9  + (tailleecranL - 37) / 9  & position.y == tailleecranl / 2 - 55 &
                    abestirevariable[13] == 1 & abestirevariable[15] == 0)
                    {
                        abestirevariable[15] = 1;
                        constitution += 5;
                        expertises[3].nombre = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 8 & position.x  == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == tailleecranl / 2 - 55 &
                    abestirevariable[14] == 1 & abestirevariable[15] == 0)
                    {
                        abestirevariable[15] = 2;
                        constitution += 5;
                        expertises[3].nombre = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 9 & position.x  == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9  + (tailleecranL - 37) / 9  + (tailleecranL - 37) / 9 & position.y == tailleecranl / 4 - 55 &
                    abestirevariable[15] > 0 & abestirevariable[16] == 0 & abestirevariable[17] == 0 & abestirevariable[18] == 0)
                    {
                        abestirevariable[16] = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 9 & position.x  == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == 2 * tailleecranl / 4 - 55 &
                    abestirevariable[15] > 0 & abestirevariable[16] == 0 & abestirevariable[17] == 0 & abestirevariable[18] == 0)
                    {
                        abestirevariable[17] = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    
                    else if (niveau > 9 & position.x  == (tailleecranL - 37) / 9 + 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 & position.y == 3 * tailleecranl / 4 - 55 &
                    abestirevariable[15] > 0 & abestirevariable[16] == 0 & abestirevariable[17] == 0 & abestirevariable[18] == 0)
                    {
                        abestirevariable[18] = 1;
                        pointaatribuer --;
                        laisserouvert = 0;
                    }
                    retourvaleur = 0;
                }
                
                
                
                
                texte2 = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte2, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                SDL_FreeSurface(texte2);
                
                if (position.x == 5)
                {
                    SDL_FreeSurface(texte2);
                    texte2 = TTF_RenderText_Blended(police, "Apprenti", couleurBlanche);
                    SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                    SDL_FreeSurface(texte2);
                }
                
                else if (position.x == 5 + (tailleecranL - 37) / 9)
                {
                    if (descendre == 0)
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Intelligence +5          Constitution +5          Force +5", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                    
                    else
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Force +5          Constitution +5          Dextérité +5", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                }
                
                else if (position.x == 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9)
                {
                    if (descendre == 0)
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Intelligence +5          Sagesse +5          Nouveau sortilège", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                    
                    else if (descendre == 1)
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Force +5          Constitution +5          Nouvelle technique", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                    
                    else
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Dextérité +5          Charisme +5          Nouvelle expertise", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                }
                
                else if (position.x == 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9)
                {
                    if (descendre == 0)
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Sagesse +5          Constitution +5", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                    
                    else
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Charisme +5          Constitution +5", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                }
                
                else if (position.x == 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9)
                {
                    if (descendre == 0)
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Intelligence +10          Nouvelle expertise", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                    
                    else if (descendre == 1)
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Force +10          Nouvelle expertise", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                    
                    else
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Dextérité +10          Nouvelle expertise", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                }
                
                else if (position.x == 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9)
                {
                    if (descendre == 0)
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Sagesse +5          Constitution +5", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                    
                    else
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Charisme +5          Constitution +5", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                }
                
                else if (position.x == 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9)
                {
                    SDL_FreeSurface(texte2);
                    texte2 = TTF_RenderText_Blended(police, "Charisme +5          Constitution +5          Sagesse +5", couleurBlanche);
                    SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                    SDL_FreeSurface(texte2);
                }
                
                else if (position.x == 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + 
                (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9+ (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9)
                {
                    if (descendre == 0)
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Sagesse +5          Force +5          Intelligence +10          Nouveau sortilège", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                    
                    else
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Charisme +5          Force +5          Dextérité +10          Nouvelle technique", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                }
                
                else if (position.x == 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 +
                (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9+ (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9)
                {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Constitution +5          Nouvelle expertise", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);

                }
                
                else if (position.x == 5 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 +
                (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9+ (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9 + (tailleecranL - 37) / 9)
                {
                    if (descendre == 0)
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Apprenti magicien", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                    
                    else if (descendre == 1)
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Guerrier", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                    
                    else
                    {
                        SDL_FreeSurface(texte2);
                        texte2 = TTF_RenderText_Blended(police, "Aventurier", couleurBlanche);
                        SDL_BlitSurface(texte2, NULL, ecran, &positionT);
                        SDL_FreeSurface(texte2);
                    }
                }
                
                
                
                tempsPrecedent = tempsActuel;
            }
        
            else
            {
                SDL_Delay(30 - (tempsActuel - tempsPrecedent));
            }
        
        }while (*x == 8 & laisserouvert == 1);
    }
    TTF_CloseFont(police);
}
