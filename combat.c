#include "combat.h"
#include "variable.h"
#include <string.h>

void combat(SDL_Surface* ecran, int** continuer2, int levelMonstre)
{
    SDL_Surface *texte = NULL;
    SDL_Rect position, positionT;
    
    SDL_Event event;
    
    int x = 1, tempsPrecedent = 0, tempsActuel = 0, tempsPrecedent1 = 0;
    int tempsjoueur = 0, fuite = 0, pointdeviemobrestanttotal = 0;
    char pv[3] = "";
    
    ChoixMonstre(levelMonstre, &monstre1, nomMonstre1);
    pointdeviemobrestanttotal += monstre1.pointdevierestant;
    monstre1.tempsmob = (rand() % (100) + 1);
    if ( nombreMonstre > 1)
        {ChoixMonstre(levelMonstre, &monstre2, nomMonstre2);
        pointdeviemobrestanttotal += monstre2.pointdevierestant;
        monstre2.tempsmob = (rand() % (100) + 1);}
    if ( nombreMonstre > 2)
        {ChoixMonstre(levelMonstre, &monstre3, nomMonstre3);
        pointdeviemobrestanttotal += monstre3.pointdevierestant;
        monstre3.tempsmob = (rand() % (100) + 1);}
    
    tempsjoueur = (rand() % (vitesseattaque) + 1);
    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    afficheVie(ecran, 0);
    SDL_Flip(ecran);
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleecranL, 3, 32, 0, 0,0, 0);
    SDL_FillRect(texte, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    
    position.x = 0;
    position.y = tailleecranL / 2;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    srand(time(NULL));
    
    while ( pointdevierestant > 0 & x != 0 & fuite != 1 & pointdeviemobrestanttotal > 0 )
    {
        SDL_PollEvent(&event);     
        switch(event.type)
        {
            case SDL_QUIT:
                {**continuer2 = 0;
                x = 0;}
                break;
        }
           
        tempsActuel = SDL_GetTicks();
        
        if (tempsActuel - tempsPrecedent > 50)
        {
            tempsjoueur++;
            monstre1.tempsmob ++;
            if (nombreMonstre > 1)
                monstre2.tempsmob ++;
            if (nombreMonstre > 2)
                monstre3.tempsmob ++;
                
            afficheVie (ecran, tempsjoueur);
            SDL_Flip(ecran);
            
            if (monstre1.tempsmob > 200 & monstre1.pointdevierestant > 0)
            {
                attaqueMob(ecran, tempsjoueur, monstre1);
                monstre1.tempsmob = 0;
            }
            
            if (nombreMonstre > 1)
            {if (monstre2.tempsmob > 200 & monstre2.pointdevierestant > 0)
            {
                attaqueMob(ecran, tempsjoueur, monstre2);
                monstre2.tempsmob = 0;
            }}
            
            if (nombreMonstre > 2)
            {if (monstre3.tempsmob > 200 & monstre3.pointdevierestant > 0)
            {
                attaqueMob(ecran, tempsjoueur, monstre3);
                monstre3.tempsmob = 0;
            }}
            
            if (tempsjoueur > vitesseattaque)
            {
                 attaqueJoueur(ecran, &fuite, &pointdeviemobrestanttotal, &continuer2);
                 tempsjoueur = 0;
            }
            tempsPrecedent = tempsActuel;
        }

        else
        {
            SDL_Delay(50 - (tempsActuel - tempsPrecedent));
        }  
           
        SDL_Flip (ecran);
                
    }
    
    if (pointdevierestant > 0 & fuite != 1)
        victoire (ecran, &continuer2);
        
    else if (pointdevierestant > 0 & fuite == 1)
        Fuite (ecran, &continuer2);
        
    else
        defaite (ecran);
}


