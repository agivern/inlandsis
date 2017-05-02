#include "objet.h"
#include "variable.h"

void AfficheArmure (SDL_Surface* ecran, int i)
{
    SDL_Surface *texte= NULL;
    SDL_Rect position;
    
    char defphysique [35] = "";
    char defmagique [35] = "";
    char prix [25] = "";
    char durrabilite [25] = "";
    
    sprintf(defphysique, "Résistance physique : %d", Armures[i].DefPhy);
    sprintf(defmagique, "Résistance magique : %d", Armures[i].DefMag);
    sprintf(prix, "Prix : %d", Armures[i].prix);
    sprintf(durrabilite, "Durabilité : %d/%d", Armures[i].durabiliteRestante, Armures[i].durabilite);

    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 30);
    SDL_Color couleurBlanche = {255, 255, 255};
    
    position.x = tailleecranL - 200;
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, tailleecranl, 32, 0, 0,0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    position.y = 0;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, Epee[i].nom, couleurBlanche);
    position.y = 25;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
    
    police = TTF_OpenFont("texte/cambria.ttc", 18);
    texte = TTF_RenderText_Blended(police, "Armure en tissu", couleurBlanche);
    position.y = 80;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, defphysique, couleurBlanche);
    position.y = 110;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, defmagique, couleurBlanche);
    position.y = 140;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Effet : aucun", couleurBlanche);
    position.y = 170;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, durrabilite, couleurBlanche);
    position.y = 200;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, prix, couleurBlanche);
    position.y = 230;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    TTF_CloseFont(police);
    SDL_Flip(ecran);
}



