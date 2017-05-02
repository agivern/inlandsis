int  force, dexterite, constitution, intelligence, sagesse, charisme;

int experience, experienceUp, niveau, experienceavantUp;

int pointdevie, pointdevierestant, mana, manarestant;

int variablevent, or;

int vitesseattaque;

char zone[50];

int positionx[10], positiony[10], EmplacementMap;

int Precision, TauxDeCritique, AttPhyMin, AttPhyMax, AttMagMin, AttMagMax, DegMinCri, DegMaxCri;
int Esquive, Blocage, DefMag, DefPhy;

int tailleecranL, tailleecranl, nombreMonstre;
int clipvarie;

struct objet
{
    int nombre;
    char nom [25];
    int posi;
}Objets[10], Resources[10], magies[25], expertises[25], techniques[25];

struct Quete
{
    int active;
}NumDeQuete[6];

struct Reputation
{
    int valeur;
}Dieu[6];

int abestirevariable[25];
int pointaatribuer;

struct Arme
{
    int nombre;
    char nom [25];
    int posi;
    int DegatMin;
    int DegatMax;
    int DegatMagMin;
    int DegatMagMax;
    int durabilite;
    int durabiliteRestante;
    int prix;
    int vitesse;
}Epee[10];

struct Armure
{
    int nombre;
    char nom [25];
    int posi;
    int DefPhy;
    int DefMag;
    int durabilite;
    int durabiliteRestante;
    int prix;
}Armures[10];

struct EquipeA
{
    char nom [25];
    int DefPhy;
    int DefMag;
    int durabilite;
    int durabiliteRestante;
    int prix;
}armure[1];

struct Equipe
{
    char nom [25];
    int DegatMin;
    int DegatMax;
    int DegatMagMin;
    int DegatMagMax;
    int durabilite;
    int durabiliteRestante;
    int prix;
    int vitesse;
}arme[1];