void afficheVie(SDL_Surface *ecran, int tempsmob)
{
    SDL_Surface *texte = NULL, *affichevie2 = NULL, *affichemana = NULL, *affichetempsjoueur = NULL, *affichetempsmob = NULL;
    SDL_Rect position, positionMana, positionVie, positionjoueur, positionmob;
    
    TTF_Font *police = NULL;
    police = TTF_OpenFont("texte/cambriai.ttf", 17);
    SDL_Color couleurBlanche = {255, 255, 255};
    
    if (tailleecranL == 800)
        texte = IMG_Load("images/combat/plaine800.bmp");
    else if (tailleecranL == 1152)
        texte = IMG_Load("images/combat/plaine1152.bmp");
    position.x = 0;
    position.y = 0;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    char temps[10] = "";
    int barreVie = (pointdevierestant * 200) / pointdevie;
    int barreMana = (manarestant * 200) / mana;
    int barretempsJ = (tempsmob * 200) / 100;
    
    if (barretempsJ > 200)
        barretempsJ = 200;
           
    positionVie.x = tailleecranL - 250;
    positionVie.y = tailleecranL / 2 + 65;
    
    positionMana.x = tailleecranL - 250;
    positionMana.y = tailleecranL / 2 + 93;
    
    positionjoueur.x = tailleecranL - 250;
    positionjoueur.y = tailleecranL / 2 + 101;
    
    texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 80, 32, 0, 0, 0, 0);
    position.x = tailleecranL - 250;
    position.y = positionVie.y - 51;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    affichevie2 = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichevie2, NULL, SDL_MapRGB(ecran->format, 251, 175, 168));
    SDL_BlitSurface(affichevie2, NULL , ecran, &positionVie);
    SDL_FreeSurface (affichevie2);
    
    affichevie2 = SDL_CreateRGBSurface(SDL_HWSURFACE, barreVie, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichevie2, NULL, SDL_MapRGB(ecran->format, 237, 28, 36));
    
    affichemana = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichemana, NULL, SDL_MapRGB(ecran->format, 172, 234, 247));
    SDL_BlitSurface(affichemana, NULL , ecran, &positionMana);
    SDL_FreeSurface (affichemana);
    
    affichemana = SDL_CreateRGBSurface(SDL_HWSURFACE, barreMana, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichemana, NULL, SDL_MapRGB(ecran->format, 0, 162, 232));
    
    affichetempsjoueur = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichetempsjoueur, NULL, SDL_MapRGB(ecran->format, 70, 155, 72));
    SDL_BlitSurface(affichetempsjoueur, NULL , ecran, &positionjoueur);
    SDL_FreeSurface(affichetempsjoueur);
        
    affichetempsjoueur = SDL_CreateRGBSurface(SDL_HWSURFACE, barretempsJ, 4, 32, 0, 0, 0, 0);
    SDL_FillRect(affichetempsjoueur, NULL, SDL_MapRGB(ecran->format, 183, 223, 184));
    positionjoueur.x = tailleecranL - 50 - barretempsJ;
    
    SDL_BlitSurface(affichetempsjoueur, NULL , ecran, &positionjoueur);
    SDL_BlitSurface(affichevie2, NULL , ecran, &positionVie);
    SDL_BlitSurface(affichemana, NULL , ecran, &positionMana);
    SDL_FreeSurface(affichetempsjoueur);
    SDL_FreeSurface(affichemana);
    SDL_FreeSurface(affichevie2);
    
    sprintf(temps, "%d/%d HP", pointdevierestant, pointdevie);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    position.x = tailleecranL - 250;
    position.y = positionVie.y - 20;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    
    sprintf(temps, "%d/%d MP", manarestant, mana);
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
    position.x = tailleecranL - 250;
    position.y = positionVie.y + 8;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
    
    police = TTF_OpenFont("texte/cambriai.ttf", 25);
    texte = TTF_RenderText_Blended(police, "Keithy", couleurBlanche);
    position.x = tailleecranL - 250;
    position.y = positionVie.y - 50;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
    
    if ( monstre1.pointdevierestant > 0)
    {
        position.x = 350;
        position.y = tailleecranL / 5;
        SDL_BlitSurface(monstre1.imageMob, NULL, ecran, &position);
    }

    if (nombreMonstre > 1 & monstre2.pointdevierestant > 0)
    {
        position.x = 200;
        position.y = tailleecranL / 4;
        SDL_BlitSurface(monstre2.imageMob, NULL, ecran, &position);
    }

    if (nombreMonstre == 3 & monstre3.pointdevierestant > 0)
    {
        position.x = 50;
        position.y = tailleecranL / 3;
        SDL_BlitSurface(monstre3.imageMob, NULL, ecran, &position);
    }
}
  

