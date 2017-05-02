#include "combat.h"
#include "variable.h"

void remplir3 (SDL_Surface* ecran);

void attaqueMob(SDL_Surface* ecran, int tempsjoueur, struct Stat monstre2)
{
    int x, nombreMystere;
    
    x = (rand() % (100)) + 1;

    if (x < 50 - monstre2.Precision + Esquive )
        afficheVie(ecran, tempsjoueur);

    else if (x > 50 - monstre2.Precision + Esquive + monstre2.TauxDeCritique)
    {
        nombreMystere = (rand() % (monstre2.AttPhyMax - monstre2.AttPhyMin) + monstre2.AttPhyMin) + 1 - DefPhy;
            
        if (nombreMystere < 1)
            nombreMystere = 1;
             
        pointdevierestant = pointdevierestant - nombreMystere;

        afficheVie(ecran, tempsjoueur);
    }

    else
    {
        nombreMystere = (rand() % (monstre2.DegMaxCri - monstre2.DegMinCri) + monstre2.DegMinCri) + 1 - DefPhy;
            
        pointdevierestant = pointdevierestant - nombreMystere;
        afficheVie(ecran, tempsjoueur);
    }
}

void attaqueJoueur(SDL_Surface* ecran, int *fuite2, int *pointdevieMob, int ***continuer3)
{
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    
    SDL_Event event;
    
    TTF_Font *police = NULL, *police2 = NULL;
    police = TTF_OpenFont("texte/times.ttf", 50);
    police2 = TTF_OpenFont("texte/times.ttf", 23);
    SDL_Color couleurBlanche = {255, 255, 255};
    SDL_Color couleurNoire = {0, 0, 0};
    
    int x = 1, x2 = 1, fairetantque = 1, enhaut = 0, renvoievaleur = 0, nombreMystere, choice = 0, tempsPrecedent = 0, tempsActuel = 0, lepoint = -15, letrait = 47;
    int mobselectionne = 0;
    char temps[25] = "";
    
    texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
    position.x = 50;
    position.y = tailleecranl * 68 / 100 + lepoint;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    remplir3 (ecran);

    do
    {   
    while ( choice == 0 & pointdevie > 0 & x2 != 0)
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
                    ***continuer3 = 0;
                    x2 = 0;
                    fairetantque = 0;
                }break;
                
      		    case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            lepoint -= 29;
                            break;
                        
                         case SDLK_DOWN:
                            lepoint = lepoint + 29;
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
            
            event.key.keysym.sym = 0;
            
            texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, tailleecranl * 32 / 100, 32, 0, 0,0, 0);
            SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            position.x = 50;
            position.y = tailleecranl * 68 / 100 + 4;
            SDL_BlitSurface(texte, NULL, ecran, &position);
            SDL_FreeSurface(texte);
    
            if (lepoint > 101)
                lepoint = 101; 
                
            if (lepoint < -15)
                lepoint = -15;
                                  
            texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
            position.x = 50;
            position.y = tailleecranl * 68 / 100 + lepoint;
            SDL_BlitSurface(texte, NULL, ecran, &position);
            SDL_FreeSurface(texte);
            SDL_Flip(ecran);
            
            monstre1.tempsmob ++;
            if (nombreMonstre > 1)
                monstre2.tempsmob ++;
            if (nombreMonstre > 2)
                monstre3.tempsmob ++;
                
            afficheVie (ecran, vitesseattaque);
            SDL_Flip(ecran);
            
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
            
            if (renvoievaleur)
            {
                if ( lepoint == -15)
                    choice = 1;
                else if ( lepoint == 14)
                    choice = 2;
                else if ( lepoint == 43)
                    choice = 3;
                else if (lepoint == 72)
                    choice = 4;
                else if (lepoint == 101)
                    choice = 5;
            }
            renvoievaleur = 0;
            tempsPrecedent = tempsActuel;                      
        }   
            
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        } 
               
    }
    
    while ( choice == 1 & pointdevie > 0 & x2 != 0)
    {
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);
        
        if (tempsActuel - tempsPrecedent > 30)     
        {
            switch(event.type)
            {
                case SDL_QUIT:
                {
                    ***continuer3 = 0;
                    x2 = 0;
                    fairetantque = 0;
                }break;
                
      		    case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            {letrait -= 47;
                            enhaut = 1;}
                            break;
                        
                        case SDLK_DOWN:
                            {letrait += 47;
                            enhaut = 2;}
                            break;
                            
                        case SDLK_LEFT:
                            choice = 0;
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
            
            afficheVie (ecran, vitesseattaque); 
                        
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
            
            texte = IMG_Load("images/combat/curseur.bmp");
            SDL_SetColorKey(texte, SDL_SRCCOLORKEY, SDL_MapRGB(texte->format, 91, 255, 66));
            
            SDL_BlitSurface(texte, NULL, ecran, &position);
            SDL_FreeSurface (texte);                     
            SDL_Flip(ecran);
            
            if (renvoievaleur)
            {
                if (letrait == 47)
                    destruction(ecran, &monstre1, mobselectionne);
                if (letrait == 94)
                    destruction(ecran, &monstre2, mobselectionne);
                if (letrait == 141)
                    destruction(ecran, &monstre3, mobselectionne);
                choice = 0;
                fairetantque = 0;
            }
            tempsPrecedent = tempsActuel;                      
        }   
            
        else
        { 
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    
    while ( choice == 2 & pointdevie > 0 & x2 != 0)
    {
        utilisemagie(ecran, &choice, &x2, **continuer3, &fairetantque);
    }
    
    while ( choice == 3 & pointdevie > 0 & x2 != 0)
    {
        utilisetechnique(ecran, &choice, &x2, **continuer3, &fairetantque);
    }
    
    while ( choice == 4 & pointdevie > 0 & x2 != 0)
    {
        utiliseobjet(ecran, &choice, &x2, **continuer3, &fairetantque);
    }
    
    while ( choice == 5 & pointdevie > 0 & x2 != 0)
    {
        if (expertises[1].nombre == 1)
            *fuite2 = (rand() % (4)+1);
        else
            *fuite2 = (rand() % (5)+1);
            
        fairetantque = 0;
        choice = 0;
    }
    
    if (nombreMonstre == 1)
       *pointdevieMob = monstre1.pointdevierestant;
    if (nombreMonstre == 2)
       *pointdevieMob = monstre1.pointdevierestant + monstre2.pointdevierestant;
    if (nombreMonstre == 3)
       *pointdevieMob = monstre1.pointdevierestant + monstre2.pointdevierestant + monstre3.pointdevierestant;
       
}while (fairetantque);

    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 200,400, 32, 0, 0,0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    position.x = 0;
    position.y = tailleecranL / 2 + 6;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    SDL_Flip (ecran);
    TTF_CloseFont(police);
    TTF_CloseFont(police2);
}

