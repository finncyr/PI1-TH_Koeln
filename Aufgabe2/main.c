#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define _USE_MATH_DEFINES

char enter;
int M_eingabe, fehlerwert, check;
int i, doppeljahr;
float zinssatz, startkap, endkap, jahre, faktor;

//---------------CLEAR-SCREEN-FUNKTION----------------//

void clearscr(void)
{
  #ifdef _WIN32
      system("cls");
    #elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
      system("clear");
    //add some other OSes here if needed
    #else
      #error "OS not supported."
    //you can also throw an exception indicating the function can't be used
  #endif
}

//-----------------PAUSE-FUNKTION---------------------//

void pausescr(void)
{
  #ifdef _WIN32
    system("pause");
  #elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("read -rsp $'Press enter to continue...\n'");
  #else
    #error "OS not supported."
  #endif
}


//---------------ZINSRECHNER-FUNKTION-----------------//

int zinsenrechner()
{
  startkap = 0; zinssatz = 0; jahre = 0;

  printf("Bitte geben sie die Zinswerte ein:\n\n");

  printf("Startkapital:\t ");
  check = scanf("%f", &startkap);
  if(check != 1 || startkap <= 0) return -1;

  printf("\nZinssatz:\t ");
  check = scanf("%f", &zinssatz);
  if(check != 1 || zinssatz <= 0) return -1;

  printf("\nJahre:\t\t ");
  check = scanf("%f", &jahre);
  if(check != 1 || jahre <= 0) return -1;
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

int automat()
{
  int a_wahl, G_ct, G_eu, G_2, G_1, G_50, G_20, G_10, G_05, G_02, G_01;
  float geld, geld_cent, geld_euro;

  void automat_header(void)
  {
    printf("#######################################\n");
    printf("------------GETR\x8ENKE-AUTOMAT-----------\n");
    printf("#######################################\n\n");
  }

  float wechselgeld(float a)
  {
    G_eu = (int)a;
    G_ct = (int)((a - G_eu) * 100);

    printf("Ihr Wechselgeld:\n\n");

    G_2 = G_eu / 2;
    printf("%i x 2 Euro\n", G_2);
    G_eu = G_eu - (G_2 * 2);

    G_1 = G_eu / 1;
    printf("%i x 1 Euro\n", G_1);


    G_50 = G_ct / 50;
    printf("%i x 50 ct\n", G_50);
    G_ct = G_ct - (G_50 * 50);

    G_20 = G_ct / 20;
    printf("%i x 20 ct\n", G_20);
    G_ct = G_ct - (G_20 * 20);

    G_10 = G_ct / 10;
    printf("%i x 10 ct\n", G_10);
    G_ct = G_ct - (G_10 * 10);

    G_05 = G_ct / 5;
    printf("%i x 5 ct\n", G_05);
    G_ct = G_ct - (G_05 * 5);

    G_02 = G_ct / 2;
    printf("%i x 2 ct\n", G_02);
    G_ct = G_ct - (G_02 * 2);

    G_01 = G_ct / 1;
    printf("%i x 1 ct\n", G_01);
    G_ct = G_ct - (G_01 * 1);

    printf("\n");
  }

  // BEGINN HAUPTFUNKTION

  automat_header();

  printf("Wie viel Geld wurde eingeworfen? (Bsp: 13.37)\n");
  scanf("%f", &geld);
  printf("\n");

  if(geld < 10){ printf("BITTE MIN. 10 EURO EINWERFEN!\n\n"); return -1;}

  clearscr();

  automat_header();

  printf("Getr\x84nk\t\tPreis\t\tNummer\n\n");
  printf("Wasser\t\t1.50 Euro\t1\n");
  printf("Mountain Dew\t4.20 Euro\t42\n");
  printf("K\x94lsch\t\t1.00 Euro\t3\n");
  printf("\n");

  printf("Bitte geben Sie die gew\x81nschte Nummer ein: ");
  scanf("%i", &a_wahl);

  switch (a_wahl)
  {
    case 1:
      geld = geld - 1.50;
      wechselgeld(geld);
      break;

    case 42:
      geld = geld - 4.20;
      wechselgeld(geld);
      break;

    case 3:
      geld = geld - 1.00;
      wechselgeld(geld);
      break;

    default:
      return -1;

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
          clearscr();
          if(zinsenrechner() == -1) printf("\nFehler bei der Eingabe in Programm 1!\n");

          pausescr();                                                      //PAUSE-Funktion
          break;

        case 2:
          clearscr();
          if(automat() == -1) printf("\nFehler bei der Eingabe in Programm 2!\n");

          pausescr();
          break;

        case 3:
          clearscr();
          printf("Primzahlen-Platzhalter\n");

          pausescr();
          break;

        case 4:
          break;

        default:
          printf("Keine g\x81ltiger Men\x81punkt\n\n");
          pausescr();
      }

    }while(M_eingabe != 4);

    return 0;
}
