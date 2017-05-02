#include "objet.h"
#include "variable.h"

void AfficheEpeeBois (SDL_Surface* ecran, int i)
{
    SDL_Surface *texte= NULL;
    SDL_Rect position;
    
    char attphysique [35] = "";
    char attmagique [35] = "";
    char prix [25] = "";
    char durrabilite [25] = "";
    
    sprintf(attphysique, "Dégat physique : %d - %d", Epee[i].DegatMin, Epee[i].DegatMax);
    sprintf(attmagique, "Dégat magique : %d - %d", Epee[i].DegatMagMin, Epee[i].DegatMagMax);
    sprintf(prix, "Prix : %d", Epee[i].prix);
    sprintf(durrabilite, "Durabilité : %d/%d", Epee[i].durabiliteRestante, Epee[i].durabilite);

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
    texte = TTF_RenderText_Blended(police, "Epée a une main", couleurBlanche);
    position.y = 80;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, attphysique, couleurBlanche);
    position.y = 110;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, attmagique, couleurBlanche);
    position.y = 140;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    if (Epee[i].vitesse == 2)
        texte = TTF_RenderText_Blended(police, "Vitesse : moyenne", couleurBlanche);
    position.y = 170;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Effet : aucun", couleurBlanche);
    position.y = 200;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, durrabilite, couleurBlanche);
    position.y = 230;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, prix, couleurBlanche);
    position.y = 260;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    TTF_CloseFont(police);
    SDL_Flip(ecran);
}



