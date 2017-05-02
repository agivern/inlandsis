#include "combat.h"
#include "variable.h"


void boobooble_power2(SDL_Surface* ecran, struct Stat* monstre2, int mobselectionne, int degatmin, int degatmax)
{
    int x;
    int nombreMystere;

    nombreMystere = (rand() % (AttMagMax - AttPhyMin + degatmax - degatmin) + AttPhyMin + degatmin) + 1;
    afficheVie(ecran, 100);
    monstre2->pointdevierestant -= nombreMystere;
    if (monstre2->pointdevierestant < 0)
        monstre2->pointdevierestant = 0;
    evenementtouche(ecran, mobselectionne, nombreMystere);
    
    afficheVie(ecran, 0);
}



void attaquetechnique(SDL_Surface* ecran, int *x, int *continuer, int *fairetantque, int degatmin, int degatmax)
{
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    
    SDL_Event event;
    
    afficheVie (ecran, 100);
    SDL_Flip(ecran);
    TTF_Font *police2 = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    
    char temps[25] = "";
    int tempsPrecedent = 0, tempsActuel = 0, laisse = 1, letrait = 47, enhaut, renvoievaleur = 0, mobselectionne;
    police2 = TTF_OpenFont("texte/times.ttf", 23);
    
    while (laisse == 1 & *x != 0)
    {
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);
        
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
                            letrait -= 47;
                            enhaut = 1;
                            break;
                        
                        case SDLK_DOWN:
                            letrait += 47;
                            enhaut = 2;
                            break;
                            
                        case SDLK_LEFT:
                            *fairetantque = 0;
                            laisse =0;
                            break;
                            
                        case SDLK_RETURN:  
                            renvoievaleur = 1;
                            break;
                    }
                    break;
            }
            
            event.key.keysym.sym = 0;
            
            monstre1.tempsmob ++;
            if (nombreMonstre > 1)
                monstre2.tempsmob ++;
            if (nombreMonstre > 2)
                monstre3.tempsmob ++;
            
            afficheVie (ecran, 100); 
                        
            if (monstre1.tempsmob > 200 & monstre1.pointdevierestant > 0)
            {
                attaqueMob(ecran, 100, monstre1);
                monstre1.tempsmob = 0;
            }
            
            if (nombreMonstre > 1)
            {if (monstre2.tempsmob > 200 & monstre2.pointdevierestant > 0) 
            {
                attaqueMob(ecran, 100, monstre2);
                monstre2.tempsmob = 0;
            }}
            
            if (nombreMonstre > 2)
            {if (monstre3.tempsmob > 200 & monstre3.pointdevierestant > 0)
            {
                attaqueMob(ecran, 100, monstre3);
                monstre3.tempsmob = 0;
            }}
            
            if (letrait > 141)
                letrait = 141;
            else if (letrait < 47)
                letrait = 47;
                
            if (nombreMonstre == 1)
            {
                sprintf(temps, "%s", nomMonstre1);
                texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                position.x = 402;
                position.y = tailleecranL / 5 - 37;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                mobselectionne = 1;
                position.x = 365;
                position.y = tailleecranL / 5 - 37;
            }
            
            if (nombreMonstre == 2)
            {
                if (letrait <= 47)
                {
                    if (monstre1.pointdevierestant > 0)
                    {
                        sprintf(temps, "%s", nomMonstre1);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 402;
                        position.y = tailleecranL / 5 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 1;
                        position.x = 365;
                        position.y = tailleecranL / 5 - 37;
                    }
                    
                    else
                    {
                        sprintf(temps, "%s", nomMonstre2);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 252;
                        position.y = tailleecranL / 4 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 2;
                        position.x = 215;
                        position.y = tailleecranL / 4 - 37;
                        letrait = 94;
                    }
                }
                
                else if (letrait >= 94)
                {
                    if (monstre2.pointdevierestant > 0)
                    {
                        sprintf(temps, "%s", nomMonstre2);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 252;
                        position.y = tailleecranL / 4 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 2;
                        position.x = 215;
                        position.y = tailleecranL / 4 - 37;
                    }
                    
                    else
                    {
                        sprintf(temps, "%s", nomMonstre1);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 402;
                        position.y = tailleecranL / 5 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 1;
                        position.x = 365;
                        position.y = tailleecranL / 5 - 37;
                        letrait = 47;
                    }
                }
            }    
            
            if (nombreMonstre == 3)
            {
                if (letrait <= 47)
                {
                    if (monstre1.pointdevierestant > 0)
                    {
                        sprintf(temps, "%s", nomMonstre1);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 402;
                        position.y = tailleecranL / 5 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 1;
                        position.x = 365;
                        position.y = tailleecranL / 5 - 37;
                    }
                    
                    else if (monstre1.pointdevierestant <= 0 & monstre2.pointdevierestant > 0)
                    {
                        sprintf(temps, "%s", nomMonstre2);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 252;
                        position.y = tailleecranL / 4 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 2;
                        position.x = 215;
                        position.y = tailleecranL / 4 - 37;
                        letrait = 94;
                    }
                    
                    else
                    {
                        sprintf(temps, "%s", nomMonstre3);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 102;
                        position.y = tailleecranL / 3 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 3;
                        position.x = 65;
                        position.y = tailleecranL / 3 - 37;
                        letrait = 141;
                    }
                }
                
                else if (letrait == 94)
                {
                    if (monstre2.pointdevierestant > 0)
                    {
                        sprintf(temps, "%s", nomMonstre2);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 252;
                        position.y = tailleecranL / 4 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 2;
                        position.x = 215;
                        position.y = tailleecranL / 4 - 37;
                    }
                    
                    else if (monstre2.pointdevierestant <= 0 & enhaut == 2 & monstre3.pointdevierestant > 0)
                    {
                        sprintf(temps, "%s", nomMonstre3);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 102;
                        position.y = tailleecranL / 3 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 3;
                        position.x = 65;
                        position.y = tailleecranL / 3 - 37;
                        letrait = 141;
                    }
                    
                    else
                    {
                        sprintf(temps, "%s", nomMonstre1);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 402;
                        position.y = tailleecranL / 5 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 1;
                        position.x = 365;
                        position.y = tailleecranL / 5 - 37;
                        letrait = 47;
                    }
                }
                
                else if (letrait >= 141)
                {
                    if (monstre3.pointdevierestant > 0)
                    {
                        sprintf(temps, "%s", nomMonstre3);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 102;
                        position.y = tailleecranL / 3 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 3;
                        position.x = 65;
                        position.y = tailleecranL / 3 - 37;
                    }
                    
                    else if (monstre3.pointdevierestant <= 0 & monstre2.pointdevierestant > 0)
                    {
                        sprintf(temps, "%s", nomMonstre2);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 252;
                        position.y = tailleecranL / 4 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 2;
                        position.x = 215;
                        position.y = tailleecranL / 4 - 37;
                        letrait = 94;
                    }
                    
                    else if (monstre3.pointdevierestant <= 0 & monstre2.pointdevierestant <= 0)
                    {
                        sprintf(temps, "%s", nomMonstre1);
                        texte = TTF_RenderText_Blended(police2, temps, couleurNoire);
                        position.x = 402;
                        position.y = tailleecranL / 5 - 37;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        mobselectionne = 1;
                        position.x = 365;
                        position.y = tailleecranL / 5 - 37;
                        letrait = 47;
                    }
                }
            }
            
            if (renvoievaleur)
            {
                if (letrait == 47)
                    boobooble_power2(ecran, &monstre1, mobselectionne, degatmin, degatmax);
                if (letrait == 94)
                    boobooble_power2(ecran, &monstre2, mobselectionne, degatmin, degatmax);
                if (letrait == 141)
                    boobooble_power2(ecran, &monstre3, mobselectionne, degatmin, degatmax);
                *fairetantque = 2;
                laisse = 0;
            }
            
            texte = IMG_Load("images/combat/curseur3.bmp");
            SDL_SetColorKey(texte, SDL_SRCCOLORKEY, SDL_MapRGB(texte->format, 0, 255, 33));
            SDL_BlitSurface(texte, NULL, ecran, &position);
            SDL_FreeSurface(texte);
            
            SDL_Flip(ecran);
            tempsPrecedent = tempsActuel;                      
        }   
            
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
}









