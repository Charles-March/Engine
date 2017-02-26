void rectangleVide(int x, int y, int w, int h,SDL_Color Color)
{
SDL_SetRenderDrawColor(renderer,Color.r,Color.g,Color.b,Color.a);
SDL_Rect Temp;
Temp.x=x;Temp.y=y;Temp.w=w;Temp.h=h;
SDL_RenderDrawRect(renderer,&Temp);
SDL_free(&Temp);
}

void rectanglePlein(int x, int y, int w, int h,SDL_Color Color)
{
SDL_SetRenderDrawColor(renderer,Color.r,Color.g,Color.b,Color.a);
SDL_Rect Temp;
Temp.x=x;Temp.y=y;Temp.w=w;Temp.h=h;
SDL_RenderFillRect(renderer,&Temp);
SDL_free(&Temp);
}


void enleve_extension(char* texte)// Permet de supprimer l'extension d'une image (.bmp par exemple)
{
int c;
    for(int i=0;c!='\0';i++)
    {
    c=texte[i];
    if(c='.'){texte[i]='\0';break;}
    }
}

void affiche(char* name,int x,int y)    // fonction affichage principale
{
int w=0,h=0;
SDL_Texture *texture=NULL;
SDL_Surface *a=NULL;
char T[50];
sprintf(T,"%s%s",Imgpath,name);
a=SDL_LoadBMP(T);
if(!(a)){printf("ERROR %s\n",T);}
else {
SDL_SetColorKey(a, 250, SDL_MapRGB(a->format, 255, 255, 255));
texture= SDL_CreateTextureFromSurface(renderer,a);

SDL_Rect temp;
temp.x=x;
temp.y=y;
SDL_QueryTexture(texture,NULL,NULL,&w,&h);
temp.w=w;temp.h=h;
SDL_RenderCopy(renderer,texture,NULL,&temp);
SDL_free(&temp);
    }

SDL_DestroyTexture(texture);
free(&w);
free(&h);
SDL_FreeSurface(a);
free(T);

}

void afficheAvecTransparence(char* name,int x, int y, int transparence)
{
int w=0,h=0;
SDL_Texture *texture=NULL;
SDL_Surface *a=NULL;
char T[50];
sprintf(T,"%s%s",Imgpath,name);
a=SDL_LoadBMP(T);
if(!(a)){printf("ERROR %s\n",T);}
else {

SDL_SetSurfaceAlphaMod(a,transparence);

texture= SDL_CreateTextureFromSurface(renderer,a);


SDL_Rect temp;
temp.x=x;
temp.y=y;
SDL_QueryTexture(texture,NULL,NULL,&w,&h);
temp.w=w;temp.h=h;
SDL_SetTextureAlphaMod(texture,transparence);
SDL_RenderCopy(renderer,texture,NULL,&temp);
SDL_free(&temp);
    }
SDL_DestroyTexture(texture);
free(&w);
free(&h);
SDL_FreeSurface(a);
free(T);


}

void afficheEN32(char* name,int x,int y)    //permet d'afficher en 32x32 les images a gauche.
{
SDL_Texture *texture=NULL;
SDL_Surface *a=NULL;
char T[30];
SDL_Rect temp;
sprintf(T,"%s%s",Imgpath,name);
a=SDL_LoadBMP(T);
if(!(a)){printf("ERROR %s\n",T);}
else {
texture= SDL_CreateTextureFromSurface(renderer,a);
temp.x=x;
temp.y=y;
temp.w=32;temp.h=32;
SDL_RenderCopy(renderer,texture,NULL,&temp);

    }
SDL_free(&temp);
SDL_DestroyTexture(texture);
SDL_FreeSurface(a);
free(T);

}

int GetWidth(char* name,char*chemin)        // Permet de récupérer la taille d'une image.
{
SDL_Texture *OOh=NULL;
SDL_Surface *Oh=NULL;
int w,h;
char TOTO[60]="";
sprintf(TOTO,"%s%s",chemin,name);
Oh=SDL_LoadBMP(TOTO);
OOh=SDL_CreateTextureFromSurface(renderer,Oh);
SDL_QueryTexture(OOh,NULL,NULL,&w,&h);

SDL_DestroyTexture(OOh);
free(TOTO);
SDL_FreeSurface(Oh);
free(&w);
free(&h);
return w;
}

void afficheImageANEPASUTILISERDELAMORTSINONLAFIN(int x, int y,char *Path,char* rep) //Inutilisé pour le moment.
{
char chemin[60]="";
sprintf(chemin,"%s%s",rep,Path);
afficheEN32(chemin,x,y);
}

int isDir(char* s)  // rien a commenté.
{
    if ((strchr(s, '.')) == NULL) /* Si le nom du chemin n'a pas de point (une extension). */
        return 1;
    else
        return 0;
}

bool IsEmptyGrille(int x, int y) // rien a rajouté.
{
if(grille[x][y].type==-1)
    {
    return true ;
    }

        else
        {
        return false;
        }

}


void lecture_Image() // Permet de Trouver les Images dans le dossier images et récupérer les chemin dans un tableau IMG
{
XImgActuelle=5;
bool GO=TRUE;
int compt=0;
DIR *rep= NULL;
struct dirent* fichierLu = NULL;
char OK[50]="";
char chemin[500] = "";
char PathRep[20]="";
rep = opendir("./img");

        if(rep==NULL)
        {
        printf("Impossible de trouver le dossier ./img/");
        }
fichierLu =readdir(rep);
while (((fichierLu == readdir(rep))!=NULL)&&(GO==TRUE)&&(compt<NBTILEAFFICHE))
{
            if (strcmp(fichierLu->d_name, ".") != 0 && /* Si le fichier lu n'est pas . */
                strcmp(fichierLu->d_name, "..") != 0&& /*  Et n'est pas .. non plus */
                (!isDir(fichierLu->d_name)))
                    {

                    sprintf(OK,"%s",fichierLu->d_name);
                    strcpy(IMG[compt],OK);
                    printf("%s\n",IMG[compt]);
                    ImgActuelle = telldir(rep);
                    ImgActuelleI++;
                    compt++;
                    }
}


closedir(rep);
}

void OnScreen() // Affiche en 32x32 Les images du tableau IMG remplis précédemment.
{
int i;
int x=1,y=76;
    for(i=0;i<NBTILEAFFICHE;i++)
    {
        if(strcmp(IMG[i],"")!=0)
        {
        afficheEN32(IMG[i],x,y);
        rectangleVide(x,y,32,32,noire);
        if(x<216-33){x=x+34;}
        else {y=y+34;x=1;}
        }
    }


}

//cadre noir : En HG :  x : 250
//                      y : 25
//

void Metsdanslamap()    // Remplis la grille avec Les Images Stocké dans IMG remplis plus haut.
{
int x=Mx;
int y=My;
//int temp;
x=((x-250)/32)+case_actuelle.x;
y=((y-25)/32)+case_actuelle.y;
if(numImgClic!=1000)
    {
    strcpy(grille[x][y].optionT.sprite,IMG[numImgClic]);
    grille[x][y].type=0;
    printf("case %i,%i : %s\n",x,y,grille[x][y].optionT.sprite);
    }

}
