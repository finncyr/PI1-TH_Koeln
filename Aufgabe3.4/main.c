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
{
    int i = 0, j = 0;
    char *zwischenspeicher;

    zwischenspeicher = calloc (strlen(satz), sizeof(char));

    for(i = 0; i <= strlen(satz); i++)
    {
        if(satz[i] > 64 && satz[i] < 91 || satz[i] > 96 && satz[i] < 123)
        {
            zwischenspeicher[j] = satz[i];
            j++;
        }
    }

    memmove(satz, zwischenspeicher, strlen(zwischenspeicher) + 1);

    realloc(satz, strlen(satz) + 1);

    return;
}

char **zerschneideSatz(char *satz)
{
    char **Teilsatzarray;
    int i = 0,
        y = 0;

    Teilsatzarray = calloc(50, sizeof(char *));

    for(i = 0; i <= 50; i++)
    {
        Teilsatzarray[i] = calloc(25, sizeof(char));
    }


    for(i = 0; i <= strlen(satz) + 1; i++)
    {
        if(satz[i] > 64 && satz[i] < 91 || satz[i] > 96 && satz[i] < 123 || satz[i] == '\0' || satz[i] == 32)
        {
            Teilsatzarray[x][y] = satz[i];

            if(satz[i] == 32)
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

    return Teilsatzarray;
}

int main()
{
    char **Schnittsaetze;
    int i;

    char *Satz2 = calloc(100, sizeof(char));
    char *Satz1 = calloc(100, sizeof(char));

    //scanf("%s", &Satz1[0]);
    printf("Geben sie einen Satz mit Sonderzeichen ein: \n\n");
    fgets(Satz1, 100, stdin);

    loescheSonderzeichen(Satz1);

    printf("%s\n", Satz1);

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