void victoire(SDL_Surface *ecran, int ***continuer)
{
    SDL_Surface *texte= NULL;
    SDL_Rect positionTexte;
    
    SDL_Event event;
    
    TTF_Font *police = NULL;
    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    
    int tempsPrecedent = 0, tempsActuel = 0;
    
   	int x = 1, experiencegagne;
    
    char ecriture [50]= "";
    
    if (nombreMonstre == 1)
    {
        experience += experiencegagne = monstre1.experience;
        Resources[monstre1.nomObjet].nombre += (rand() % (2));
    }
    
    else if (nombreMonstre == 2)
    {
        experience += experiencegagne = monstre1.experience + monstre2.experience;
        Resources[monstre1.nomObjet].nombre += (rand() % (2));
        Resources[monstre2.nomObjet].nombre += (rand() % (2));
    }
    
    else
    {
        experience += experiencegagne = monstre1.experience + monstre2.experience + monstre3.experience;
        Resources[monstre1.nomObjet].nombre += (rand() % (2));
        Resources[monstre2.nomObjet].nombre += (rand() % (2));
        Resources[monstre3.nomObjet].nombre += (rand() % (2));
    }

    if (experience >= experienceUp)
    {
        niveau++;
        pointaatribuer ++;
        experienceavantUp = experienceUp;
        experience = experience - experienceavantUp;
        experienceUp = 100 * niveau + experienceavantUp;
    }
    
    SDL_Color couleurBlanche = {255, 255, 255};
    
    police = TTF_OpenFont("texte/cambria.ttc", 50);
    texte = TTF_RenderText_Blended(police, "Vous avez gagné !", couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 - 175;
    positionTexte.y = 50;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
        
    police = TTF_OpenFont("texte/cambria.ttc", 25);
    sprintf(ecriture, "Vous avez gagné : %d points d'expérience", experiencegagne);
    texte = TTF_RenderText_Blended(police, ecriture, couleurBlanche);
    positionTexte.x = 50;
    positionTexte.y = 150;
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
    
    SDL_Flip (ecran);
    
    do
    { 
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);
        
        if (tempsActuel - tempsPrecedent > 30)	
        switch(event.type)
        {
            case SDL_QUIT:
                {
                    ***continuer = 0;
                    x = 0;
                    break;
                }
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_RETURN:
                         x = 0;
                    break;
                }break;
                
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
        
    }while (x != 0 & **continuer != 0 );
}





void Fuite (SDL_Surface *ecran, int ***continuer)
{
    SDL_Surface *texte= NULL;
    SDL_Rect positionTexte;
    
    SDL_Event event;
    
    TTF_Font *police = NULL;
    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    
    int tempsPrecedent = 0, tempsActuel = 0;
    
   	int x = 1, experiencegagne;
    
    char ecriture [25]= "";
    
    if (nombreMonstre == 2)
    {
        if (monstre1.pointdevierestant <= 0)
            {experience += monstre1.experience;
            experiencegagne = monstre1.experience;}
        if (monstre2.pointdevierestant <= 0)
             {experience += monstre2.experience;
             experiencegagne = monstre1.experience;}
    }
    
    if (nombreMonstre == 3)
    {
        if (monstre1.pointdevierestant <= 0)
            {experience += monstre1.experience;
            experiencegagne = monstre1.experience;}
        if (monstre2.pointdevierestant <= 0) 
             {experience += monstre2.experience;
             experiencegagne = monstre2.experience;}
        if (monstre3.pointdevierestant <= 0)
             {experience += monstre3.experience;
             experiencegagne = monstre3.experience;}
    }
        
    if (experience >= experienceUp)
    {
        niveau++;
        experienceavantUp = experienceUp;
        experience = experience - experienceavantUp;
        experienceUp = 100 * niveau + experienceavantUp;
    }
    
    SDL_Color couleurBlanche = {255, 255, 255};
    
    police = TTF_OpenFont("texte/cambria.ttc", 50);
    texte = TTF_RenderText_Blended(police, "Vous avez fuit !", couleurBlanche);
    positionTexte.x = tailleecranL - tailleecranL / 2 - 160;
    positionTexte.y = 50;
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
        
    police = TTF_OpenFont("texte/cambria.ttc", 25);
    sprintf(ecriture, "Vous avez gagné : %d", experiencegagne);
    texte = TTF_RenderText_Blended(police, ecriture, couleurBlanche);
    positionTexte.x = 50;
    positionTexte.y = 150;
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
    
    SDL_Flip (ecran);
    
    do
    { 
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);
        
        if (tempsActuel - tempsPrecedent > 30)	
        switch(event.type)
        {
            case SDL_QUIT:
                {
                    ***continuer = 0;
                    x = 0;
                    break;
                }
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_RETURN:
                         x = 0;
                    break;
                }break;
                
            tempsPrecedent = tempsActuel;
        }
        
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }
        
    }while (x != 0 & **continuer != 0 );
}




void defaite(SDL_Surface *ecran)
{
     
}
