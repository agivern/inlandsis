#include "combat.h"
#include "variable.h"

void utiliseobjet(SDL_Surface* ecran, int *choice, int *x, int *continuer, int *fairetantque)
{
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    
    SDL_Event event;
    
    TTF_Font *police3 = NULL;
    SDL_Color couleurBlanche = {255, 255, 255};
    
    char temps[25] = "";
    
    int i, nombreobjet = i = 0, letrait = 12, renvoievaleur = 0, tempsPrecedent = 0, tempsActuel = 0;
    police3 = TTF_OpenFont("texte/cambria.ttc", 18);
        
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL / 2, tailleecranL / 2 + 3, 32, 0, 0,0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    position.x = tailleecranL / 4;
    position.y = 0;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
            
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL / 2 - 6, tailleecranL / 2 - 3, 32, 0, 0,0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    position.x = tailleecranL / 4 + 3;
    position.y = 3;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
        
    texte = TTF_RenderText_Blended(police3, "Quel objet voulez-vous utiliser?", couleurBlanche);
    position.x = tailleecranL / 4 + 75;
    position.y = 7;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
        
    position.x = tailleecranL / 4 + 40;
    position.y = 37;
        
    for ( i = 0; i <= 9; i ++)
    {
        if (Objets[i].nombre)
        {
            sprintf(temps, "%s : %d", Objets[i].nom, Objets[i].nombre);
            texte = TTF_RenderText_Blended(police3, temps, couleurBlanche);
            SDL_BlitSurface(texte, NULL, ecran, &position);
            SDL_FreeSurface(texte);
            Objets[i].posi = position.y;
            position.y += 30;
            nombreobjet++;
        }
    } 

    if(nombreobjet > 0)
    {  
        TTF_CloseFont(police3); 
        police3 = TTF_OpenFont("texte/times.ttf", 40);
        texte = TTF_RenderText_Blended(police3, ".", couleurBlanche);
        position.x = tailleecranL / 4 + 20;
        position.y = letrait;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
            
        SDL_Flip(ecran);
        while (*choice == 4 & *x != 0)
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
                        *continuer = 0;
                        *x = 0;
                    }break;
                
  		            case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {
                            case SDLK_UP:
                                letrait -= 30;
                                break;
                        
                            case SDLK_DOWN:
                                letrait += 30;
                                break;
                            
                            case SDLK_RETURN:  
                                renvoievaleur = 2;
                                break;
                        
                            case SDLK_LEFT:
                                *choice = 0;
                                break;
                        }break;
                }
            
                event.key.keysym.sym = 0;
                    
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, tailleecranL / 2 - 3, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                position.x = tailleecranL / 4 + 10;
                position.y = 3;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
    
                if (letrait > 30 * nombreobjet - 18)
                    letrait = 30 * nombreobjet - 18; 
                
                if (letrait < 12)
                    letrait = 12;
                                  
                texte = TTF_RenderText_Blended(police3, ".", couleurBlanche);
                position.x = tailleecranL / 4 + 20;
                position.y = letrait;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                SDL_Flip(ecran);
                    
                if (renvoievaleur == 2)
                {
                    for ( i = 0; i <= 9; i ++)
                    {
                        if (Objets[i].posi == letrait + 25)
                        {
                            switch (i)
                            {
                                case 0:
                                    pointdevierestant += 30;
                                    if (pointdevierestant > pointdevie)
                                        pointdevierestant = pointdevie;
                                    Objets[0].nombre --;
                                    *fairetantque = 0;
                                    *choice = 0;
                                    break;
                                        
                                case 1:
                                    pointdevierestant += 100;
                                    if (pointdevierestant > pointdevie)
                                        pointdevierestant = pointdevie;
                                    Objets[1].nombre --;
                                    *fairetantque = 0;
                                    *choice = 0;
                                    break;
                                        
                                case 2:
                                    manarestant += 10;
                                    if (manarestant > mana)
                                        manarestant = mana;
                                    Objets[2].nombre --;
                                    *fairetantque = 0;
                                    *choice = 0;
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
                        
                renvoievaleur = 0;
                tempsPrecedent = tempsActuel;                      
            }   
            
            else
            {
                SDL_Delay(30 - (tempsActuel - tempsPrecedent));
            }
        }   
    }
    
    else if (nombreobjet == 0)
    {
        texte = TTF_RenderText_Blended(police3, "Vous n'avez aucun objet !", couleurBlanche);
        position.x = tailleecranL / 4 + 100;
        position.y = 37;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        TTF_CloseFont(police3);
            
        police3 = TTF_OpenFont("texte/times.ttf", 15);
        texte = TTF_RenderText_Blended(police3, "Appuyez sur entrer", couleurBlanche);
        position.x = tailleecranL / 2 - 60;
        position.y = tailleecranL / 2 - 20;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        SDL_Flip(ecran);
        while (*choice == 4 & *x != 0)
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
                            *continuer = 0;
                            *x = 0;
                        }break;
                
      		            case SDL_KEYDOWN:
                            switch (event.key.keysym.sym)
                            {
                                case SDLK_RETURN:  
                                    renvoievaleur = 2;
                                    break;
                                    
                                case SDLK_LEFT:  
                                    renvoievaleur = 2;
                                    break;
                                    
                            }break;
                    }
                    event.key.keysym.sym = 0;
                    
                    if (renvoievaleur == 2)
                        *choice = 0;
                        
                    tempsPrecedent = tempsActuel;                      
                }
            
                else
                {
                    SDL_Delay(30 - (tempsActuel - tempsPrecedent));
                }
            }
        }
        TTF_CloseFont (police3);
}
