#include <Init.h>

int main(int argc, char** argv)
{
    InitSDL();
        while(pWindow)
        {
            eventB1();      // Fonction Evenement => event.h
            TF1();          // Fonction affichage => affichage.h
         //   OMG();
        }
    return 0;
}