void utilisetechnique(SDL_Surface* ecran, int *choice, int *x, int *continuer, int *fairetantque)
{
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    
    SDL_Event event;
    
    TTF_Font *police3 = NULL;
    SDL_Color couleurBlanche = {255, 255, 255};
    
    char temps[25] = "";
    
    int i, nombreobjet = i = 0, letrait = 12, renvoievaleur = 0, tempsPrecedent = 0, tempsActuel = 0, maisse = 1;
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
        
    texte = TTF_RenderText_Blended(police3, "Quel techniques voulez-vous utiliser?", couleurBlanche);
    position.x = tailleecranL / 4 + 60;
    position.y = 7;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
        
    position.x = tailleecranL / 4 + 40;
    position.y = 37;
        
    for ( i = 0; i <= 9; i ++)
    {
        if (techniques[i].nombre)
        {
            sprintf(temps, "%s", techniques[i].nom);
            texte = TTF_RenderText_Blended(police3, temps, couleurBlanche);
            SDL_BlitSurface(texte, NULL, ecran, &position);
            SDL_FreeSurface(texte);
            techniques[i].posi = position.y;
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
        while (*choice == 3 & *x != 0 & maisse == 1)
        {
            tempsActuel = SDL_GetTicks();
            SDL_PollEvent(&event);
            renvoievaleur = 0;
                
            if (tempsActuel - tempsPrecedent > 30)     
            {
                switch(event.type)
                {
                    case SDL_QUIT:
                        *continuer = 0;
                        *x = 0;
                        break;
                
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
                        if (techniques[i].posi == letrait + 25)
                        {
                            switch (i)
                            {
                                case 0:
                                    attaquetechnique(ecran, x, continuer, &maisse, 3, 3);
                                    if (maisse == 2)
                                    {
                                        *choice = 0;
                                        *fairetantque = 0;
                                    }
                                    break;
                                        
                                case 1:
                                    attaquetechnique(ecran, x, continuer, &maisse, 3, 3);
                                    if (maisse == 2)
                                    {
                                        *choice = 0;
                                        *fairetantque = 0;
                                    }
                                    break;
                                        
                                case 2:
                                    attaquetechnique(ecran, x, continuer, &maisse, 3, 3);
                                    if (maisse == 2)
                                    {
                                        *choice = 0;
                                        *fairetantque = 0;
                                    }
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
        texte = TTF_RenderText_Blended(police3, "Vous n'avez aucune technique !", couleurBlanche);
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
        while (*choice == 3 & *x != 0)
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
