/* (x;y;type(objet :) Etat;bougeable;          sprite                    ;Collision;Animation;visible{event...}
             (light :) Fixe;Intensité;R;V;B;          direction;angle
    0 1  2               3       4      5         6       7          8          9        10
*/
bool Estunchiffre(char c) //...
{
                   if ((c>='0')&&(c<='9'))
                    {
                    return true;
                    }
                    else
                    {
                    return false;
                    }
}
void LoadMAP (char *Path) // Load la map écrite dans Path FONCTION NON UTILISE
{
char c='a';
bool moi=true;
char Temp[50]="";
char chemin[50]="";
int curseur=0;
int nb;
float flo;
char Path2[25]="";
sprintf(Path2,"%s%s",LoadPath,Path);
int i=0,i2=0,i3=0;
InitGrille();
FILE *f;
f=fopen(Path,"r");
if (f==NULL){c='EOF';}

int Etat=0;
while ((c!='EOF') && moi)
{
    printf("%i\n",f);
        switch (Etat)
        {

            case 0:
               // printf("Case : %i,%i  %i\n",i,i2,Etat);
                fscanf(f,"%c",&c);
                if(Estunchiffre(c))
                    {
                    printf("Etat %i\n",Etat);
                    curseur=ftell(f);
                    fseek(f,curseur-1,SEEK_SET);
                    fscanf(f,"%i",&nb);
                    i=nb;
                    printf("Case : %i,%i  %i\n",i,i2,Etat);
                    }
                    else
                        {
                        if(c==';'){Etat++;}
                        }
            break;


            case 1:
                fscanf(f,"%c",&c);
                printf("Case : %i,%i  %i\n",i,i2,Etat);
                if(Estunchiffre(c))
                    {
                    curseur=ftell(f);
                    fseek(f,curseur-1,SEEK_SET);
                    fscanf(f,"%i",&nb);
                    i2=nb;

                    }
                    else
                        {
                        if(c==';'){Etat++;}
                        }
            break;



            case 2:
                    fscanf(f,"%c",&c);
                    if(Estunchiffre(c))
                    {
                    curseur=ftell(f);
                    fseek(f,curseur-1,SEEK_SET);
                    fscanf(f,"%i",&nb);
                    grille[i][i2].optionT.optionType=nb;
                    printf("Case : %i,%i  %i\n",i,i2,Etat);
                    }
                    else
                    {
                    if(c==';'){Etat++;}
                    }
            break;


            case 3:
                    fscanf(f,"%c",&c);
                    if(Estunchiffre(c))
                    {
                    curseur=ftell(f);
                    fseek(f,curseur-1,SEEK_SET);
                    fscanf(f,"%i",&nb);
                    grille[i][i2].optionT.Fixe_Etat=nb;
                    printf("Case : %i,%i  %i\n",i,i2,Etat);
                    }
                    else
                    {
                    if(c==';'){Etat++;}
                    }
            break;


            case 4:
                    fscanf(f,"%c",&c);
                  if(Estunchiffre(c))
                    {
                    curseur=ftell(f);
                    fseek(f,curseur-1,SEEK_SET);
                    fscanf(f,"%i",&nb);
                    grille[i][i2].optionT.Intensite_Bougeable=nb;
                    printf("Case : %i,%i  %i\n",i,i2,Etat);
                    }
                    else
                    {
                    if(c==';'){Etat++;}
                    }
            break;



            case 5:
                        fscanf(f,"%i",&nb);                         //R
                        nb=grille[i][i2].optionT.Couleur.R=nb;
                        fscanf(f,"%c",&c);                          //;
                        fscanf(f,"%i",&nb);                         //V
                        nb=grille[i][i2].optionT.Couleur.V=nb;
                        fscanf(f,"%c",&c);                          //;
                        fscanf(f,"%i",&nb);                         //B
                        nb=grille[i][i2].optionT.Couleur.R=nb;
                        fscanf(f,"%c",&c);
                        printf("Case : %i,%i  %i\n",i,i2,Etat);
                        Etat++;


            break;


            case 6:

                    i3=0;
                    strcpy(Temp,"");
                    c=' ';
                    while(c!=';')
                    {
                        fscanf(f,"%c",&c);
                        if(c!=';'){Temp[i3]=c;}
                        i3++;
                    }
                    strcpy(grille[i][i2].optionT.sprite,Temp);
                    printf("Case : %i,%i  %i\n",i,i2,Etat);
                    Etat++;
            break;

            case 7:
                    fscanf(f,"%c",&c);
                    if(Estunchiffre(c))
                    {
                    curseur=ftell(f);
                    fseek(f,curseur-1,SEEK_SET);
                    fscanf(f,"%f",&flo);
                    grille[i][i2].optionT.Direction=flo;
                    printf("Case : %i,%i  %i\n",i,i2,Etat);
                    }
                    else
                    {
                    if(c==';'){Etat++;}
                    }

            break;

            case 8:
                fscanf(f,"%c",&c);
                if(Estunchiffre(c))
                   {
                   curseur=ftell(f);
                   fseek(f,curseur-1,SEEK_SET);
                   fscanf(f,"%f",&flo);
                   grille[i][i2].optionT.Angle=flo;
                   printf("Case : %i,%i  %i\n",i,i2,Etat);
                   }
                   else
                   {
                   if(c==';'){Etat++;}
                   }

           break;

            case 9:
                fscanf(f,"%c",&c);
                if(Estunchiffre(c))
                   {
                   curseur=ftell(f);
                   fseek(f,curseur-1,SEEK_SET);
                   fscanf(f,"%i",&nb);
                   grille[i][i2].collision=nb;
                   printf("Case : %i,%i  %i\n",i,i2,Etat);
                   }
                   else
                   {
                   if(c==';'){Etat++;}
                   }

            break;

            case 10:
                 fscanf(f,"%c",&c);
                 if(Estunchiffre(c))
                   {
                   curseur=ftell(f);
                   fseek(f,curseur-1,SEEK_SET);
                   fscanf(f,"%i",&nb);
                   grille[i][i2].animation=nb;
                   printf("Case : %i,%i  %i\n",i,i2,Etat);
                   }
                   else
                   {
                   if(c==';'){Etat++;}
                   }
            break;

            case 11:
                fscanf(f,"%c",&c);
                printf("Case : %i,%i  FAIT\n",i,i2);
                if(c==')'){
                Etat=0;
                fscanf(f,"%c",&c);
                if(c==EOF){moi=false;}
                    else
                    {
                    curseur=ftell(f);
                    fseek(f,curseur-1,SEEK_SET);
                    printf("Case : %i,%i  %i\n",i,i2,Etat);
                    }

                }


            break;
        }
}
fclose(f);
}

