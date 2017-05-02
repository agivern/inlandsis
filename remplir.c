#include "demarage.h"
void remplir (SDL_Surface* ecran)
{
     SDL_Surface *texte2= NULL;
     SDL_Rect positionTexte2;
     
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambria.ttc", 15);
    SDL_Color couleurNoire = {0, 0, 0};

    texte2 = TTF_RenderText_Blended(police, "NOUVELLE PARTIE", couleurNoire);
    positionTexte2.x = 350;
    positionTexte2.y = 362;
    SDL_BlitSurface(texte2, NULL, ecran, &positionTexte2);
    
    texte2 = TTF_RenderText_Blended(police, "CONTINUER", couleurNoire);
    positionTexte2.x = 370;
    positionTexte2.y = 406;
    SDL_BlitSurface(texte2, NULL, ecran, &positionTexte2);
    
    texte2 = TTF_RenderText_Blended(police, "QUITTER", couleurNoire);
    positionTexte2.x = 378;
    positionTexte2.y = 451;
    SDL_BlitSurface(texte2, NULL, ecran, &positionTexte2);
    
    SDL_FreeSurface(texte2);
    
    TTF_CloseFont(police); 
}
