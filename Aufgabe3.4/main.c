/*  AUFGABE 3.4 - PI Praktikum
 *
 *  Ersteller:  Cyriax
 *  Version:    1
 *  Datum:      10.01.2018
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x = 0;

void loescheSonderzeichen(char *satz)
// Funktion zum Löschen von Sonderzeichen, Ziffern und Leerzeichen
{
    int i = 0, j = 0;
    char *zwischenspeicher;

    zwischenspeicher = calloc(strlen(satz), sizeof(char));

    for(i = 0; i <= strlen(satz); i++)
    {
        if(satz[i] > 64 && satz[i] < 91 || satz[i] > 96 && satz[i] < 123)
        // Alle Buchstaben werden in den Zwischenspeicher geschrieben
        {
            zwischenspeicher[j] = satz[i];
            j++;
        }
    }

    memmove(satz, zwischenspeicher, strlen(zwischenspeicher) + 1);
    // Daten von Zwischenspeicher (inkl. \0) in Satz

    realloc(satz, strlen(satz) + 1);
    free(zwischenspeicher);
    // Überflüssigen Speicher freigeben

    return;
}

char **zerschneideSatz(char *satz)
// Funktion die einzelne Wörter eines Satzes herrausschneidet
{
    char **Teilsatzarray;
    int i = 0,
        y = 0;

    // Grundwert: max. 50 Wörter à 50 Zeichen
    Teilsatzarray = calloc(50, sizeof(char *));

    for(i = 0; i <= 50; i++)
    {
        Teilsatzarray[i] = calloc(50, sizeof(char));
    }


    for(i = 0; i <= strlen(satz) + 1; i++)
    {
        if(satz[i] > 64 && satz[i] < 91 || satz[i] > 96 && satz[i] < 123 || satz[i] == '\0' || satz[i] == 32)
        // Alle zulässigen Zeichen
        {
            Teilsatzarray[x][y] = satz[i];

            if(satz[i] == 32)
            // Leerzeichen durch String-Ende ersetzen
            {
                Teilsatzarray[x][y] = '\0';
                x++;
                y = 0;
            }
            else
            {
                y++;
            }
        }
    }

    for(i = 0; i < x; i++)
    // Rücksetzen des überflüssigen Speichers
    {
        realloc(Teilsatzarray[i], strlen(Teilsatzarray[i]) + 1);
    }

    return Teilsatzarray;
}

int main()
{
    char **Schnittsaetze;
    int i;

    char *Satz2 = calloc(100, sizeof(char));
    char *Satz1 = calloc(100, sizeof(char));

    printf("Geben sie einen Satz mit Sonderzeichen ein: \n\n");
    fgets(Satz1, 100, stdin);

    loescheSonderzeichen(Satz1);

    printf("%s\n\n", Satz1);

    printf("Geben sie einen Satz ein: \n\n");
    fgets(Satz2, 100, stdin);

    Schnittsaetze = zerschneideSatz(Satz2);

    printf("\n");

    for(i = 0; i <= x; i++)
    {
        printf("%s\n", Schnittsaetze[i]);
    }

    return 0;
}
