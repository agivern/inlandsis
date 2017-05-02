#include "combat.h"

void ChoixMonstre(int levelMonstre, struct Stat* monstre2, char *nomMonstre)
{
    int x;
    
    if (levelMonstre == 1)
    {
        x = (rand() % (3)) + 1;
        
        if (x == 1)
        {
            sprintf(nomMonstre, "Jeune Loup Sauvage");
            monstre2->force = 3;
            monstre2->dexterite = 5;
            monstre2->constitution = 3;
            monstre2->intelligence = 2;
            monstre2->sagesse = 2;
            monstre2->charisme = 1;
            monstre2->Esquive = 1;
            monstre2->DefMag = 2;
            monstre2->DefPhy = 3;
            monstre2->Blocage = 0;
            monstre2->TauxDeCritique = 2;
            monstre2->Precision = 11;
            monstre2->pointdevie = 13;
            monstre2->pointdevierestant = 13;
            monstre2->AttPhyMin = 2;
            monstre2->AttPhyMax = 5;
            monstre2->DegMinCri = 9;
            monstre2->DegMaxCri = 13;
            monstre2->experience = 12;
            monstre2->tempsmob = 0;
            monstre2->nomObjet = 1;
            monstre2->imageMob = SDL_LoadBMP("images/chara/bebe-loup.bmp");
            SDL_SetColorKey(monstre2->imageMob, SDL_SRCCOLORKEY, SDL_MapRGB(monstre2->imageMob->format, 255, 255, 255));
        }
        
        else if(x == 2)
        {
            sprintf(nomMonstre, "Jeune Cerf");
            monstre2->force = 3;
            monstre2->dexterite = 6;
            monstre2->constitution = 2;
            monstre2->intelligence = 1;
            monstre2->sagesse = 1;
            monstre2->charisme = 1;
            monstre2->Esquive = 15;
            monstre2->DefMag = 1;
            monstre2->DefPhy = 2;
            monstre2->Blocage = 0;
            monstre2->TauxDeCritique = 10;
            monstre2->Precision = 15;
            monstre2->pointdevie = 6;
            monstre2->pointdevierestant = 6;
            monstre2->AttPhyMin = 3;
            monstre2->AttPhyMax = 4;
            monstre2->DegMinCri = 10;
            monstre2->DegMaxCri = 11;
            monstre2->experience = 9;
            monstre2->tempsmob = 0;
            monstre2->nomObjet = 2;
            monstre2->imageMob = SDL_LoadBMP("images/chara/jeune-cerf.bmp");
            SDL_SetColorKey(monstre2->imageMob, SDL_SRCCOLORKEY, SDL_MapRGB(monstre2->imageMob->format, 255, 255, 255));
        }
        
        else if(x == 3)
        {
            sprintf(nomMonstre, "Chat Sauvage");
            monstre2->force = 2;
            monstre2->dexterite = 3;
            monstre2->constitution = 2;
            monstre2->intelligence = 0;
            monstre2->sagesse = 0;
            monstre2->charisme = 2;
            monstre2->Esquive = 20;
            monstre2->DefMag = 0;
            monstre2->DefPhy = 2;
            monstre2->Blocage = 0;
            monstre2->TauxDeCritique = 1;
            monstre2->Precision = 1;
            monstre2->pointdevie = 5;
            monstre2->pointdevierestant = 5;
            monstre2->AttPhyMin = 1;
            monstre2->AttPhyMax = 2;
            monstre2->DegMinCri = 4;
            monstre2->DegMaxCri = 5;
            monstre2->experience = 5;
            monstre2->tempsmob = 0;
            monstre2->nomObjet = 0;
            monstre2->imageMob = SDL_LoadBMP("images/chara/chat-sauvage.bmp");
            SDL_SetColorKey(monstre2->imageMob, SDL_SRCCOLORKEY, SDL_MapRGB(monstre2->imageMob->format, 255, 255, 255));
        }
    }
}
