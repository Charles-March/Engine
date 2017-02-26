#define TTMAX 32
#define MAPMAX 1000
#define NBTILEAFFICHE 30
SDL_Window* pWindow = NULL;

SDL_Surface *ecran=NULL;
SDL_Surface *Stemp=NULL;

SDL_Rect tempT;

SDL_Texture *sdlTexture;

SDL_Event event;

SDL_Renderer* renderer;

TTF_Font *police=NULL;

int XImgActuelle=0;
int ImgActuelle=0;
int ImgActuelleI=0;
char TexteHCD[9][50];
char IMG[NBTILEAFFICHE][50]={"","","","","","","","","",""};

int Mx,My;
int Xhelp, Yhelp;
int sourisClic = 0;
int menuOuvert = 0;
int numImgClic = 1000;
int compteur=1;
char Imgpath[]="./img/";
char LoadPath[]="./save/";
int IPS=60;

float Temps_Fin_Tour;
float Temps_Debut_Tour;
float Temps_Tour;

SDL_Color noire={0,0,0};
SDL_Color vert={120,255,120};
SDL_Color bleu={120,120,255};
SDL_Color rouge={255,120,120};
SDL_Color blanc={255,255,255};

class Oevent
{

};

class couleur
{
public:
int R;
int V;
int B;
};

class option
{
public:
int optionType;
int Fixe_Etat;
int Intensite_Bougeable;
int visible;
couleur Couleur;
float Direction;
float Angle;
char sprite[50];
int HerbeHaute;
};

class Gmap
{
public:
int type;
option optionT;
int collision;
int animation;
Oevent event;
int AuDessus;
};

class coordonnee
{
public:
int x;
int y;
};

/*
class Gmap{
public:
int collision;
int auDessus;
char sprite[50]
};*/

coordonnee case_actuelle;
coordonnee Noir_HautGauche;
Gmap grille[MAPMAX][MAPMAX];
