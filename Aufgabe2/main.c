#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define _USE_MATH_DEFINES

int M_eingabe, fehlerwert;
int i, doppeljahr;
float zinssatz, startkap, endkap, jahre, faktor;


//---------------ZINSRECHNER-FUNKTION-----------------//

int zinsenrechner()
{
  startkap = 0; zinssatz = 0; jahre = 0;

  printf("Bitte geben sie die Zinswerte ein:\n\n");

  printf("Startkapital:\t ");
  scanf("%f", &startkap);
  if(startkap < 0){printf("Eingabe fehlerhaft!\n"); return -1;}

  printf("\nZinssatz:\t ");
  scanf("%f", &zinssatz);
  if(zinssatz < 0){printf("Eingabe fehlerhaft!\n"); return -1;}

  printf("\nJahre:\t\t ");
  scanf("%f", &jahre);
  if(jahre < 0){printf("Eingabe fehlerhaft!\n"); return -1;}
  printf("\n\n");

  printf("Jahr:\tKontostand:\n");

  bool trigger = true;

  for(i = 0; i <= jahre; i++)
  {
      endkap = startkap * pow((1 + zinssatz/100), i);

      if(endkap >= 2*startkap && trigger)
      {
        doppeljahr = i;
        trigger = false;
      }

      printf("%i\t%.02f\n", i, endkap);
  }

  printf("\n");

  faktor = endkap/startkap;

  printf("Der Faktor nach %.f Jahren Verzinsung ist: %f\n\n", jahre, faktor);

  if(doppeljahr != 0)
  {
    printf("Nach %i Jahren wurde der Startbetrag verdoppelt!\n\n", doppeljahr);
  }

  return 0;
}

//--------------MAIN-FUNKTION--------------------//

int main()
{
    do
    {
      system("cls");

      printf("--------------------MEN\x9A--------------------\n\n");
      printf("Rechner f\x81r die Zinseszinsberechnung:\t\t1\n");
      printf("Simulation eines einfachen Getr\x84nkeautomats:\t2\n");
      printf("Berechnung verschiedener Primzahlen:\t\t3\n");
      printf("Programm beenden\t\t\t\t4\n\n");

      printf("Men\x81zahl eingeben:\t");
      scanf("%i", &M_eingabe);

      switch(M_eingabe)
      {
        case 1:
          system("cls");
          if(zinsenrechner() == -1)printf("ERROR!\n");

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
