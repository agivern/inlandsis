#include "objet.h"

#include "jeux.h"
#include "variable.h"

void technique(SDL_Surface* ecran, int **continuer, int *x)
{   
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    
    SDL_Event event;
    
    char temps[40];
    int i, nombreobjet = 0, tempsActuel, tempsPrecedent, renvoievaleur;
              
    TTF_Font *police = NULL;    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_Flip(ecran);
    
    police = TTF_OpenFont("texte/cambria.ttc", 40);
    SDL_Color couleurBlanche = {255, 255, 255};
    
    texte = TTF_RenderText_Blended(police, "TECHNIQUE", couleurBlanche);
    position.x = tailleecranL / 2 - 100;
    position.y = 5;      
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police); 
    
    police = TTF_OpenFont("texte/cambria.ttc", 25);
    nombreobjet = i = 0;
    int lepoint = 53;
    
    position.x = 25;
    position.y = 75;
    
    for ( i = 0; i <= 24; i ++)
    {
        if (techniques[i].nombre == 1)
        {
            texte = TTF_RenderText_Blended(police, techniques[i].nom, couleurBlanche);
            SDL_BlitSurface(texte, NULL, ecran, &position);
            SDL_FreeSurface(texte);
            techniques[i].posi = position.y;
            position.y += 32;
            nombreobjet++;
        }
    } 
    
    if ( nombreobjet > 0)
    {
        texte = TTF_RenderText_Blended(police, "Retour", couleurBlanche);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        
        TTF_CloseFont(police); 
            
        police = TTF_OpenFont("texte/times.ttf", 40);
        texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
        position.x = 5;
        position.y = lepoint;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
            
        SDL_Flip(ecran);
            
        while (*x == 6)
        {
            tempsActuel = SDL_GetTicks();
            SDL_PollEvent(&event);
            renvoievaleur = 0;
            if (tempsActuel - tempsPrecedent > 30)     
            {
                switch(event.type)
                {
                    case SDL_QUIT:
                    {
                        **continuer = 0;
                        *x = 0;
                    }break;
                
  		            case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {
                            case SDLK_UP:
                                lepoint -= 32;
                                break;
                        
                            case SDLK_DOWN:
                                lepoint += 32;
                                break;
                            
                            case SDLK_RETURN:  
                                renvoievaleur = 2;
                                break;
                        
                        }break;
                }
            
                event.key.keysym.sym = 0;
                    
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, tailleecranl, 20, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                position.x = 0;
                position.y = 0;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
    
                if (lepoint > 32 * nombreobjet + 53)
                    lepoint = 32 * nombreobjet + 53; 
                
                if (lepoint < 53)
                    lepoint = 53;
                                  
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                position.x = 5;
                position.y = lepoint;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                SDL_Flip(ecran);
                    
                if (renvoievaleur == 2)
                {
                    if (lepoint == 32 * nombreobjet + 53)
                        *x = 1;
                        
                    else
                    {
                        for ( i = 0; i <= 24; i ++)
                        {
                            if (techniques[i].posi == lepoint - 25)
                            {
                                switch (i)
                                {
                                    case 0:
                                        AffichePotion(ecran, *continuer);
                                        *x = 1;
                                        break;
                                        
                                    case 1:
                                        break;
                                        
                                    case 2:
                                        AfficheEnergisant(ecran, *continuer);
                                        *x = 1;
                                        break;
                                        
                                    case 3:
                                        break;
                                        
                                    case 4:
                                        break;
                                        
                                    case 5:
                                        break;
                                        
                                    case 6:
                                        break;
                                        
                                    case 7:
                                        break;
                                        
                                    case 8:
                                        break;
                                        
                                    case 9:
                                        break;    
                                }
                            }
                        }
                    } 
                }
                renvoievaleur = 0;
                tempsPrecedent = tempsActuel;                      
            }   
            
            else
            {
                SDL_Delay(30 - (tempsActuel - tempsPrecedent));
            }
        }
    }
    
    else
    {  
        position.x = tailleecranL / 2 - 187;
        position.y = 75;
        texte = TTF_RenderText_Blended(police, "Vous n'avez pas appris de technique", couleurBlanche);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        TTF_CloseFont(police); 
        
        police = TTF_OpenFont("texte/cambria.ttc", 15);
        texte = TTF_RenderText_Blended(police, "Appuyez sur Entrer", couleurBlanche);
        position.x = tailleecranL - tailleecranL / 2 - 60;
        position.y = tailleecranl - 25;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        TTF_CloseFont(police); 
        SDL_Flip(ecran);
        
        while (*x == 6)
        {
            tempsActuel = SDL_GetTicks();
            SDL_PollEvent(&event);
            renvoievaleur = 0;
            if (tempsActuel - tempsPrecedent > 30)     
            {
                switch(event.type)
                {
                    case SDL_QUIT:
                    {
                        **continuer = 0;
                        *x = 0;
                    }break;
                
                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {
                            case SDLK_RETURN:  
                                renvoievaleur = 2;
                                break;
                        
                        }break;
                }
            
                event.key.keysym.sym = 0;
                    
                if (renvoievaleur == 2)
                    *x = 1;
                        
                tempsPrecedent = tempsActuel;                      
            }   
            
            else
            {
                SDL_Delay(30 - (tempsActuel - tempsPrecedent));
            }
        }
    }
}
