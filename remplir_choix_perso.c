#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>

#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "jeux.h"
#include "variable.h"

void remplir_choix_perso (SDL_Surface* ecran)
{
    SDL_Surface *affichevie = NULL, *affichemana = NULL, *affichexp = NULL, *texte =NULL;
    SDL_Rect positionVie, positionMana, positionxp, positionTexte;
    
    int barreVie = (pointdevierestant * 200) / pointdevie;
    int barreMana = (manarestant * 200) / mana;
    int barreExperience = (experience * 200) / experienceUp;
    
    positionVie.x = tailleecranL - 350;
    positionVie.y = 95;
    
    positionMana.x = tailleecranL - 350;
    positionMana.y = 120;
    
    positionxp.x = tailleecranL - 350;
    positionxp.y = 145;
    
    char level[10] = "";
    char PV[15] = "";
    char MANA[15] = "";
    char OR[6] = "";
    char Experience[25] = "";
    
    sprintf(level, "Niveau %d", niveau);
    sprintf(PV, "%d/%d HP", pointdevierestant, pointdevie);
    sprintf(MANA, "%d/%d MP", manarestant, mana);
    sprintf(OR, "Or: %d", or);
    sprintf(Experience, "%d/%d XP", experience, experienceUp);
    
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 15);
    SDL_Color couleurNoire = {0, 0, 0};
    SDL_Color couleurBlanche = {255, 255, 255};
    
    affichevie = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichevie, NULL, SDL_MapRGB(ecran->format, 251, 175, 168));
    SDL_BlitSurface(affichevie, NULL , ecran, &positionVie);
    
    affichevie = SDL_CreateRGBSurface(SDL_HWSURFACE, barreVie, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichevie, NULL, SDL_MapRGB(ecran->format, 237, 28, 36));
    
    affichemana = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichemana, NULL, SDL_MapRGB(ecran->format, 172, 234, 247));
    SDL_BlitSurface(affichemana, NULL , ecran, &positionMana);
    
    affichemana = SDL_CreateRGBSurface(SDL_HWSURFACE, barreMana, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichemana, NULL, SDL_MapRGB(ecran->format, 0, 162, 232));
    
    affichexp = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichexp, NULL, SDL_MapRGB(ecran->format, 183, 223, 184));
    SDL_BlitSurface(affichexp, NULL , ecran, &positionxp);
    
    affichexp = SDL_CreateRGBSurface(SDL_HWSURFACE, barreExperience, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichexp, NULL, SDL_MapRGB(ecran->format, 70, 155, 72));
    
    SDL_BlitSurface(affichevie, NULL , ecran, &positionVie);
    SDL_BlitSurface(affichemana, NULL , ecran, &positionMana);
    SDL_BlitSurface(affichexp, NULL , ecran, &positionxp);
    
    texte = TTF_RenderText_Blended(police, PV, couleurBlanche);
    positionTexte.x = tailleecranL - 350;
    positionTexte.y = 80;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, MANA, couleurBlanche);
    positionTexte.x = tailleecranL - 350;
    positionTexte.y = 105;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, Experience, couleurBlanche);
    positionTexte.x = tailleecranL - 350;
    positionTexte.y = 130;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police); 
    
    police = TTF_OpenFont("texte/cambria.ttc", 17);
    texte = TTF_RenderText_Blended(police, level, couleurBlanche);
    positionTexte.x = tailleecranL - 244;
    positionTexte.y = 50;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, OR, couleurBlanche);
    positionTexte.x = 20;
    positionTexte.y = tailleecranl - 50;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, "Zone :", couleurBlanche);
    positionTexte.x = 20;
    positionTexte.y = tailleecranl - 25;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    texte = TTF_RenderText_Blended(police, zone, couleurBlanche);
    positionTexte.x = 70;
    positionTexte.y = tailleecranl - 25;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police); 
    
    police = TTF_OpenFont("texte/cambria.ttc", 35);
    texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
    positionTexte.x = tailleecranL - 245;
    positionTexte.y = 15;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    
    SDL_FreeSurface(affichevie);
    SDL_FreeSurface(affichemana);
    SDL_FreeSurface(affichexp);
    TTF_CloseFont(police);
}
