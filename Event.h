void ModifierCaract ()  // Permet de modifié Les caractéristique directement en bas a gauche
{
int y=(My-535)/20;
    switch (y)
    {
        case 1:
            grille[Xhelp][Yhelp].optionT.Fixe_Etat=(grille[Xhelp][Yhelp].optionT.Fixe_Etat+1)%5;
        break;

        case 2:
            grille[Xhelp][Yhelp].optionT.Intensite_Bougeable=(grille[Xhelp][Yhelp].optionT.Intensite_Bougeable+1)%2;
        break;

        case 3:
            if(grille[Xhelp][Yhelp].type==1){}
        break;

        case 4:
            if(grille[Xhelp][Yhelp].type==0){grille[Xhelp][Yhelp].collision=(grille[Xhelp][Yhelp].collision+1)%2;}
          //  if(grille[Xhelp][Yhelp].type==1){grille[Xhelp][Yhelp].optionT.Direction++%float(360);}
        break;

        case 5:
            if(grille[Xhelp][Yhelp].type==0){grille[Xhelp][Yhelp].animation=(grille[Xhelp][Yhelp].animation+1)%2;}
        //    if(grille[Xhelp][Yhelp].type==1){grille[Xhelp][Yhelp].angle++%360;}
        break;

        case 6:
            if(grille[Xhelp][Yhelp].type==1){grille[Xhelp][Yhelp].collision=(grille[Xhelp][Yhelp].collision+1)%2;}
            if(grille[Xhelp][Yhelp].type==0){grille[Xhelp][Yhelp].optionT.visible=(grille[Xhelp][Yhelp].optionT.visible+1)%2;}

        break;

        case 7:
            if(grille[Xhelp][Yhelp].type==1){grille[Xhelp][Yhelp].animation=(grille[Xhelp][Yhelp].animation+1)%2;}
            if(grille[Xhelp][Yhelp].type==0){grille[Xhelp][Yhelp].AuDessus=(grille[Xhelp][Yhelp].AuDessus+1)%2;}
        break;

        case 8:
            if(grille[Xhelp][Yhelp].type==0){grille[Xhelp][Yhelp].AuDessus=(grille[Xhelp][Yhelp].optionT.HerbeHaute+1)%2;}

    }
helpCD(Xhelp,Yhelp);
}
/* (x;y;type(objet :) Etat;bougeable;          sprite                    ;Collision;Animation{event...}
             (light :) Fixe;Intensité;R;V;B;          direction;angle
    0 1  2               3       4      5         6       7          8          9        10
*/
void ClicBouton()   // Clic sur le menu
{
    if((menuOuvert == 1) && (Mx >= 0 && Mx < 100) && (My >= 106 && My < 126)) {
        FinSDL();
    } else if((Mx >= 0 && Mx < 75) && (My >= 0 && My < 25)) {
        sourisClic = 1;
        menuOuvert = 1;
    } else if((Mx >= 75 && Mx < 150) && (My >= 0 && My < 25)) {
        sourisClic = 2;
        menuOuvert = 2;
    } else if((Mx >= 0 && Mx < 250) && (My >= 738 && My < 768)) {
        sourisClic = 3;
    } else {
        sourisClic = 0;
        menuOuvert = 0;
    }
}

int numImageClic()  //Retourne le numéro de l'image ou l'on a cliqué a gauche
{
    if (menuOuvert == 0 && (Mx >= 1 && Mx <= 239) && (My >= 76 && My <= 500)) {
        return (((My-76)/34)*7)+((Mx-1)/34);
    } else return numImgClic;
}

void eventB1(void)          // Boucle principale evenementielle
{
SDL_PollEvent(&event);
    switch (event.type)
    {
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_SPACE:
                                lecture_Image();
                            break;

                            case SDLK_s:
                                saveMAP("maptest01.map");
                            break;


                            case SDLK_DELETE:
                                if((Mx>250)&&(My>25)) InitUneCase((Mx-250)/32,(My-25)/32);
                            break;

                            case SDLK_l:
                                LoadMapBis("maptest01.map");
                            break;

                            case SDLK_UP:
                                if(case_actuelle.y!=0)
                                    case_actuelle.y=case_actuelle.y-10;
                            break;

                            case SDLK_DOWN:
                                if(case_actuelle.y!=MAPMAX)
                                    case_actuelle.y=case_actuelle.y+10;
                            break;

                            case SDLK_RIGHT:
                                if(case_actuelle.x!=MAPMAX)
                                    case_actuelle.x=case_actuelle.x+10;
                            break;

                            case SDLK_LEFT:
                                if(case_actuelle.x!=0)
                                    case_actuelle.x=case_actuelle.x-10;
                            break;

                            case SDLK_r:
                                case_actuelle.x=0;
                                case_actuelle.y=0;
                            break;

                        }
                    break;

                    case SDL_MOUSEBUTTONDOWN:
                        switch(event.button.button)
                        {
                            case SDL_BUTTON_LEFT:
                                SDL_GetMouseState(&Mx, &My);
                                numImgClic = numImageClic();
                                ClicBouton();
                                //cadre noir : En HG :  x : 250
//                      y : 25
                                if((Mx>250)&&(My>25)) {Metsdanslamap();}
                                if(Mx>0 && Mx<524 && My>524 && My<737){ModifierCaract();}
                           //     printf("%d\n", numImgClic);
                            break;

                            case SDL_BUTTON_RIGHT:
                                SDL_GetMouseState(&Mx, &My);
                                if(Mx>256 && My>25)
                                    {
                                    helpCD(-1,-1);
                                    }
                            break;
                        }
                    break;

                    case SDL_MOUSEMOTION:
                        if(menuOuvert!=0){SDL_GetMouseState(&Mx, &My);}
                     //   printf("%i %i",Mx,My);
                    break;

                    case SDL_QUIT:
                    FinSDL();
                    break;

                    default:
                    break;
    }
}
