#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

void AffichePotion(SDL_Surface* ecran, int *continuer);
void AfficheEnergisant(SDL_Surface* ecran, int *continuer);

void AfficheHerbe(SDL_Surface* ecran, int *continuer);
void Affichecrocdeloup(SDL_Surface* ecran, int *continuer);
void Afficheboisdecerf(SDL_Surface* ecran, int *continuer);

void AfficheEpeeBois(SDL_Surface* ecran, int i);
void AfficheEquipe(SDL_Surface* ecran, int i, int *continuer);

void AfficheArmure(SDL_Surface* ecran, int i);
void AfficheEquipeA(SDL_Surface* ecran, int i, int *continuer);
