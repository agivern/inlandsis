#ifndef _FMAP_H
#define _FMAP_H

#include "utils.h"

typedef struct
{
	SDL_Rect R;
	char mur;
	// tout ce que vous voulez...

} TileProp;


typedef struct
{
	int nclip;
	int cpt;
	int x;
	int y;
	int w;
	int h;
} AffObjet;

typedef struct
{
	int LARGEUR_TILE,HAUTEUR_TILE;
	int nbtiles;
	TileProp* props;
	SDL_Surface* tileset;
	unsigned char** schema;
	int nbtiles_largeur_monde,nbtiles_hauteur_monde;
	int xscroll,yscroll;
	int largeur_fenetre,hauteur_fenetre;
} Map;

Map* ChargerMap(const char* tileset,const char* image_schema,const char* image_corr,const char* tileprop,
				int largeur_tile,int hauteur_tile,int largeur_fenetre,int hauteur_fen);
int AfficherMap(Map* m,SDL_Surface* screen);
void LibererMap(Map* m);
int CollisionDecor(Map* carte,SDL_Rect* perso);
int FocusScrollCenter(Map* carte,SDL_Rect* perso);
int FocusScrollBox(Map* carte,SDL_Rect* perso,SDL_Rect* limit);
int collisionPNJ (SDL_Rect* perso, SDL_Rect* pnj);
int testvitesse, testdepla;
#endif
