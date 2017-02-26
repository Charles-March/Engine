void affichetexte(char* text,int x, int y, int Taille, char* policeN,SDL_Color Color)
{
int w=0,h=0;
SDL_Surface *Surface=NULL;
SDL_Texture *texture=NULL;
tempT.x=x;
tempT.y=y;
police=TTF_OpenFont(policeN,Taille);

if((police!=NULL)&&(text!=NULL)){

Surface=TTF_RenderText_Blended(police,text,Color);
texture = SDL_CreateTextureFromSurface(renderer,Surface);
SDL_QueryTexture(texture,NULL,NULL,&w,&h);
tempT.w=w;tempT.h=h;
SDL_RenderCopy(renderer,texture,NULL,&tempT);
                                }
free(&w);
free(&h);
TTF_CloseFont(police);
SDL_DestroyTexture(texture);
SDL_FreeSurface(Surface);
}

void afficherBoutonMenu()   // Les textes des sous menus.
{
    affichetexte("File",26,4,15,"Arial.ttf",noire);
    rectangleVide(0,0,75,25,noire);
    if ((Mx >= 0 && Mx < 75) && (My >= 0 && My < 25))
        rectangleVide(1,1,73,23,noire);

    affichetexte("Options",86,4,15,"Arial.ttf",noire);
    rectangleVide(75,0,75,25,noire);
    if((Mx >= 75 && Mx < 150) && (My >= 0 && My < 25))
        rectangleVide(76,1,73,23,noire);

    affichetexte("RUN",103,741,20,"Arial.ttf",noire);
    rectangleVide(0,738,250,30,noire);
    if((Mx >= 0 && Mx < 250) && (My >= 738 && My < 768))
        rectangleVide(1,739,248,28,noire);
}

void afficherBoutonFile()   // Les Sous menu.
{
    affichetexte("New",16,28,14,"Arial.ttf",noire);
    if((Mx >= 0 && Mx < 100) && (My >= 26 && My <46))
        rectangleVide(11,26,89,20,noire);

    affichetexte("Open",16,48,14,"Arial.ttf",noire);
    if((Mx >= 0 && Mx < 100) && (My >= 46 && My <66))
        rectangleVide(11,46,89,20,noire);

    affichetexte("Save",16,68,14,"Arial.ttf",noire);
    if((Mx >= 0 && Mx < 100) && (My >= 66 && My <86))
        rectangleVide(11,66,89,20,noire);

    affichetexte("Save as...",16,88,14,"Arial.ttf", noire);
    if((Mx >= 0 && Mx < 100) && (My >= 86 && My <106))
        rectangleVide(11,86,89,20,noire);

    affichetexte("Quit",16,108,14,"Arial.ttf",noire);
    if((Mx >= 0 && Mx < 100) && (My >= 106 && My <126))
        rectangleVide(11,106,89,20,noire);
}

void afficherZoneBouton()   // Les menus.
{
    if(sourisClic == 1)
    {
        rectanglePlein(1,26,100,100,blanc);
        rectangleVide(1,26,100,100,noire);
        rectangleVide(10,26,1,100,noire);
        afficherBoutonFile();
    }

    if(sourisClic == 2)
    {
        //affiche("bouton_options_souris",150,0);
    }
}

void afficheInterface() //affiche les Cadres des menus, etc..
{
    rectanglePlein(0,0,1366,25,blanc); //menu
    rectangleVide(0,0,1366,25,noire); //contour menu
    rectanglePlein(0,25,250,500,blanc); //liste
    rectangleVide(0,25,250,500,noire); //contour liste
    rectanglePlein(0,525,250,213,blanc); //objet
    rectangleVide(0,525,250,213,noire); //objet contour
    rectanglePlein(0,738,250,30,blanc); //test
    rectangleVide(0,738,250,30,noire); //test contour
    afficherBoutonMenu();
}

void afficheIPS() // Fonction qui écrit les IPS
{
char bonsoir[50]="";
sprintf(bonsoir,"2D Engine, IPS : %f",1000/(Temps_Debut_Tour+Temps_Tour));
SDL_SetWindowTitle(pWindow,bonsoir);
free(bonsoir);
}


//cadre noir : En HG :  x : 250
//                      y : 25

void OMG()          // affiche les Images sur la Map.
{
for(int i=case_actuelle.x;i<=case_actuelle.x+33;i++)
    {
        for(int i2=case_actuelle.y;i2<=case_actuelle.y+22;i2++)
        {
            if(grille[i][i2].type!=-1)  {

            if (grille[i][i2].optionT.visible==0)
            {afficheAvecTransparence(grille[i][i2].optionT.sprite,(i-case_actuelle.x)*32+250,(i2-case_actuelle.y)*32+25,63);}
            else
            {affiche(grille[i][i2].optionT.sprite,(i-case_actuelle.x)*32+250,(i2-case_actuelle.y)*32+25);}
                if(grille[i][i2].collision==1 && grille[i][i2].type==0)
                    {
                        rectangleVide((i-case_actuelle.x)*32+250,(i2-case_actuelle.y)*32+25,32,32,vert);
                    }
                                        }
        }
    }
rectangleVide(0,0,0,0,noire);
}