void AfficheEquipeA(SDL_Surface* ecran, int i, int *continuer)
{    
    SDL_Surface *texte = NULL;
    SDL_Rect positionTexte;
    
    SDL_Event event;
    
    int tempsPrecedent = 0, tempsActuel = 0, lepoint = 81, valeur = 0, i2;
    
    int DefPhy2 = DefPhy - armure[0].DefPhy + Armures[i].DefPhy;
    int DefMag2 = DefMag - armure[0].DefMag + Armures[i].DefMag;
    
    char temps[40] ={0};
    
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 25);
    SDL_Color couleurBlanche = {255, 255, 255};
    SDL_Color couleurVerte = {97, 170, 93};
    SDL_Color couleurRouge = {236, 55, 40};
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL, tailleecranl, 32, 0, 0, 0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    positionTexte.x = 0;
    positionTexte.y = 0;
    SDL_BlitSurface(texte, NULL , ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL - 12, tailleecranl - 12, 32, 0, 0, 0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    positionTexte.x = 6;
    positionTexte.y = 6;
    SDL_BlitSurface(texte, NULL , ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, armure[0].nom, couleurBlanche);
    positionTexte.x = 33;
    positionTexte.y = 110;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, Armures[i].nom, couleurBlanche);
    positionTexte.x = tailleecranL - 205;
    positionTexte.y = 110;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
    
    police = TTF_OpenFont("texte/cambria.ttc", 50);
    texte = TTF_RenderText_Blended(police, "CHANGEMENT D'EQUIPEMENT", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 337;
    positionTexte.y = 5;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
    
    police = TTF_OpenFont("texte/cambria.ttc", 18);
    sprintf(temps, "Defense Physique : %d", DefPhy);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    positionTexte.x = 33;
    positionTexte.y = 150;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Defense Physique :", couleurBlanche);
    positionTexte.x = tailleecranL - 205;
    positionTexte.y = 150;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    sprintf(temps, "%d", DefPhy2);
    
    if (DefPhy2 > DefPhy)
    {
        texte = TTF_RenderText_Blended(police, temps, couleurVerte);
        positionTexte.x = tailleecranL - 58;
        positionTexte.y = 150;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
    }
    
    else if (DefPhy2 == DefPhy)
    {
        texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
        positionTexte.x = tailleecranL - 58;
        positionTexte.y = 150;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
    }
    
    else
    {
        texte = TTF_RenderText_Blended(police, temps, couleurRouge);
        positionTexte.x = tailleecranL - 58;
        positionTexte.y = 150;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
    }
        
    sprintf(temps, "Defense Magique : %d", DefMag);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    positionTexte.x = 33;
    positionTexte.y = 175;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Dégat Magique :", couleurBlanche);
    positionTexte.x = tailleecranL - 205;
    positionTexte.y = 175;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    sprintf(temps, "%d", DefMag2);
    
    if (DefMag2 > DefMag)
    {
        texte = TTF_RenderText_Blended(police, temps, couleurVerte);
        positionTexte.x = tailleecranL - 74;
        positionTexte.y = 175;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
    }
    
    else if (DefMag2 == DefMag)
    {
        texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
        positionTexte.x = tailleecranL - 74;
        positionTexte.y = 175;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
    }
    
    else
    {
        texte = TTF_RenderText_Blended(police, temps, couleurRouge);
        positionTexte.x = tailleecranL - 74;
        positionTexte.y = 175;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
    }
    
    sprintf(temps, "Effet : aucun", arme[0].durabiliteRestante, arme[0].durabilite);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    positionTexte.x = 33;
    positionTexte.y = 200;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    sprintf(temps, "Effet : aucun", Epee[i].durabiliteRestante, Epee[i].durabilite);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    positionTexte.x = tailleecranL - 205;
    positionTexte.y = 200;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    sprintf(temps, "Durabilité : %d/%d", arme[0].durabiliteRestante, arme[0].durabilite);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    positionTexte.x = 33;
    positionTexte.y = 225;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    sprintf(temps, "Durabilité : %d/%d", Epee[i].durabiliteRestante, Epee[i].durabilite);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    positionTexte.x = tailleecranL - 205;
    positionTexte.y = 225;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
    
    police = TTF_OpenFont("texte/cambria.ttc", 25);
    texte = TTF_RenderText_Blended(police, "Equipé", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 33;
    positionTexte.y = tailleecranl - 90;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);

    texte = TTF_RenderText_Blended(police, "Retour", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 33;
    positionTexte.y = tailleecranl - 50;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont (police);
    
    police = TTF_OpenFont("texte/times.ttf", 50);
    texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 52;
    positionTexte.y = tailleecranl - 40 - lepoint;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    SDL_Flip (ecran);
    
    while (*continuer != 0 & valeur == 0)
    { 
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);

        if (tempsActuel - tempsPrecedent > 30)	
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    *continuer = 0;
                    break;
                
                case SDL_KEYDOWN:
                     switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            lepoint += 40;
                            break;
                        
                        case SDLK_DOWN:
                            lepoint -= 40;
                            break;
                            
                        case SDLK_RETURN:  
                            valeur = 1;
                            break;
                    }
                    break;
            }
            
            event.key.keysym.sym = 0;
            
            if (lepoint < 41)
                lepoint = 41;
            else if ( lepoint > 81)
                lepoint = 81;
                
            texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, 100, 32, 0, 0,0, 0);
            SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            positionTexte.x = tailleecranL / 2 - 60;
            positionTexte.y = tailleecranl - 120;
            SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
            SDL_FreeSurface(texte);
        
            texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
            positionTexte.x = tailleecranL / 2 - 52;
            positionTexte.y = tailleecranl - 40 - lepoint;
            SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
            SDL_FreeSurface(texte);
                    
            if (valeur == 1 & lepoint == 81)
            {
                for (i2 = 0; i2 < 10; i2++)
                {
                    if (Armures[i2].nombre == 0)
                    {
                        sprintf(Armures[i2].nom, armure[0].nom, NULL);
                        Armures[i2].DefPhy = armure[0].DefPhy;
                        Armures[i2].DefMag = armure[0].DefMag;
                        Armures[i2].durabilite = armure[0].durabilite;
                        Armures[i2].durabiliteRestante = armure[0].durabiliteRestante;
                        Armures[i2].prix = armure[0].prix;
                        Armures[i2].nombre = 1;
                        i2 = 10;
                    }
                }
                
                sprintf(arme[0].nom, Epee[i].nom, NULL);
                armure[0].DefPhy = Armures[i].DefPhy;
                armure[0].DefMag = Armures[i].DefMag;
                armure[0].durabilite = Armures[i].durabilite;
                armure[0].durabiliteRestante = Armures[i].durabiliteRestante;
                armure[0].prix = Armures[i].prix;
                Armures[i].nombre = 0;
                Armures[i].posi = 0;
                
                DefPhy = constitution + armure[0].DefPhy;
                DefMag = sagesse + armure[0].DefMag;
            }
            
            SDL_Flip(ecran);
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    TTF_CloseFont (police);
}
