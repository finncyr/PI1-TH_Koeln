#include <stdio.h>
#include <stdlib.h>

int M_eingabe;

int main()
{
    do
    {
      system("cls");

      printf("--------------------MEN\x9A--------------------\n\n");
      printf("Flaechenberechnung von Dreiecksgeometrien:\t1\n");
      printf("Simulation eines einfachen Getr\x84nkeautomats:\t2\n");
      printf("Berechnung verschiedener Primzahlen:\t\t3\n");
      printf("Programm beenden\t\t\t\t4\n\n");

      printf("Men\x81zahl eingeben:\t");
      scanf("%i", &M_eingabe);

      switch(M_eingabe)
      {
        case 1:
          system("cls");
          printf("Bitte geben sie ihre Dreiecksdaten ein:\n\n");

          system("pause");                                                      //PAUSE-Funktion
          break;

        case 2:
          system("cls");
          printf("Getränkeautomat-Platzhalter\n");

          system("pause");
          break;

        case 3:
          system("cls");
          printf("Primzahlen-Platzhalter\n");
          
          system("pause");
          break;
      }

    }while(M_eingabe != 4);

    return 0;
}
