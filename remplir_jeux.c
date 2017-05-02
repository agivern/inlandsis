#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>

#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "jeux.h"
#include "variable.h"

void remplir_jeux (SDL_Surface* ecran)
{
    SDL_Surface *texte2 = NULL;
    SDL_Rect positionTexte2;
     
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 15);
    SDL_Color couleurNoire = {0, 0, 0};
     
    texte2 = TTF_RenderText_Blended(police, "OBJETS", couleurNoire);
    positionTexte2.x = 110;
    positionTexte2.y = 26;
    SDL_BlitSurface(texte2, NULL, ecran, &positionTexte2);
    SDL_FreeSurface(texte2);
    
    texte2 = TTF_RenderText_Blended(police, "EQUIPEMENT", couleurNoire);
    positionTexte2.x = 90;
    positionTexte2.y = 71;
    SDL_BlitSurface(texte2, NULL, ecran, &positionTexte2);
    SDL_FreeSurface(texte2);
    
    texte2 = TTF_RenderText_Blended(police, "MAGIE", couleurNoire);
    positionTexte2.x = 110;
    positionTexte2.y = 116;
    SDL_BlitSurface(texte2, NULL, ecran, &positionTexte2);
    SDL_FreeSurface(texte2);

    texte2 = TTF_RenderText_Blended(police, "STATUT", couleurNoire);
    positionTexte2.x = 108;
    positionTexte2.y = 161;
    SDL_BlitSurface(texte2, NULL, ecran, &positionTexte2);
    SDL_FreeSurface(texte2);
    
    texte2 = TTF_RenderText_Blended(police, "OPTION", couleurNoire);
    positionTexte2.x = 106;
    positionTexte2.y = 206;
    SDL_BlitSurface(texte2, NULL, ecran, &positionTexte2);
    SDL_FreeSurface(texte2);
    
    texte2 = TTF_RenderText_Blended(police, "SAUVEGARDER", couleurNoire);
    positionTexte2.x = 82;
    positionTexte2.y = 251;
    SDL_BlitSurface(texte2, NULL, ecran, &positionTexte2);
    SDL_FreeSurface(texte2);
    
    texte2 = TTF_RenderText_Blended(police, "RETOUR", couleurNoire);
    positionTexte2.x = 100;
    positionTexte2.y = 296;
    SDL_BlitSurface(texte2, NULL, ecran, &positionTexte2);
    SDL_FreeSurface(texte2);
    TTF_CloseFont(police); 
}
