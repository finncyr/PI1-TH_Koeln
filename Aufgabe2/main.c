/*
    AUFGABE 2   -   PI PRAKTIKUM 2017

    Ersteller:      Finn Cyriax
    Getestet unter: gcc auf Windows 10 und Ubuntu 16.10

        MENÜ: Zeile 287
        2.1 : Zeile  65
        2.2 : Zeile 112
        2.3 : Zeile 226

    pausescr und clearscr sind optional und wurden von mir zur Verschönerung
    des Menüs hinzugefügt.

    Kommentare zu (fast) gleichen Zeilen wurden weggelassen

    Da ich immer etwas vor den Deadlines bin ignorieren sie bitte die
    nicht relevanten Funktionen. Entsprechende Aufgaben sind betitelt.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES                               // Ruft mathematische Variablen wie Pi auf
#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)           // Aufgabe 2.3: Zeit soll in ms ausgegeben werden, daher s/1000=ms

int fehlerwert, check;

//---------------CLEAR-SCREEN-FUNKTION----------------//
//    Funktion zum Löschen des Bildschirminhaltes     //

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
// Funktion um vor dem Löschen des Bildschirminhaltes //
//        dem Nutzer sein Ergebnis anzuzeigen         //

void pausescr(void)
{
  char pause;
  #ifdef _WIN32
    system("pause");                // Windows interner pause-Befehl
  #elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    printf("\nTippen sie ein j zum fortfahren: ");
    scanf(" %c", &pause);           // Linux Workaround mit einer scanf Eingabe
  #else
    #error "OS not supported."      // Error falls anderes Betriebssystem
  #endif
}




//---------------ZINSRECHNER-FUNKTION-----------------//
//                    Aufgabe 2.1                     //

int zinsenrechner()
{
  float zinssatz, startkap, endkap, jahre, faktor, doppeljahr;
  int i;                                                // Zählvariable

  startkap = 0; zinssatz = 0; jahre = 0, check = 1;     // Setzten der Standardwerte

  printf("Bitte geben sie die Zinswerte ein:\n\n");

  printf("Startkapital:\t\t ");
  check = scanf("%f", &startkap);                       // Einlesen des scanf-Rückgabewertes als Variable
  if(check != 1 || startkap <= 0) return -1;            // Check ob positive Gleitkommazahl eingegeben wurde

  printf("\nZinssatz(Prozent):\t ");
  check = scanf("%f", &zinssatz);
  if(check != 1 || zinssatz <= 0) return -1;

  printf("\nvolle Jahre:\t\t ");
  check = scanf("%f", &jahre);
  if(check != 1 || jahre <= 0) return -1;
  printf("\n\n");

  printf("Jahr:\tKontostand:\n");                       // Tabellenüberschrift


  for(i = 0; i <= jahre; i++)                           // Schleife für Zinstabelle
  {
      endkap = startkap * pow((1 + zinssatz/100), i);   // Zinseszinsformel

      printf("%i\t%.02f\n", i, endkap);                 // Ausgeben der Werte
  }

  printf("\n");

  faktor = endkap/startkap;                             // Endfaktorberrechnung
  printf("Der Faktor nach %.f Jahren Verzinsung ist: %f\n\n", jahre, faktor);


  doppeljahr = log(2)/log(1+(zinssatz/100));            // Verdopplungsjahrberrechnung
  printf("Nach %f Jahren w\x84re der Betrag verdoppelt!\n\n", doppeljahr);

  return 0;                                             // Nach erfolgreichem Beenden
}

//---------------AUTOMAT-FUNKTION-------------------//
//                  Aufgabe 2.2                     //

int automat()
{
  int a_wahl, G_ct, G_eu, G_2, G_1, G_50, G_20, G_10, G_05, G_02, G_01;
  float geld;

  void AutomatHeader(void)                                 // Definition eines Programm-Headers
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

  a_wahl = 0;

  while(1 == 1){                                      // Unendliche while-Schleife

    AutomatHeader();

    printf("Getr\x84nk\t\tPreis\t\tNummer\n\n");      // Tabelle der Getränke
    printf("Wasser\t\t1.50 Euro\t1\n");
    printf("Mountain Dew\t4.20 Euro\t42\n");
    printf("K\x94lsch\t\t1.00 Euro\t3\n");
    printf("\n");

    printf("Bitte geben Sie die gew\x81nschte Nummer ein: ");
    scanf("%i", &a_wahl);

    clearscr();

    if(a_wahl == 1 || a_wahl == 42 || a_wahl == 3) break;  // break aus Schleife

    else {
      printf("Bitte richtige Nummer eingeben!\n\n");       // ERROR-Nachricht
    }
  }

  AutomatHeader();

  printf("Wie viel Geld wurde eingeworfen? (Bsp: 13.37)\n");
  scanf("%f", &geld);
  printf("\n");

  if(geld < 10){ printf("BITTE MIN. 10 EURO EINWERFEN!\n\n"); return -1;} // Abfrage ob mindestens 10€ eingeworfen wurden


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
  }

  return 0;
}

//--------------PRIMZAHL-FUNKTION----------------//
//                 Aufgabe 2.3                   //

int primzahlen()
{
  /////////////////////////
  int primcheck(int n)
  {
    int i;

    if(n < 2)  return 0;
    if(n == 2) return 1;

    if((n % 2) == 0) return 0;

    for(i = 3; i <= sqrt(n); i += 2)
    {
      if((n % i) == 0) return 0;
    }

    return 1;
  }
  ////////////////////////


  long schranke, j, x, array_count, P_check;
  int time1, time2, thou;

  printf("Bitte obere Schranke eingeben: \n");
  scanf("%ld", &schranke);
  if(schranke < 0) return -1;
  printf("\n");

  int primzahlen[schranke];
  array_count = 0;

  time1 = clock();

  for(j = 0; j <= schranke; j++)
  {
    P_check = primcheck(j);

    if(P_check == 1)
    {
      primzahlen[array_count] = j;
      array_count++;
    }
  }

  time2 = clock();

  thou  = (time2 - time1) / CLOCKS_PER_MS;

  x = 0;

  while(x < array_count)
  {
    printf("%i ist eine Primzahl\n", primzahlen[x]);
    x++;
  }

  printf("\nEs wurden %li Primzahlen gefunden!\n", array_count);
  printf("Die Berrechnung dauerte %i ms!\n\n", thou);

  return 0;
}

//--------------MAIN-FUNKTION--------------//
//  Menüführung für einfaches Starten der  //
//             Unterfunktionen             //

int main()
{
    int M_eingabe;                                     // Variable für die Menüeingabe

    do
    {
      clearscr();                                      // Bildschirm clear

      printf("--------------------MEN\x9A--------------------\n\n");
      printf("Rechner f\x81r die Zinseszinsberechnung:\t\t1\n");
      printf("Simulation eines einfachen Getr\x84nkeautomats:\t2\n");
      printf("Berechnung verschiedener Primzahlen:\t\t3\n");
      printf("Programm beenden\t\t\t\t4\n\n");

      printf("Men\x81zahl eingeben:\t");
      scanf(" %i", &M_eingabe);                         // Einlesen der Menüzahl

      switch(M_eingabe)                                // Menüwahl-Switch
      {
        case 1:
          clearscr();                                  // Bildschirm clear
          if(zinsenrechner() == -1) printf("\nFehler bei der Eingabe in Programm 1!\n"); // Abfrage ob Fehlermeldung -1
                                                                                         // Gleichzeitig wird die Funktion aufgerufen
          pausescr();                                  //PAUSE-Funktion (wait for input)
          break;

        case 2:
          clearscr();
          if(automat() == -1) printf("\nFehler bei der Eingabe in Programm 2!\n");

          pausescr();
          break;

        case 3:
          clearscr();
          if(primzahlen() == -1) printf("\nFehler bei der Eingabe in Programm 3!\n");

          pausescr();
          break;

        case 4:
          break;

        default:
          printf("Keine g\x81ltiger Men\x81punkt\n\n");       // Fehlermeldung, falls andere Zahl eingegeben wird
          pausescr();
      }

    }while(M_eingabe != 4);                   // Wenn Menüzahl 4 -> Aus Schleife austreten

    return 0;
}