void remplir3 ( SDL_Surface* ecran)
{
    SDL_Surface *texte = NULL;
    SDL_Rect position;
     
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambriai.ttf", 25);
    SDL_Color couleurBlanche = {255, 255, 255};
    
    texte = TTF_RenderText_Blended(police, "Attaque", couleurBlanche);
    position.x = 75;
    position.y = tailleecranl * 68 / 100 + 15;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Magie", couleurBlanche);
    position.x = 75;
    position.y = tailleecranl * 68 / 100 + 45;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Technique", couleurBlanche);
    position.x = 75;
    position.y = tailleecranl * 68 / 100 + 75;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Objet", couleurBlanche);
    position.x = 75;
    position.y = tailleecranl * 68 / 100 + 105;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Fuir", couleurBlanche);
    position.x = 75;
    position.y = tailleecranl * 68 / 100 + 135;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    SDL_Flip (ecran);
    
    TTF_CloseFont(police);
}


void destruction(SDL_Surface* ecran, struct Stat* monstre2, int mobselectionne)
{
    int x;
    int nombreMystere;
    
    x = (rand() % (100)) + 1;

    if (x < 50 - Precision + monstre2->Esquive)
    {        
        afficheVie(ecran, vitesseattaque);
        evenementrate(ecran, mobselectionne);

    }
    
    else if (x > 50 - Precision + monstre2->Esquive + TauxDeCritique )
    {
        nombreMystere = (rand() % (AttPhyMax - AttPhyMin) + AttPhyMin) + 1 - monstre2->DefPhy;
        afficheVie(ecran, vitesseattaque);
        monstre2->pointdevierestant -= nombreMystere;
        if (monstre2->pointdevierestant < 0)
            monstre2->pointdevierestant = 0;
        evenementtouche(ecran, mobselectionne, nombreMystere);
    }
    
    else
    {
        nombreMystere = (rand() % (DegMaxCri - DegMinCri) + DegMinCri) + 1 - monstre2->DefPhy;
        afficheVie(ecran, vitesseattaque); 
        monstre2->pointdevierestant -= nombreMystere;
        if (monstre2->pointdevierestant < 0)
            monstre2->pointdevierestant = 0;
        evenementtouche(ecran, mobselectionne, nombreMystere);
    }
    afficheVie(ecran, 0);
}


void evenementrate(SDL_Surface* ecran, int mobselectionne)
{
    SDL_Surface *texte = NULL;
    SDL_Rect position;
     
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambriai.ttf", 23);
    SDL_Color couleurNoire = {0, 0, 0};
    SDL_Event event;
    
    int x = 0, tempsActuel = 0, tempsPrecedent = 0;
    
    texte = TTF_RenderText_Blended(police, "Raté", couleurNoire);
    
    if (mobselectionne == 1)
    {        
        position.x = 400;
        position.y = tailleecranL / 5 + 100;
    }
    
    else if (mobselectionne == 2)
    {
        position.x = 250;
        position.y = tailleecranL / 4 + 100;
    }
    
    else if (mobselectionne == 3)
    {
        position.x = 100;
        position.y = tailleecranL / 3 + 100;
    }
    
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    SDL_Flip (ecran);
    
    while (x < 33)
    {
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);
        if (tempsActuel - tempsPrecedent > 30)     
        {
            switch(event.type)
            {
            }
            x ++;
            tempsPrecedent = tempsActuel;                      
        }
            
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    TTF_CloseFont(police);
}


void evenementtouche(SDL_Surface* ecran, int mobselectionne, int degat)
{
    SDL_Surface *texte = NULL;
    SDL_Rect position;
     
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambriai.ttf", 23);
    SDL_Color couleurNoire = {0, 0, 0};
    SDL_Event event;
    
    char temps[20];
    sprintf(temps, "%d dégats", degat);
    
    int x = 0, tempsActuel = 0, tempsPrecedent = 0;
    
    texte = TTF_RenderText_Blended(police, temps, couleurNoire);
    if (mobselectionne == 1)
    {        
        position.x = 400;
        position.y = tailleecranL / 5 + 100;
    }
    
    else if (mobselectionne == 2)
    {
        position.x = 250;
        position.y = tailleecranL / 4 + 100;
    }
    
    else if (mobselectionne == 3)
    {
        position.x = 100;
        position.y = tailleecranL / 3 + 100;
    }
    
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    SDL_Flip (ecran);
    
    while (x < 33)
    {
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);
        if (tempsActuel - tempsPrecedent > 30)     
        {
            switch(event.type)
            {
            }
            x ++;
            tempsPrecedent = tempsActuel;                      
        }
            
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    TTF_CloseFont(police);
}
