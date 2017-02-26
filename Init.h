#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include <windows.h>
#include <string>
#include <time.h>
#include "SDL.h"
#include <SDL_ttf.h>
#include <stdio.h>
#include <Declaration.h>
#include <dirent.h>

char* afficheBool (bool a)
{
if (a) return "true";
else return "false";
}

void InitTexteHCD() // HDC => HelpClicDroit
{
int i=0;
for(i=0;i<8;i++)
{
  strcpy(TexteHCD[i]," ");
}

}
void InitUneCase(int i, int i2)
{
         grille[i][i2].animation=0;
         grille[i][i2].collision=1;
         grille[i][i2].type=-1;
         grille[i][i2].optionT.Angle=0;
         grille[i][i2].optionT.Couleur.R=0;
         grille[i][i2].optionT.Couleur.V=0;
         grille[i][i2].optionT.Couleur.B=0;
         grille[i][i2].optionT.Direction=0;
         grille[i][i2].optionT.Fixe_Etat=0;
         grille[i][i2].optionT.Intensite_Bougeable=0;
         grille[i][i2].optionT.optionType=0;
         grille[i][i2].optionT.visible=1;
         grille[i][i2].AuDessus=0;
         grille[i][i2].optionT.HerbeHaute=0;
         strcpy(grille[i][i2].optionT.sprite,"");
}
void InitGrille()
{
    for(int i=0;i<MAPMAX;i++)
    {
        for(int i2=0;i2<MAPMAX;i2++)
        {
         InitUneCase(i,i2);
        }
    }
}


int InitSDL()   // Lancement de L'affichage, Création du rendu,etc..
{
InitGrille();
InitTexteHCD();
case_actuelle.x=0;
case_actuelle.y=0;

Noir_HautGauche.x=251;
Noir_HautGauche.y=26;

for(int i=0;i<MAPMAX;i++){for(int i2=0;i2<MAPMAX;i2++){grille[i][i2].optionT.sprite[0]='\0';}}
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
        /* Création de la fenêtre */

       pWindow = SDL_CreateWindow("2D ENGINE",100, 100,
                                                                  1366,
                                                                  768,
                                                                  SDL_WINDOW_SHOWN | SDL_RENDERER_PRESENTVSYNC);

renderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);

TTF_Init();
Temps_Fin_Tour = SDL_GetTicks();
if(!(pWindow)){fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());}
return 0;
}

void FinSDL(void)   // Fonction de Fin du logiciel.
{
SDL_DestroyWindow(pWindow);
pWindow=0;
TTF_Quit();
SDL_Quit();
}

#include <LireImage.h>
#include <Affichage.h>
#include <Packing.h>
#include <Event.h>

