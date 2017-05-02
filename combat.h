#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

void combat(SDL_Surface* ecran, int** continuer2, int levelMonstre);
void victoire (SDL_Surface *ecran, int ***continuer);
void Fuite (SDL_Surface *ecran, int ***continuer);
void defaite (SDL_Surface *ecran);
void attaqueJoueur(SDL_Surface* ecran, int *fuite2, int *pointdevieMob, int ***continuer3);
void afficheVie(SDL_Surface *ecran, int tempsmob); 
char nomMonstre1 [50], nomMonstre2 [50], nomMonstre3 [50];

struct Stat
{
    int force;
    int dexterite;
    int constitution;
    int intelligence;
    int sagesse;
    int charisme;
    int Precision;
    int TauxDeCritique;
    int Esquive;
    int Blocage;
    int DefMag;
    int DefPhy;
    int pointdevie;
    int pointdevierestant;
    int AttPhyMin;
    int AttPhyMax;
    int DegMinCri;
    int DegMaxCri;
    int experience;
    int tempsmob;
    int nomObjet;
    SDL_Surface *imageMob;
};

struct Stat monstre1;
struct Stat monstre2;
struct Stat monstre3;
void ChoixMonstre(int levelMonstre, struct Stat* monstre2, char *nomMonstre);
void attaqueMob(SDL_Surface* ecran, int tempsjoueur, struct Stat monstre2);
void destruction(SDL_Surface* ecran, struct Stat* monstre2, int mobselectionne);
void evenementrate(SDL_Surface* ecran, int mobselectionne);
void evenementtouche(SDL_Surface* ecran, int mobselectionne, int degat);
//void utiliseobjet(SDL_Surface* ecran, int *choice, int *x, int *continuer, int *fairetantque)
//void utilisemagie(SDL_Surface* ecran, int *choice, int *x, int *continuer, int *fairetantque)