void AfficheEquipe(SDL_Surface* ecran, int i, int *continuer)
{    
    SDL_Surface *texte = NULL;
    SDL_Rect positionTexte;
    
    SDL_Event event;
    
    int tempsPrecedent = 0, tempsActuel = 0, lepoint = 81, valeur = 0, i2;
    int AttPhyMin2 = AttPhyMin - arme[0].DegatMin + Epee[i].DegatMin;
    int AttPhyMax2 = AttPhyMax - arme[0].DegatMax + Epee[i].DegatMax;
    int AttMagMin2 = AttMagMin - arme[0].DegatMagMin + Epee[i].DegatMagMin;
    int AttMagMax2 = AttMagMax - arme[0].DegatMagMax + Epee[i].DegatMagMax;
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
    
    texte = TTF_RenderText_Blended(police, arme[0].nom, couleurBlanche);
    positionTexte.x = 33;
    positionTexte.y = 110;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, Epee[i].nom, couleurBlanche);
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
    sprintf(temps, "Dégat Physique : %d - %d", AttPhyMin, AttPhyMax);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    positionTexte.x = 33;
    positionTexte.y = 150;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Dégat Physique :", couleurBlanche);
    positionTexte.x = tailleecranL - 205;
    positionTexte.y = 150;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    if (AttPhyMin2 > AttPhyMin & AttPhyMax2 > AttPhyMax)
    {
        sprintf(temps, "%d - %d", AttPhyMin2, AttPhyMax2);
        texte = TTF_RenderText_Blended(police, temps, couleurVerte);
        positionTexte.x = tailleecranL - 70;
        positionTexte.y = 150;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
        sprintf(temps, "%d - %d", DegMinCri - arme[0].DegatMin + Epee[i].DegatMin , DegMaxCri - arme[0].DegatMax + Epee[i].DegatMax);
        texte = TTF_RenderText_Blended(police, temps, couleurVerte);
        positionTexte.x = tailleecranL - 78;
        positionTexte.y = 200;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
    }
    
    else if (AttPhyMin2 == AttPhyMin & AttPhyMax2 == AttPhyMax)
    {
        sprintf(temps, "%d - %d", AttPhyMin2, AttPhyMax2);
        texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
        positionTexte.x = tailleecranL - 70;
        positionTexte.y = 150;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
        sprintf(temps, "%d - %d", DegMinCri - arme[0].DegatMin + Epee[i].DegatMin , DegMaxCri - arme[0].DegatMax + Epee[i].DegatMax);
        texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
        positionTexte.x = tailleecranL - 78;
        positionTexte.y = 200;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
    }
    
    else
    {
        sprintf(temps, "%d - %d", AttPhyMin2, AttPhyMax2);
        texte = TTF_RenderText_Blended(police, temps, couleurRouge);
        positionTexte.x = tailleecranL - 70;
        positionTexte.y = 150;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
        sprintf(temps, "%d - %d", DegMinCri - arme[0].DegatMin + Epee[i].DegatMin , DegMaxCri - arme[0].DegatMax + Epee[i].DegatMax);
        texte = TTF_RenderText_Blended(police, temps, couleurRouge);
        positionTexte.x = tailleecranL - 78;
        positionTexte.y = 200;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
    }
    
    texte = TTF_RenderText_Blended(police, "Dégat Critique :", couleurBlanche);
    positionTexte.x = tailleecranL - 205;
    positionTexte.y = 200;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
        
    sprintf(temps, "Dégat Magique : %d - %d", AttMagMin, AttMagMax);
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
    
    if (AttMagMin2 > AttMagMin & AttMagMax2 > AttMagMax)
    {
        sprintf(temps, "%d - %d", AttMagMin2, AttMagMax2);
        texte = TTF_RenderText_Blended(police, temps, couleurVerte);
        positionTexte.x = tailleecranL - 74;
        positionTexte.y = 175;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
    }
    
    else if (AttMagMin2 == AttMagMin & AttMagMax2 == AttMagMax)
    {
        sprintf(temps, "%d - %d", AttMagMin2, AttMagMax2);
        texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
        positionTexte.x = tailleecranL - 74;
        positionTexte.y = 175;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
    }
    
    else
    {
        sprintf(temps, "%d - %d", AttMagMin2, AttMagMax2);
        texte = TTF_RenderText_Blended(police, temps, couleurRouge);
        positionTexte.x = tailleecranL - 74;
        positionTexte.y = 175;
        SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
        SDL_FreeSurface(texte);
    }
    
    if (Epee[i].vitesse == 2)
        texte = TTF_RenderText_Blended(police, "Vitesse : moyenne", couleurBlanche);
    positionTexte.x = tailleecranL - 205;
    positionTexte.y = 225;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    if (arme[0].vitesse == 2)
        texte = TTF_RenderText_Blended(police, "Vitesse : moyenne", couleurBlanche);
    positionTexte.x = 33;
    positionTexte.y = 225;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    sprintf(temps, "Dégat critique : %d - %d", DegMinCri, DegMaxCri);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    positionTexte.x = 33;
    positionTexte.y = 200;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    sprintf(temps, "Effet : aucun", arme[0].durabiliteRestante, arme[0].durabilite);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    positionTexte.x = 33;
    positionTexte.y = 250;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    sprintf(temps, "Effet : aucun", Epee[i].durabiliteRestante, Epee[i].durabilite);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    positionTexte.x = tailleecranL - 205;
    positionTexte.y = 250;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    sprintf(temps, "Durabilité : %d/%d", arme[0].durabiliteRestante, arme[0].durabilite);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    positionTexte.x = 33;
    positionTexte.y = 275;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    sprintf(temps, "Durabilité : %d/%d", Epee[i].durabiliteRestante, Epee[i].durabilite);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    positionTexte.x = tailleecranL - 205;
    positionTexte.y = 275;
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
                    if (Epee[i2].nombre == 0)
                    {
                        sprintf(Epee[i2].nom, arme[0].nom, NULL);
                        Epee[i2].DegatMin = arme[0].DegatMin;
                        Epee[i2].DegatMax = arme[0].DegatMax;
                        Epee[i2].DegatMagMin = arme[0].DegatMagMin;
                        Epee[i2].DegatMagMax = arme[0].DegatMagMax;
                        Epee[i2].durabilite = arme[0].durabilite;
                        Epee[i2].durabiliteRestante = arme[0].durabiliteRestante;
                        Epee[i2].prix = arme[0].prix;
                        Epee[i2].vitesse = arme[0].vitesse;
                        Epee[i2].nombre = 1;
                        i2 = 10;
                    }
                }
                
                sprintf(arme[0].nom, Epee[i].nom, NULL);
                arme[0].DegatMin = Epee[i].DegatMin;
                arme[0].DegatMax = Epee[i].DegatMax;
                arme[0].DegatMagMin = Epee[i].DegatMagMin;
                arme[0].DegatMagMax = Epee[i].DegatMagMax;
                arme[0].durabilite = Epee[i].durabilite;
                arme[0].durabiliteRestante = Epee[i].durabiliteRestante;
                arme[0].prix = Epee[i].prix;
                arme[0].vitesse = Epee[i].vitesse;
                Epee[i].nombre = 0;
                Epee[i].posi = 0;
                
                AttPhyMin = 1 + force + arme[0].DegatMin;
                AttPhyMax = 10 + force + arme[0].DegatMax;
                AttMagMin = 1 + intelligence + arme[0].DegatMagMin;
                AttMagMax = 10 + intelligence + arme[0].DegatMagMax;
                DegMinCri = 1 + (force + dexterite);
                DegMaxCri = 10 + force + dexterite;
                
                if (arme[0].vitesse == 2)
                    vitesseattaque = 100;
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
