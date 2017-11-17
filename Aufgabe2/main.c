/*
    AUFGABE 2   -   PI PRAKTIKUM 2017
    Ersteller:      Finn Cyriax
    Getestet unter: gcc auf Windows 10 1703 und Ubuntu 16.10

    pausescr und clearscr sind optional und wurden von mir zur Verschönerung
    des Menüs hinzugefügt.

    Kommentare zu (fast) doppelten Funktionen wurden weggelassen
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define _USE_MATH_DEFINES

int fehlerwert, check;
int i;
float zinssatz, startkap, endkap, jahre, faktor, doppeljahr;

//---------------CLEAR-SCREEN-FUNKTION----------------//

void clearscr(void)
{
  #ifdef _WIN32         //Check ob ausführendes System auf Windows basiert
      system("cls");    //clearscreen für Windows
    #elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
                        //Check ob ausführendes System Linux oder Mac OS ist
      system("clear");  //clearscreen für Mac und Linux
    #else
      #error "OS not supported."
  #endif
}

//-----------------PAUSE-FUNKTION---------------------//

void pausescr(void)
{
  int pause;
  #ifdef _WIN32
    system("pause");
  #elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    printf("\nTippen sie eine 1 zum fortfahren: ");
    scanf("%i", &pause);
  #else
    #error "OS not supported."
  #endif
}




//---------------ZINSRECHNER-FUNKTION-----------------//
//                    Aufgabe 2.1                     //

int zinsenrechner()
{
  startkap = 0; zinssatz = 0; jahre = 0;

  printf("Bitte geben sie die Zinswerte ein:\n\n");

  printf("Startkapital:\t\t ");
  check = scanf("%f", &startkap);
  if(check != 1 || startkap <= 0) return -1;            // Check ob positive Gleitkommazahl eingegeben wurde

  printf("\nZinssatz(Prozent):\t ");
  check = scanf("%f", &zinssatz);
  if(check != 1 || zinssatz <= 0) return -1;

  printf("\nJahre:\t\t\t ");
  check = scanf("%f", &jahre);
  if(check != 1 || jahre <= 0) return -1;
  printf("\n\n");

  printf("Jahr:\tKontostand:\n");                       // Tabellenüberschrift

  bool trigger = true;

  for(i = 0; i <= jahre; i++)                           // Schleife für Zinstabelle
  {
      endkap = startkap * pow((1 + zinssatz/100), i);   // Zinseszinsformel

      printf("%i\t%.02f\n", i, endkap);
  }

  printf("\n");

  faktor = endkap/startkap;                             // Endfaktorberrechnung
  printf("Der Faktor nach %.f Jahren Verzinsung ist: %f\n\n", jahre, faktor);


  doppeljahr = log(2)/log(1+(zinssatz/100));            // Verdopplungsjahrberrechnung
  printf("Nach %f Jahren w\x84re der Betrag verdoppelt!\n\n", doppeljahr);

  return 0;
}

//---------------AUTOMAT-FUNKTION-------------------//
//                  Aufgabe 2.2                     //

int automat()
{
  int a_wahl, G_ct, G_eu, G_2, G_1, G_50, G_20, G_10, G_05, G_02, G_01;
  float geld;

  void automat_header(void)                                 // Definition eines Programm-Headers
  {
    printf("#######################################\n");
    printf("------------GETR\x8ENKE-AUTOMAT-----------\n");
    printf("#######################################\n\n");
  }

  float wechselgeld(float a)                                // Definiton einer Wechselgeld-Funktion
  {
    G_eu = (int)a;                      // Konvertierung des Gleitkommazahl Geldes in zwei int Variablen
    G_ct = (int)((a - G_eu) * 100);     // Notwendig für int-Division mit Rest

    printf("Ihr Wechselgeld:\n\n");

    G_2 = G_eu / 2;                     // int-Division mit Rest
    printf("%i x 2 Euro\n", G_2);
    G_eu = G_eu - (G_2 * 2);            // Abziehen des Geldes was durch 2€ Stücke beschreibbar ist

    G_1 = G_eu / 1;
    printf("%i x 1 Euro\n", G_1);       // Abziehen kann vernachlässigt werden, da Division durch 1


    G_50 = G_ct / 50;                   // Berechnung für Centbeträge
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

    printf("\n");

    return 0;
  }

  // BEGINN HAUPTFUNKTION AUTOMAT

  automat_header();

  printf("Wie viel Geld wurde eingeworfen? (Bsp: 13.37)\n");
  scanf("%f", &geld);
  printf("\n");

  if(geld < 10){ printf("BITTE MIN. 10 EURO EINWERFEN!\n\n"); return -1;} // Abfrage ob mindestens 10€ eingeworfen wurden

  clearscr();

  a_wahl = 0;

  automat_header();

  printf("Getr\x84nk\t\tPreis\t\tNummer\n\n");      // Tabelle der Getränke
  printf("Wasser\t\t1.50 Euro\t1\n");
  printf("Mountain Dew\t4.20 Euro\t42\n");
  printf("K\x94lsch\t\t1.00 Euro\t3\n");
  printf("\n");

  printf("Bitte geben Sie die gew\x81nschte Nummer ein: ");
  scanf("%i", &a_wahl);

  switch (a_wahl)                 // Fallunterscheidung für Auswahl
  {
    case 1:
      geld = geld - 1.50;         // Abziehen des Betrages für jeweiliges Getränk
      wechselgeld(geld);          // Berechnung des Wechselgelds
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
      printf("Bitte gültiges Getr\x84nk eingeben!\n");    //Fehlermeldung für ungültige Nummer
      break;
  }

  return 0;
}

//--------------PRIMZAHL-FUNKTION----------------//
//              under construction               //
int primzahlen()
{
  int primzahlen[1];
  long double schranke;



}

//--------------MAIN-FUNKTION--------------------//

int main()
{
    int M_eingabe;

    do
    {
      clearscr();                                      // Bildschirm clear

      printf("--------------------MEN\x9A--------------------\n\n");
      printf("Rechner f\x81r die Zinseszinsberechnung:\t\t1\n");
      printf("Simulation eines einfachen Getr\x84nkeautomats:\t2\n");
      printf("Berechnung verschiedener Primzahlen:\t\t3\n");
      printf("Programm beenden\t\t\t\t4\n\n");

      printf("Men\x81zahl eingeben:\t");
      scanf("%i", &M_eingabe);                         // Einlesen der Menüzahl

      switch(M_eingabe)
      {
        case 1:
          clearscr();                                  // Bildschirm clear
          if(zinsenrechner() == -1) printf("\nFehler bei der Eingabe in Programm 1!\n"); // Abfrage ob Fehlermeldung -1

          pausescr();                                  //PAUSE-Funktion (wait for input)
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

    }while(M_eingabe != 4);                   // Wenn Menüzahl 4 -> Aus Schleife austreten

    return 0;
}
