#include "variable.h"
#include "sauve.h"

void chargement (int argc, char *argv[])
{
    FILE* fichier = NULL;
    
    fichier = fopen("data/donn�.txt", "r");
 
    if (fichier != NULL)
    {
        fscanf(fichier, "%d %d", &positionx , &positiony);
        fclose(fichier);
        
    }
    
}

void sauvegarde(int argc, char *argv[])
{
    FILE* fichier = NULL;
    remove("data.txt");
    fichier = fopen("data/donn�.txt", "w");
 
    if (fichier != NULL)
    {
        fprintf(fichier, "%d %d", *positionx, *positiony);
        fclose(fichier);
    }
}
