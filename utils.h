#ifndef _UTILS_H
#define _UTILS_H

#include <sdl/sdl.h>
#include "sauve.h"

#pragma comment (lib,"sdl.lib")      // ignorez ces lignes si vous ne linkez pas les libs de cette façon.
#pragma comment (lib,"sdlmain.lib")

typedef struct
{
	char key[SDLK_LAST];
} Input;

void UpdateEvents(Input* in, int *x, int **continuer2, SDL_Surface *ecran);
void ecranmenu(SDL_Surface *ecran, int *x, int **continuer);
SDL_Surface* LoadImage32(const char* fichier_image,int vram);
Uint32 GetPixel32(SDL_Surface* image,int i,int j);
#endif
