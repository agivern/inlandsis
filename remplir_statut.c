#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#include "jeux.h"
#include "variable.h"

void remplir_statut (SDL_Surface* ecran)
{
    SDL_Surface *affichevie = NULL, *affichemana = NULL, *texte= NULL, *affichexp = NULL;
    SDL_Rect positionTexte, positionVie, positionMana, positionxp;
    
    int barreVie = (pointdevierestant * 200) / pointdevie;
    int barreMana = (manarestant * 200) / mana;
    int barreExperience = (experience * 200) / experienceUp;
   	
    positionVie.x = 50;
    positionVie.y = 240;
    
    positionMana.x = tailleecranL - 250;
    positionMana.y = 240;
    
    positionxp.x = tailleecranL/ 2 - 100;
    positionxp.y = 240;
    
    char level[10] = "";
    char PV[10] = "";
    char MANA[10] = "";
    char Experience[10] = "";
    
    char Force[3] = "";
    char Dexterite[5] = "";
    char Constitution[5] = "";
    char Intelligence[5] = "";
    char Sagesse[5] = "";
    char Charisme[5] = "";
    
    char tauxdecritique2 [6] = "";
    char precision [6] = "";
    char attphysique [15] = "";
    char attmagique [15] = "";
    char attcritique [15] = "";
    
    char blocage [6] = "";
    char defphysique [6] = "";
    char defmagique [6] = "";
    char esquive [6] = "";
    
    sprintf(level, "%d", niveau);
    sprintf(PV, "%d / %d HP", pointdevierestant, pointdevie);
    sprintf(MANA, "%d / %d MP", manarestant, mana);
    
    sprintf(Force, "%d", force);
    sprintf(Dexterite, "%d", dexterite);
    sprintf(Constitution, "%d", constitution);
    sprintf(Intelligence, "%d", intelligence);
    sprintf(Sagesse, "%d", sagesse);
    sprintf(Charisme, "%d", charisme);
    
    sprintf(tauxdecritique2, "%d %%", TauxDeCritique);
    sprintf(precision, "%d %%", Precision);
    sprintf(attphysique, "%d - %d", AttPhyMin, AttPhyMax);
    sprintf(attmagique, "%d - %d", AttMagMin, AttMagMax);
    sprintf(attcritique, "%d - %d", DegMinCri, DegMaxCri);
    
    sprintf(Experience, "%d / %d XP", experience, experienceUp);
    sprintf(blocage, "%d %%", Blocage);
    sprintf(defphysique, "%d", DefPhy);
    sprintf(defmagique, "%d", DefMag);
    sprintf(esquive, "%d", Esquive);
    
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 15);
    SDL_Color couleurBlanche = {255, 255, 255};
    
    affichevie = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichevie, NULL, SDL_MapRGB(ecran->format, 251, 175, 168));
    SDL_BlitSurface(affichevie, NULL , ecran, &positionVie);
    SDL_FreeSurface(affichevie);
    
    affichevie = SDL_CreateRGBSurface(SDL_HWSURFACE, barreVie, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichevie, NULL, SDL_MapRGB(ecran->format, 237, 28, 36));
    
    affichemana = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichemana, NULL, SDL_MapRGB(ecran->format, 172, 234, 247));
    SDL_BlitSurface(affichemana, NULL , ecran, &positionMana);
    SDL_FreeSurface(affichemana);
    
    affichemana = SDL_CreateRGBSurface(SDL_HWSURFACE, barreMana, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichemana, NULL, SDL_MapRGB(ecran->format, 0, 162, 232));
    
    affichexp = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichexp, NULL, SDL_MapRGB(ecran->format, 183, 223, 184));
    SDL_BlitSurface(affichexp, NULL , ecran, &positionxp);
    SDL_FreeSurface(affichexp);
    
    affichexp = SDL_CreateRGBSurface(SDL_HWSURFACE, barreExperience, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichexp, NULL, SDL_MapRGB(ecran->format, 70, 155, 72));
    
    SDL_BlitSurface(affichevie, NULL , ecran, &positionVie);
    SDL_BlitSurface(affichemana, NULL , ecran, &positionMana);
    SDL_BlitSurface(affichexp, NULL , ecran, &positionxp);
    SDL_FreeSurface(affichevie);
    SDL_FreeSurface(affichemana);
    SDL_FreeSurface(affichexp);
    
    texte = TTF_RenderText_Blended(police, PV, couleurBlanche);
    positionTexte.x = 50;
    positionTexte.y = 225;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, MANA, couleurBlanche);
    positionTexte.x = tailleecranL - 250;
    positionTexte.y = 225;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, Experience, couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 - 100;
    positionTexte.y = 225;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police); 

    police = TTF_OpenFont("texte/cambria.ttc", 17);
    texte = TTF_RenderText_Blended(police, "Force", couleurBlanche);
    positionTexte.x = 50;
    positionTexte.y = 285;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, Force, couleurBlanche);
    positionTexte.x = 200;
    positionTexte.y = 285;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Dexterite", couleurBlanche);
    positionTexte.x = 50;
    positionTexte.y = 310;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, Dexterite, couleurBlanche);
    positionTexte.x = 200;
    positionTexte.y = 310;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Constitution", couleurBlanche);
    positionTexte.x = 50;
    positionTexte.y = 335;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, Constitution, couleurBlanche);
    positionTexte.x = 200;
    positionTexte.y = 335;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);

    texte = TTF_RenderText_Blended(police, "Intelligence", couleurBlanche);
    positionTexte.x = 50;
    positionTexte.y = 360;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, Intelligence, couleurBlanche);
    positionTexte.x = 200;
    positionTexte.y = 360;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Sagesse", couleurBlanche);
    positionTexte.x = 50;
    positionTexte.y = 385;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, Sagesse, couleurBlanche);
    positionTexte.x = 200;
    positionTexte.y = 385;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Charisme", couleurBlanche);
    positionTexte.x = 50;
    positionTexte.y = 410;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, Charisme, couleurBlanche);
    positionTexte.x = 200;
    positionTexte.y = 410;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
  
    texte = TTF_RenderText_Blended(police, "Att. Physique", couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 - 100;
    positionTexte.y = 285;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, attphysique, couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 + 50;
    positionTexte.y = 285;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Att. Magique", couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 - 100;
    positionTexte.y = 310;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, attmagique, couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 + 50;
    positionTexte.y = 310;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Précision", couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 - 100;
    positionTexte.y = 335;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, precision, couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 + 50;
    positionTexte.y = 335;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);

    texte = TTF_RenderText_Blended(police, "Taux de Critique", couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 - 100;
    positionTexte.y = 360;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, tauxdecritique2, couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 + 50;
    positionTexte.y = 360;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Dégats Critique", couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 - 100;
    positionTexte.y = 385;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, attcritique, couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 + 50;
    positionTexte.y = 385;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Vitesse d'attaque : moyenne", couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 -100;
    positionTexte.y = 410;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte); 
    
    texte = TTF_RenderText_Blended(police, "Def. Physique", couleurBlanche);
    positionTexte.x = tailleecranL - 250;
    positionTexte.y = 285;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, defphysique, couleurBlanche);
    positionTexte.x = tailleecranL - 100;
    positionTexte.y = 285;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Def. Magique", couleurBlanche);
    positionTexte.x = tailleecranL - 250;
    positionTexte.y = 310;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, defmagique, couleurBlanche);
    positionTexte.x = tailleecranL - 100;
    positionTexte.y = 310;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Esquive", couleurBlanche);
    positionTexte.x = tailleecranL - 250;
    positionTexte.y = 335;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, esquive, couleurBlanche);
    positionTexte.x = tailleecranL - 100;
    positionTexte.y = 335;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);

    texte = TTF_RenderText_Blended(police, "Blocage", couleurBlanche);
    positionTexte.x = tailleecranL - 250;
    positionTexte.y = 360;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, blocage, couleurBlanche);
    positionTexte.x = tailleecranL - 100;
    positionTexte.y = 360;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    TTF_CloseFont(police); 
      
    police = TTF_OpenFont("texte/cambria.ttc", 17);
    texte = TTF_RenderText_Blended(police, "Niveau", couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 - 37;
    positionTexte.y = 50;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, level, couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 +18;
    positionTexte.y = 50;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);

    
    police = TTF_OpenFont("texte/cambria.ttc", 35);
    texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 - 50;
    positionTexte.y = 15;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    TTF_CloseFont(police);
    police = TTF_OpenFont("texte/cambria.ttc", 15);
    texte = TTF_RenderText_Blended(police, "Appuyez sur Entrer", couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 - 60;
    positionTexte.y = tailleecranl - 25;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
}