void helpCD (int x,int y)   // Gére les String lors du clic droit.
{
if(x==-1 && y==-1){
Xhelp=(Mx-250)/32 + case_actuelle.x;
Yhelp=(My - 25)/32 + case_actuelle.y;
}
else
{
Xhelp=x;
Yhelp=y;
}
InitTexteHCD();
           switch (grille[Xhelp][Yhelp].type)
            {
                case -1:
                    sprintf(TexteHCD[0],"Case Vide (%i , %i)",Xhelp,Yhelp);
                break;

                case 0:
                    sprintf(TexteHCD[0],"Type Image (%i , %i)",Xhelp,Yhelp);

                    if(grille[Xhelp][Yhelp].optionT.Fixe_Etat==0)
                    {sprintf(TexteHCD[1],"Etat : Solide");}
                    else if(grille[Xhelp][Yhelp].optionT.Fixe_Etat==1)
                    {sprintf(TexteHCD[1],"Etat : Liquide");}
                    else if(grille[Xhelp][Yhelp].optionT.Fixe_Etat==2)
                    {sprintf(TexteHCD[1],"Etat : Echelle");}
                    else if(grille[Xhelp][Yhelp].optionT.Fixe_Etat==3)
                    {sprintf(TexteHCD[1],"Etat : PNJ Script");}
                    else if(grille[Xhelp][Yhelp].optionT.Fixe_Etat==4)
                    {sprintf(TexteHCD[1],"Etat : PNJ Mouvement Random");}

                    sprintf(TexteHCD[2],"Bougeable : %s ",afficheBool(grille[Xhelp][Yhelp].optionT.Intensite_Bougeable));

                    sprintf(TexteHCD[3],"Image : %s",grille[Xhelp][Yhelp].optionT.sprite);

                    sprintf(TexteHCD[4],"Collision : %s ",afficheBool(grille[Xhelp][Yhelp].collision));

                    sprintf(TexteHCD[5],"Animé : %s ",afficheBool(grille[Xhelp][Yhelp].animation));

                    sprintf(TexteHCD[6],"Visible : %s ",afficheBool(grille[Xhelp][Yhelp].optionT.visible));

                    sprintf(TexteHCD[7],"Au Dessus : %s",afficheBool(grille[Xhelp][Yhelp].AuDessus));

                    sprintf(TexteHCD[8],"'Herbe haute' : %s",afficheBool(grille[Xhelp][Yhelp].optionT.HerbeHaute));
                break;

                case 1:
                sprintf(TexteHCD[0],"Type Light (%i , %i)",Xhelp,Yhelp);

                sprintf(TexteHCD[1],"Fixe : %s ",afficheBool(grille[Xhelp][Yhelp].optionT.Fixe_Etat));

                sprintf(TexteHCD[2],"Intensité : %i ",grille[Xhelp][Yhelp].optionT.Intensite_Bougeable);

                sprintf(TexteHCD[3],"Couleur : (%i,%i,%i) ",grille[Xhelp][Yhelp].optionT.Couleur.R,grille[Xhelp][Yhelp].optionT.Couleur.V,grille[Xhelp][Yhelp].optionT.Couleur.B);

                sprintf(TexteHCD[4],"Direction : %f ",grille[Xhelp][Yhelp].optionT.Direction);

                sprintf(TexteHCD[5],"Angle : %f ",grille[Xhelp][Yhelp].optionT.Angle);

                sprintf(TexteHCD[6],"Collision : %s ",afficheBool(grille[Xhelp][Yhelp].collision));

                sprintf(TexteHCD[7],"Animé : %s ", afficheBool(grille[Xhelp][Yhelp].animation));

                break;
            }


}


void AfficheHelpCD (void) //Affiche L'aide lors d'un clic droit
{
int i;
for(i=0;i<8;i++)
    {
    if(i==0){affichetexte(TexteHCD[i],65,535,14,"Arial.ttf",noire);}
    else {affichetexte(TexteHCD[i],5,535+i*20,14,"Arial.ttf",noire); }
    }

}

void TF1()
{
afficheInterface();
AfficheHelpCD();
OnScreen();
OMG();
afficherZoneBouton();
//printf("VALEUR : %s\n",grille[2][5].optionT.sprite);
SDL_RenderPresent(renderer);

Temps_Tour=Temps_Fin_Tour - SDL_GetTicks();
Temps_Debut_Tour=(1000-(IPS*Temps_Tour))/IPS;
if((1000-(IPS*Temps_Tour))/IPS>0) {SDL_Delay((1000-(IPS*Temps_Tour))/IPS);}
Temps_Fin_Tour = SDL_GetTicks();
SDL_RenderClear(renderer);
afficheIPS();
compteur++;
if(compteur >2000000000) {compteur=1;}
}
