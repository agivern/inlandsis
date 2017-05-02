#include "demarage.h"
#include "variable.h"
#include "sauve.h"

void demarage (SDL_Surface* ecran, int *continuer2)
{
    SDL_Surface *texte= NULL;
    SDL_Rect positionTexte;
    
    SDL_Event event;
    
    int tempsPrecedent = 0, tempsActuel = 0, x = 1, lepoint = 0;
    
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 25);
    SDL_Color couleurBlanche = {255, 255, 255};
    
    tailleecranL = 1024;
    tailleecranl = 768;
    
    texte = TTF_RenderText_Blended(police, "Nouvelle partie", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 83;
    positionTexte.y = tailleecranl - 350;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Continuer", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 53;
    positionTexte.y = tailleecranl - 300;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Quitter", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 39;
    positionTexte.y = tailleecranl - 250;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont (police);
    
    police = TTF_OpenFont("texte/times.ttf", 50);
    texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
    positionTexte.x = tailleecranL / 2 - 100;
    positionTexte.y = tailleecranl - 380 + lepoint;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
    positionTexte.x = tailleecranL / 2 + 87;
    positionTexte.y = tailleecranl - 380 + lepoint;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    SDL_Flip (ecran);
    
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 55, 32, 0, 0, 0, 0);
    
    while (x)
    { 
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);
        
        if ( tempsActuel - tempsPrecedent > 30 )
        {
            switch(event.type)
            {
                case SDL_QUIT:
                {
                    *continuer2 = 0;
                    x = 0;
                    break;
                }
                break;
                
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            lepoint -= 52;
                            break;
                        
                        case SDLK_DOWN:
                            lepoint += 52;
                            break;
                            
                        case SDLK_RETURN:  
                            x = 2;
                            break;
                    }
                    break;
            }
            
            event.key.keysym.sym = 0;
            
            if (lepoint > 104)
                lepoint = 104; 
                
            if (lepoint < 0)
                lepoint = 0;
            
            if (lepoint == 0)
            {
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 - 74;
                positionTexte.y = tailleecranl - 380 + 52;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 + 60;
                positionTexte.y = tailleecranl - 380 + 52;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 + 87;
                positionTexte.y = tailleecranl - 380 + lepoint;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 100;
                positionTexte.y = tailleecranl - 380 + lepoint;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            }
            
            else if (lepoint == 52)
            {
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 17, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 - 100;
                positionTexte.y = tailleecranl - 380 + 0;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 + 87;
                positionTexte.y = tailleecranl - 380 + 0;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 15, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 - 59;
                positionTexte.y = tailleecranl - 380 + 104;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 + 45;
                positionTexte.y = tailleecranl - 380 + 104;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 + 60;
                positionTexte.y = tailleecranl - 380 + lepoint;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x =  tailleecranL / 2 - 74;
                positionTexte.y = tailleecranl - 380 + lepoint;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            }
            
            else if (lepoint == 104)
            {
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 - 74;
                positionTexte.y = tailleecranl - 380 + 55;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 50, 32, 0, 0,0, 0);
                SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                positionTexte.x = tailleecranL / 2 + 60;
                positionTexte.y = tailleecranl - 380 + 52;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 + 45;
                positionTexte.y = tailleecranl - 380 + lepoint;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
                
                texte = TTF_RenderText_Blended(police, ".", couleurBlanche);
                positionTexte.x = tailleecranL / 2 - 59;
                positionTexte.y = tailleecranl - 380 + lepoint;
                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                SDL_FreeSurface(texte);
            }
            SDL_Flip(ecran);
            
            if ( x == 2 & lepoint == 104)
            {  
                x = 0;
                *continuer2 = 0;
            }
            
            if ( x == 2 & lepoint == 0)
            {  
                x = 0;
                variablevent = 1;
                force = 50;
                dexterite = 50;
                constitution = 50;
                intelligence = 5;
                sagesse = 5;
                charisme = 5;
                
                or = 0;
                    
                experience = 0;
                experienceUp = 1;
                niveau = 10;
                pointaatribuer = 0;  
                
                vitesseattaque = 50;
                
                pointdevie = pointdevierestant = 20 + constitution;
                mana = manarestant = 5 + intelligence;
                    
                Precision = 20 + dexterite / 5;
                TauxDeCritique = 1 + dexterite / 10;
                AttPhyMin = 1 + force;
                AttPhyMax = 10 + force;
                AttMagMin = 1 + intelligence;
                AttMagMax = 10 + intelligence;
                DegMinCri = 1 + (force + dexterite);
                DegMaxCri = 10 + force + dexterite;
                    
                Blocage = 0;
                DefMag = 0 + sagesse;
                DefPhy = 0 + constitution;
                Esquive = dexterite / 2;
                    
                positionx[0] = 500;
                positiony[0] = 500;
                
                sprintf(Objets[0].nom, "Potion", NULL);
                Objets[0].nombre = 1;
                sprintf(Objets[1].nom, "Potion +", NULL);
                Objets[1].nombre = 0;
                sprintf(Objets[2].nom, "Energisant", NULL);
                Objets[2].nombre = 0;
                sprintf(Objets[3].nom, "Energisant +", NULL);
                Objets[3].nombre = 0;
                sprintf(Objets[4].nom, "Remède", NULL);
                Objets[4].nombre = 0;
                sprintf(Objets[5].nom, "Adrenaline", NULL);
                Objets[5].nombre = 0;
                sprintf(Objets[6].nom, "Potion de furtivité", NULL);
                Objets[6].nombre = 0;
                
                sprintf(Resources[0].nom, "Herbes", NULL);
                Resources[0].nombre = 3;
                sprintf(Resources[1].nom, "Canine de loups", NULL);
                Resources[1].nombre = 0;
                sprintf(Resources[2].nom, "bois de cerf", NULL);
                Resources[2].nombre = 0;
                
                sprintf(magies[0].nom, "Eclats magique", NULL);
                magies[0].nombre = 0;
                sprintf(magies[1].nom, "Eclat de feu", NULL);
                magies[1].nombre = 0;
                
                sprintf(expertises[0].nom, "Maniement des armes a une main", NULL);
                expertises[0].nombre = 1;
                sprintf(expertises[1].nom, "Vision de l'échapatoire", NULL);
                expertises[1].nombre = 0;
                sprintf(expertises[2].nom, "Port d'armure de base", NULL);
                expertises[1].nombre = 0;
                sprintf(expertises[3].nom, "Maniement des armes a deux mains", NULL);
                expertises[1].nombre = 0;
                
                sprintf(techniques[0].nom, "Coup de pied", NULL);
                techniques[0].nombre = 0;
                sprintf(techniques[1].nom, "Attaque enragé", NULL);
                techniques[1].nombre = 0;
                
                sprintf(arme[0].nom, "Epée en bois", NULL);
                arme[0].DegatMin = 1;
                arme[0].DegatMax = 3;
                arme[0].DegatMagMin = 0;
                arme[0].DegatMagMax = 0;
                arme[0].prix = 5;
                arme[0].durabilite = 25;
                arme[0].durabiliteRestante = 25;
                arme[0].vitesse = 2;
                
                sprintf(armure[0].nom, "Tenue de villageois", NULL);
                armure[0].DefPhy = 2;
                armure[0].DefMag = 0;
                armure[0].prix = 15;
                armure[0].durabilite = 35;
                armure[0].durabiliteRestante = 35;
                
                *continuer2 = 3;
            }
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
    }
    
    TTF_CloseFont (police);
}
