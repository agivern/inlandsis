#include "utils.h"
#include "variable.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

void UpdateEvents(Input* in, int *x, int **continuer2, SDL_Surface *ecran)
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		    case SDL_KEYDOWN:
		        in->key[event.key.keysym.sym]=1;
                switch (event.key.keysym.sym)
                {
                    case SDLK_i:
                         {in->key[event.key.keysym.sym]=0;
                         EmplacementMap = **continuer2;
                         **continuer2 = 99;
                         *x = 0;
                         break;}
                       
          		    case SDLK_ESCAPE :
                         {in->key[event.key.keysym.sym]=0;
                         EmplacementMap = **continuer2;
                         *x = 5;
                         break;}
                         
                    case SDLK_RETURN:
                         {in->key[event.key.keysym.sym]=0;
                         in->key[SDLK_w] = 0;
                         in->key[SDLK_s] = 0;
                         in->key[SDLK_a] = 0;
                         in->key[SDLK_d] = 0;
                         in->key[SDLK_UP] = 0;
                         in->key[SDLK_DOWN] = 0;
                         in->key[SDLK_LEFT] = 0;
                         in->key[SDLK_RIGHT] = 0;
                         *x = 4;
                         break;}
			    break;
                }
			    break;
			    

			    
		    case SDL_KEYUP:
			    in->key[event.key.keysym.sym]=0;
			    break;
			
           case SDL_QUIT:
               {**continuer2 = 0;
               *x = 0;}
               break;
		    default:
		 	   break;
        }
        
    }
}

SDL_Surface* LoadImage32(const char* fichier_image,int vram)
{
	SDL_Surface* image_result;
	SDL_Surface* image_ram = SDL_LoadBMP(fichier_image);	// charge l'image dans image_ram en RAM
	if (image_ram==NULL)
	{
		printf("Image %s introuvable !! \n",fichier_image);
		SDL_Quit();
		exit(-1);
	}
	
	image_result = NULL;
	if (vram)
		image_result=SDL_CreateRGBSurface(SDL_HWSURFACE, image_ram->w, image_ram->h, 32, 0, 0, 0, 0);  // cree une image en VRAM
	if (image_result==NULL)
		vram = 0;
	if (!vram)
		image_result=SDL_CreateRGBSurface(SDL_SWSURFACE, image_ram->w, image_ram->h, 32, 0, 0, 0, 0);  // cree une image en RAM
	SDL_BlitSurface(image_ram,NULL,image_result,NULL);	// copie l'image image_ram de moins de 32 bits vers image_result qui fait 32 bits
	SDL_FreeSurface(image_ram);      // supprime la surface image_ram : inutile maintenant --> libere la mémoire
	return image_result;
}

Uint32 GetPixel32(SDL_Surface* image,int i,int j)
{
	if (i<0 || i>image->w-1 || j<0 || j>image->h-1)
		return 0;
	return ((Uint32*)(image->pixels))[j*(image->pitch/4)+i];   // lecture directe des pixels
}

void ecranmenu(SDL_Surface *ecran, int *x, int **continuer)
{
    SDL_Surface *texte = NULL;
    SDL_Rect positionTexte;
    
    SDL_Event event;
    
    int lepoint = -10, y = 0;
    int tempsPrecedent = 0, tempsActuel = 0;
    
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 25);
    SDL_Color couleurBlanche = {255, 255, 255};
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL / 4 + 6, tailleecranl / 2 + 6, 32, 0, 0, 0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    positionTexte.x = ( tailleecranL - tailleecranL / 4 ) /2 - 3;
    positionTexte.y = (tailleecranl - tailleecranl / 2)/2 - 3;
    SDL_BlitSurface(texte, NULL , ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL / 4, tailleecranl / 2, 32, 0, 0, 0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    positionTexte.x = ( tailleecranL - tailleecranL / 4 ) /2;
    positionTexte.y = (tailleecranl - tailleecranl / 2)/2;
    SDL_BlitSurface(texte, NULL , ecran, &positionTexte);
    SDL_FreeSurface(texte);

    texte = TTF_RenderText_Blended(police, "Personnage", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 64;
    positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Option", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 36;
    positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + (tailleecranl/2 - 60)/3;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Sauvegarder", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 68;
    positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + 2 * (tailleecranl/2 - 60)/3;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Quitter", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 38;
    positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + (tailleecranl/2 - 60);
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont (police);

    police = TTF_OpenFont("texte/times.ttf", 50);
    texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
    positionTexte.x = tailleecranL / 2 + 64;
    positionTexte.y = tailleecranl / 2 - tailleecranl / 4 - 10;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 78;
    positionTexte.y = tailleecranl / 2 - tailleecranl / 4  - 10;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    SDL_Flip (ecran);

    
    while (*x == 5)
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
                        case SDLK_ESCAPE :
                             *x = 0;
                             break;
                             
                        case SDLK_UP:
                            lepoint -= 50;
                            break;
                        
                        case SDLK_DOWN:
                            lepoint += 50;
                            break;
                            
                        case SDLK_RETURN:  
                            y = 1;
                            break;
                    }
                    break;
            }
            
            event.key.keysym.sym = 0;
            
            if (lepoint > 140)
                lepoint = 140; 
                
            if (lepoint < -10)
                lepoint = -10;
        
            if (lepoint == -10)
            {
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 + 40;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + (tailleecranl/2 - 60)/3 - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 17, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 - 54;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + (tailleecranl/2 - 60)/3 - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 78;
                positionTexte.y = tailleecranl / 2 - tailleecranl / 4 - 10;;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
    
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 + 64;
                positionTexte.y = tailleecranl / 2 - tailleecranl / 4 - 10;;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            }
            
            else if (lepoint == 40)
            {
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 17, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 - 78;
                positionTexte.y = tailleecranl / 2 - tailleecranl / 4 ;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 + 64;
                positionTexte.y = tailleecranl / 2 - tailleecranl / 4 ;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 17, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 - 85;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + 2 * (tailleecranl/2 - 60)/3 - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 17, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 + 71;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + 2 * (tailleecranl/2 - 60)/3 - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 54;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + (tailleecranl/2 - 60)/3 - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
    
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 + 40;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + (tailleecranl/2 - 60)/3 - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            }
            
            else if (lepoint == 90)
            {
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 + 40;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + (tailleecranl/2 - 60)/3 - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 17, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 - 54;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + (tailleecranl/2 - 60)/3 - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 17, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 - 55;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + (tailleecranl/2 - 60) - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 + 41;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + (tailleecranl/2 - 60) - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 85;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + 2 * (tailleecranl/2 - 60)/3 - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
    
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 + 71;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + 2 * (tailleecranl/2 - 60)/3 - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            }
            
            else if (lepoint == 140)
            {
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 17, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 - 85;
                positionTexte.y = tailleecranl / 2 + tailleecranl / 8 - 75;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 + 71;
                positionTexte.y = tailleecranl / 2 + tailleecranl / 8 - 75;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 55;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + (tailleecranl/2 - 60) - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
    
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 + 41;
                positionTexte.y = (tailleecranl - tailleecranl / 2)/2 + 20 + (tailleecranl/2 - 60) - 30;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            }
    
            if (y == 1 & lepoint == 140)
            {
                **continuer = 0;
                *x = 0;
            }
            
            else if (y == 1 & lepoint == -10)
            {
                **continuer = 99;
                *x = 0;
            }
            
            else if (y == 1 & lepoint == 90)
            {
                sauvegarde();
                *x = 0;
            }
            
            SDL_Flip(ecran);
            y = 0;
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    TTF_CloseFont (police);
}

     