void LoadMapBis(char* path) // Fonction pour Load la Map Path CELLE CI EST UTILISEE
{
int x,y,i;
char T[50];
char c='a';
FILE* f = fopen(path,"r");
InitGrille();
while (!feof(f))
{
fscanf(f,"(%i;%i;",&x,&y);
fscanf(f,"%i;%i;%i;%i;%i;%i;",&grille[x][y].type
        ,&grille[x][y].optionT.Fixe_Etat,&grille[x][y].optionT.Intensite_Bougeable
        ,&grille[x][y].optionT.Couleur.R,&grille[x][y].optionT.Couleur.V
        ,&grille[x][y].optionT.Couleur.B);

i=0;
c='a';
strcpy(T,"");
fscanf(f,"%c",&c);
while (c!=';' && !feof(f) && c!='EOF' && c!=' ')
{
T[i]=c;
i++;
printf("%c\n",c);
fscanf(f,"%c",&c);
}
        if(c!='EOF' && !feof(f)){
        T[i]='\0';
        strcpy(grille[x][y].optionT.sprite,T);
       fscanf(f,"%f;%f;%i;%i;%i;%i;%i)",&grille[x][y].optionT.Direction,&grille[x][y].optionT.Angle
        ,&grille[x][y].collision,&grille[x][y].animation,&grille[x][y].optionT.visible
        ,&grille[x][y].AuDessus,&grille[x][y].optionT.HerbeHaute);

        printf("J'ai fais : %i,%i ! :D\n",x,y); }
}
}
/* (x;y;type(objet :) Etat;bougeable;          sprite                    ;Collision;Animation;visible{event...}
             (light :) Fixe;Intensité;R;V;B;          direction;angle
    0 1  2               3       4      5         6       7          8          9        10
*/


void saveMAP(char* path) // Fonction Pour Save la Map Path
{
int i,i2;
char T[50];
FILE* f=fopen(path,"w+");

    for(i=0;i<MAPMAX;i++)
    {
        for(i2=0;i2<MAPMAX;i2++)
        {        //   0  1  2  3  4  5  6  7  8  9 10
        if(!IsEmptyGrille(i,i2))
        {
        strcpy(T,grille[i][i2].optionT.sprite);
         fprintf(f,"(%i;%i;%i;%i;%i;%i;%i;%i;%s;%f;%f;%i;%i;%i;%i;%i)",i,i2,grille[i][i2].type
        ,grille[i][i2].optionT.Fixe_Etat,grille[i][i2].optionT.Intensite_Bougeable
        ,grille[i][i2].optionT.Couleur.R,grille[i][i2].optionT.Couleur.V
        ,grille[i][i2].optionT.Couleur.B,T
        ,grille[i][i2].optionT.Direction,grille[i][i2].optionT.Angle
        ,grille[i][i2].collision
        ,grille[i][i2].animation,grille[i][i2].optionT.visible
        ,grille[i][i2].AuDessus,grille[i][i2].optionT.HerbeHaute);
        }

        }
    }
fclose(f);
}
