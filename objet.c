#include "objet.h"

#include "jeux.h"
#include "variable.h"

void objet(SDL_Surface* ecran, int **continuer, int *x)
{   
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    
    SDL_Event event;
    
    char temps[40];
    int i, nombreobjet = 0;
    int renvoievaleur, choice = 0, tempsPrecedent = 0, tempsActuel = 0, lepoints = 20, lepoint = 0, faire;
                
    TTF_Font *police = NULL, *police2 = NULL;
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_Flip(ecran);
    
    do
    {   
        faire = 1;
        
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_Flip(ecran);
        
        police = TTF_OpenFont("texte/cambria.ttc", 25);
        SDL_Color couleurBlanche = {255, 255, 255};
    
        texte = TTF_RenderText_Blended(police, "Objets", couleurBlanche);
        position.x = 25;
        position.y = 50;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
    
        texte = TTF_RenderText_Blended(police, "Ressources", couleurBlanche);
        position.x = 25;
        position.y = 100;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
    
        texte = TTF_RenderText_Blended(police, "Armes", couleurBlanche);
        position.x = 25;
        position.y = 150;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
    
        texte = TTF_RenderText_Blended(police, "Armures", couleurBlanche);
        position.x = 25;
        position.y = 200;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
    
        texte = TTF_RenderText_Blended(police, "Retour", couleurBlanche);
        position.x = 25;
        position.y = 250;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
    
        texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, tailleecranl, 32, 0, 0, 0, 0);
        SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        position.x = 175;
        position.y = 0;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        TTF_CloseFont(police);
    
        police = TTF_OpenFont("texte/times.ttf", 50);
    
        texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
        position.x = 5;
        position.y = lepoints;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
    
        SDL_Flip (ecran);
    
        while (choice == 0 & *x == 2 & faire == 1)
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
                                lepoints -= 50;
                                break;
                        
                            case SDLK_DOWN:
                                lepoints = lepoints + 50;
                                break;
                            
                            case SDLK_RETURN:  
                                renvoievaleur = 1;
                                break;
                        
                            case SDLK_RIGHT:
                                renvoievaleur = 1;
                                break;
                        }
                        break;
                }
                
                event.key.keysym.sym =0;
                
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, tailleecranl, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                position.x = 0;
                position.y = 0;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
    
                if (lepoints > 220)
                    lepoints = 220; 
                
                if (lepoints < 20)
                    lepoints = 20;
                                  
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                position.x = 5;
                position.y = lepoints;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                SDL_Flip(ecran);
            
                if (lepoints == 220 & renvoievaleur == 1)
                    *x = 1;
                
                else if (lepoints == 20 & renvoievaleur == 1)
                    choice = 1;
                    
                else if (lepoints == 70 & renvoievaleur == 1)
                    choice = 2;
                    
                else if (lepoints == 120 & renvoievaleur == 1)
                    choice = 3;
                    
                else if (lepoints == 170 & renvoievaleur == 1)
                    choice = 4;
                    
                renvoievaleur = 0;
                tempsPrecedent = tempsActuel;                      
            }   
            
            else
            {
                SDL_Delay(30 - (tempsActuel - tempsPrecedent));
            } 
        }
        
        

        while (choice == 1 & *x == 2 & faire == 1)
        {
            nombreobjet = i = 0;
            lepoint = 5;
            police2 = TTF_OpenFont("texte/cambria.ttc", 18);
            position.x = 210;
            position.y = 30;
            for ( i = 0; i <= 9; i ++)
            {
                if (Objets[i].nombre)
                {
                    sprintf(temps, "%s : %d", Objets[i].nom, Objets[i].nombre);
                    texte = TTF_RenderText_Blended(police2, temps, couleurBlanche);
                    SDL_BlitSurface(texte, NULL, ecran, &position);
                    SDL_FreeSurface(texte);
                    Objets[i].posi = position.y;
                    position.y += 30;
                    nombreobjet++;
                }
            } 
            
            TTF_CloseFont(police2); 
            
            if ( nombreobjet > 0)
            {
                police2 = TTF_OpenFont("texte/times.ttf", 40);
                texte = TTF_RenderText_Blended(police2, ".", couleurBlanche);
                position.x = 195;
                position.y = lepoint;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
            
                SDL_Flip(ecran);

                while (choice == 1 & *x == 2 & faire == 1)
                {
                    tempsActuel = SDL_GetTicks();
                    SDL_PollEvent(&event);
                    renvoievaleur = 0;
                    if (tempsActuel - tempsPrecedent > 30)     
                    {
                        switch(event.type)
                        {
                            case SDL_QUIT:
                                **continuer = 0;
                                *x = 0;
                                break;
                
      		                case SDL_KEYDOWN:
                                switch (event.key.keysym.sym)
                                {
                                    case SDLK_UP:
                                        lepoint -= 30;
                                        break;
                        
                                    case SDLK_DOWN:
                                        lepoint += 30;
                                        break;
                            
                                    case SDLK_RETURN:  
                                        renvoievaleur = 2;
                                        break;
                        
                                    case SDLK_LEFT:
                                        choice = 0;
                                        break;
                                }break;
                        }
            
                        event.key.keysym.sym = 0;
                        
                        texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, tailleecranl, 32, 0, 0,0, 0);
                        SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                        position.x = 185;
                        position.y = 0;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
    
                        if (lepoint > 30 * nombreobjet - 25)
                            lepoint = 30 * nombreobjet - 25; 
                    
                        if (lepoint < 5)
                            lepoint = 5;
                                  
                        texte = TTF_RenderText_Blended(police2, ".", couleurBlanche);
                        position.x = 195;
                        position.y = lepoint;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        SDL_Flip(ecran);
                    
                        if (renvoievaleur == 2)
                        {
                            for ( i = 0; i <= 9; i ++)
                            {
                                if (Objets[i].posi == lepoint + 25)
                                {
                                    switch (i)
                                    {
                                        case 0:
                                            AffichePotion(ecran, *continuer);
                                            faire = 0;
                                            break;
                                        
                                        case 1:
                                            break;
                                        
                                        case 2:
                                            AfficheEnergisant(ecran, *continuer);
                                            faire = 0;
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
                police2 = TTF_OpenFont("texte/times.ttf", 25);
                texte = TTF_RenderText_Blended(police2, "Vous n'avez aucun objet !", couleurBlanche);
                position.x = (tailleecranL + 175)/ 2 - 125;
                position.y = 10;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police2);
            
                police2 = TTF_OpenFont("texte/times.ttf", 15);
                texte = TTF_RenderText_Blended(police2, "Appuyez sur entrer", couleurBlanche);
                position.x = (tailleecranL + 175)/ 2 - 60;
                position.y = tailleecranl - 20;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                SDL_Flip(ecran);
                TTF_CloseFont(police2);
                
                while (choice == 1 & *x != 0)
                {
                    tempsActuel = SDL_GetTicks();
                    SDL_PollEvent(&event);
                    renvoievaleur = 0;
                
                    if (tempsActuel - tempsPrecedent > 30)     
                    {
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
                                        renvoievaleur = 2;
                                        break;
                                    
                                    case SDLK_LEFT:  
                                        renvoievaleur = 2;
                                        break;
                                }break;
                        }
                        event.key.keysym.sym = 0;
                    
                        if (renvoievaleur == 2)
                            choice = 0;
                        
                        tempsPrecedent = tempsActuel;                      
                    }
            
                    else
                    {
                        SDL_Delay(30 - (tempsActuel - tempsPrecedent));
                    }
                }
            }
        }
        
        while (choice == 2 & *x == 2 & faire == 1)
        {
            nombreobjet = i = 0;
            lepoint = 5;
            police2 = TTF_OpenFont("texte/cambria.ttc", 18);
            position.x = 210;
            position.y = 30;
            for ( i = 0; i <= 9; i ++)
            {
                if (Resources[i].nombre)
                {
                    sprintf(temps, "%s : %d", Resources[i].nom, Resources[i].nombre);
                    texte = TTF_RenderText_Blended(police2, temps, couleurBlanche);
                    SDL_BlitSurface(texte, NULL, ecran, &position);
                    SDL_FreeSurface(texte);
                    Resources[i].posi = position.y;
                    position.y += 30;
                    nombreobjet++;
                }
            } 
            TTF_CloseFont(police2);
            
            if (nombreobjet > 0)
            {
                police2 = TTF_OpenFont("texte/times.ttf", 40);
                texte = TTF_RenderText_Blended(police2, ".", couleurBlanche);
                position.x = 195;
                position.y = lepoint;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                SDL_Flip(ecran);
            
                while (choice == 2 & *x == 2 & faire == 1)
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
                                        lepoint -= 30;
                                        break;
                        
                                    case SDLK_DOWN:
                                        lepoint += 30;
                                        break;
                            
                                    case SDLK_RETURN:  
                                        renvoievaleur = 2;
                                        break;
                            
                                    case SDLK_LEFT:
                                        choice = 0;
                                        break;
                                }break;
                        }
            
                        event.key.keysym.sym = 0;
                    
                        texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, tailleecranl, 32, 0, 0,0, 0);
                        SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                        position.x = 185;
                        position.y = 0;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
    
                        if (lepoint > 30 * nombreobjet - 25)
                            lepoint = 30 * nombreobjet - 25; 
                
                        if (lepoint < 5)
                            lepoint = 5;
                                  
                        texte = TTF_RenderText_Blended(police2, ".", couleurBlanche);
                        position.x = 195;
                        position.y = lepoint;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        SDL_Flip(ecran);
                        
                        if (renvoievaleur == 2)
                        {
                            for ( i = 0; i <= 9; i ++)
                            {
                                if (Resources[i].posi == lepoint + 25)
                                {
                                    switch (i)
                                    {
                                        case 0:
                                            AfficheHerbe(ecran, *continuer);
                                            faire = 0;
                                            break;
                                        
                                        case 1:
                                            Affichecrocdeloup(ecran, *continuer);
                                            faire = 0;
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
                police2 = TTF_OpenFont("texte/times.ttf", 25);
                texte = TTF_RenderText_Blended(police2, "Vous n'avez aucune ressource !", couleurBlanche);
                position.x = (tailleecranL + 175)/ 2 - 135;
                position.y = 10;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police2);
            
                police2 = TTF_OpenFont("texte/times.ttf", 15);
                texte = TTF_RenderText_Blended(police2, "Appuyez sur entrer", couleurBlanche);
                position.x = (tailleecranL + 175)/ 2 - 60;
                position.y = tailleecranl - 20;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                SDL_Flip(ecran);
                TTF_CloseFont(police2);
                
                while (choice == 2 & *x != 0)
                {
                    tempsActuel = SDL_GetTicks();
                    SDL_PollEvent(&event);
                    renvoievaleur = 0;
                
                    if (tempsActuel - tempsPrecedent > 30)     
                    {
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
                                        renvoievaleur = 2;
                                        break;
                                    
                                    case SDLK_LEFT:  
                                        renvoievaleur = 2;
                                        break;
                                }break;
                        }
                        event.key.keysym.sym = 0;
                    
                        if (renvoievaleur == 2)
                            choice = 0;
                        
                        tempsPrecedent = tempsActuel;                      
                    }
            
                    else
                    {
                        SDL_Delay(30 - (tempsActuel - tempsPrecedent));
                    }
                }
            }
        }
        
        while (choice == 3 & *x == 2 & faire == 1)
        {
            nombreobjet = i = 0;
            lepoint = 5;
            police2 = TTF_OpenFont("texte/cambria.ttc", 18);
            position.x = 210;
            position.y = 30;
            for ( i = 0; i <= 9; i ++)
            {
                if (Epee[i].nombre)
                {
                    sprintf(temps, "%s", Epee[i].nom);
                    texte = TTF_RenderText_Blended(police2, temps, couleurBlanche);
                    SDL_BlitSurface(texte, NULL, ecran, &position);
                    SDL_FreeSurface(texte);
                    Epee[i].posi = position.y;
                    position.y += 30;
                    nombreobjet++;
                }
            } 
            
            TTF_CloseFont(police2); 
            
            if (nombreobjet > 0)
            {
                police2 = TTF_OpenFont("texte/times.ttf", 40);
                texte = TTF_RenderText_Blended(police2, ".", couleurBlanche);
                position.x = 195;
                position.y = lepoint;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                SDL_Flip(ecran);
            
                while (choice == 3 & *x == 2 & faire == 1 & **continuer != 0)
                {
                    tempsActuel = SDL_GetTicks();
                    SDL_PollEvent(&event);
                    renvoievaleur = 0;
                    if (tempsActuel - tempsPrecedent > 30)     
                    {
                        switch(event.type)
                        {
                            case SDL_QUIT:
                                **continuer = 0;
                                *x = 0;
                                break;
                    
      		                case SDL_KEYDOWN:
                                switch (event.key.keysym.sym)
                                {
                                    case SDLK_UP:
                                        lepoint -= 30;
                                        break;
                        
                                    case SDLK_DOWN:
                                        lepoint += 30;
                                        break;
                            
                                    case SDLK_RETURN:  
                                        renvoievaleur = 2;
                                        break;
                            
                                    case SDLK_LEFT:
                                        choice = 0;
                                        break;
                                }break;
                        }
            
                        event.key.keysym.sym = 0;
                    
                        texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, tailleecranl, 32, 0, 0,0, 0);
                        SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                        position.x = 185;
                        position.y = 0;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
    
                        if (lepoint > 30 * nombreobjet - 25)
                            lepoint = 30 * nombreobjet - 25; 
                
                        if (lepoint < 5)
                            lepoint = 5;
                                  
                        texte = TTF_RenderText_Blended(police2, ".", couleurBlanche);
                        position.x = 195;
                        position.y = lepoint;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        SDL_Flip(ecran);
                    
                        for ( i = 0; i <= 9; i ++)
                        {
                            if (Epee[i].posi == lepoint + 25)
                                AfficheEpeeBois(ecran, i);
                        }
                        
                        if (renvoievaleur == 2)
                        {
                            for ( i = 0; i <= 9; i ++)
                            {
                                if (Epee[i].posi == lepoint + 25)
                                    AfficheEquipe(ecran, i, *continuer);
                            }
                            faire = 0;
                        }
                        renvoievaleur = 0;
                        tempsPrecedent = tempsActuel;                        
                    }
                
                    else
                    {
                        SDL_Delay(30 - (tempsActuel - tempsPrecedent));
                    }
                }
                TTF_CloseFont(police2);
            }
            
            else if (nombreobjet == 0)
            {
                police2 = TTF_OpenFont("texte/times.ttf", 25);
                texte = TTF_RenderText_Blended(police2, "Vous n'avez aucune arme !", couleurBlanche);
                position.x = (tailleecranL + 175)/ 2 - 125;
                position.y = 10;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police2);
            
                police2 = TTF_OpenFont("texte/times.ttf", 15);
                texte = TTF_RenderText_Blended(police2, "Appuyez sur entrer", couleurBlanche);
                position.x = (tailleecranL + 175)/ 2 - 60;
                position.y = tailleecranl - 20;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                SDL_Flip(ecran);
                TTF_CloseFont(police2);
                
                while (choice == 3 & *x != 0)
                {
                    tempsActuel = SDL_GetTicks();
                    SDL_PollEvent(&event);
                    renvoievaleur = 0;
                
                    if (tempsActuel - tempsPrecedent > 30)     
                    {
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
                                        renvoievaleur = 2;
                                        break;
                                    
                                    case SDLK_LEFT:  
                                        renvoievaleur = 2;
                                        break;
                                }break;
                        }
                        event.key.keysym.sym = 0;
                    
                        if (renvoievaleur == 2)
                            choice = 0;
                        
                        tempsPrecedent = tempsActuel;                      
                    }
            
                    else
                    {
                        SDL_Delay(30 - (tempsActuel - tempsPrecedent));
                    }
                }
            }
        }
        
        while (choice == 4 & *x == 2 & faire == 1)
        {
            nombreobjet = i = 0;
            lepoint = 5;
            police2 = TTF_OpenFont("texte/cambria.ttc", 18);
            position.x = 210;
            position.y = 30;
            for ( i = 0; i <= 9; i ++)
            {
                if (Armures[i].nombre)
                {
                    sprintf(temps, "%s", Armures[i].nom);
                    texte = TTF_RenderText_Blended(police2, temps, couleurBlanche);
                    SDL_BlitSurface(texte, NULL, ecran, &position);
                    SDL_FreeSurface(texte);
                    Armures[i].posi = position.y;
                    position.y += 30;
                    nombreobjet++;
                }
            } 
            
            TTF_CloseFont(police2); 
            
            if (nombreobjet > 0)
            {
                police2 = TTF_OpenFont("texte/times.ttf", 40);
                texte = TTF_RenderText_Blended(police2, ".", couleurBlanche);
                position.x = 195;
                position.y = lepoint;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                SDL_Flip(ecran);
            
                while (choice == 4 & *x == 2 & faire == 1 & **continuer != 0)
                {
                    tempsActuel = SDL_GetTicks();
                    SDL_PollEvent(&event);
                    renvoievaleur = 0;
                    if (tempsActuel - tempsPrecedent > 30)     
                    {
                        switch(event.type)
                        {
                            case SDL_QUIT:
                                **continuer = 0;
                                *x = 0;
                                break;
                    
      		                case SDL_KEYDOWN:
                                switch (event.key.keysym.sym)
                                {
                                    case SDLK_UP:
                                        lepoint -= 30;
                                        break;
                        
                                    case SDLK_DOWN:
                                        lepoint += 30;
                                        break;
                            
                                    case SDLK_RETURN:  
                                        renvoievaleur = 2;
                                        break;
                            
                                    case SDLK_LEFT:
                                        choice = 0;
                                        break;
                                }break;
                        }
            
                        event.key.keysym.sym = 0;
                    
                        texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, tailleecranl, 32, 0, 0,0, 0);
                        SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                        position.x = 185;
                        position.y = 0;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
    
                        if (lepoint > 30 * nombreobjet - 25)
                            lepoint = 30 * nombreobjet - 25; 
                
                        if (lepoint < 5)
                            lepoint = 5;
                                  
                        texte = TTF_RenderText_Blended(police2, ".", couleurBlanche);
                        position.x = 195;
                        position.y = lepoint;
                        SDL_BlitSurface(texte, NULL, ecran, &position);
                        SDL_FreeSurface(texte);
                        SDL_Flip(ecran);
                    
                        for ( i = 0; i <= 9; i ++)
                        {
                            if (Armures[i].posi == lepoint + 25)
                                AfficheArmure(ecran, i);
                        }
                        
                        if (renvoievaleur == 2)
                        {
                            for ( i = 0; i <= 9; i ++)
                            {
                                if (Armures[i].posi == lepoint + 25)
                                    AfficheEquipeA(ecran, i, *continuer);
                            }
                            faire = 0;
                        }
                        renvoievaleur = 0;
                        tempsPrecedent = tempsActuel;                        
                    }
                
                    else
                    {
                        SDL_Delay(30 - (tempsActuel - tempsPrecedent));
                    }
                }
                TTF_CloseFont(police2);
            }
            
            else if (nombreobjet == 0)
            {
                police2 = TTF_OpenFont("texte/times.ttf", 25);
                texte = TTF_RenderText_Blended(police2, "Vous n'avez aucune armure !", couleurBlanche);
                position.x = (tailleecranL + 175)/ 2 - 135;
                position.y = 10;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                TTF_CloseFont(police2);
            
                police2 = TTF_OpenFont("texte/times.ttf", 15);
                texte = TTF_RenderText_Blended(police2, "Appuyez sur entrer", couleurBlanche);
                position.x = (tailleecranL + 175)/ 2 - 60;
                position.y = tailleecranl - 20;
                SDL_BlitSurface(texte, NULL, ecran, &position);
                SDL_FreeSurface(texte);
                SDL_Flip(ecran);
                TTF_CloseFont(police2);
                
                while (choice == 4 & *x != 0)
                {
                    tempsActuel = SDL_GetTicks();
                    SDL_PollEvent(&event);
                    renvoievaleur = 0;
                
                    if (tempsActuel - tempsPrecedent > 30)     
                    {
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
                                        renvoievaleur = 2;
                                        break;
                                    
                                    case SDLK_LEFT:  
                                        renvoievaleur = 2;
                                        break;
                                }break;
                        }
                        event.key.keysym.sym = 0;
                    
                        if (renvoievaleur == 2)
                            choice = 0;
                        
                        tempsPrecedent = tempsActuel;                      
                    }
            
                    else
                    {
                        SDL_Delay(30 - (tempsActuel - tempsPrecedent));
                    }
                }
            }
        }
        
        texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL, tailleecranl, 32, 0, 0,0, 0);
        SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        position.x = 185;
        position.y = 0;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        
    }while (*x == 2 & **continuer != 0);
    TTF_CloseFont(police);
    
}
