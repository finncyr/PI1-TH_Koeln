/** AUFGABE 3.1 - PI Praktikum
 *
 *  Ersteller:  Cyriax
 *  Version:    1
 *  Datum:      13.12.2017
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GROESSE_FELD 4
#define DIM_ZEILE GROESSE_FELD * 2 + 1
#define DIM_SPALTE GROESSE_FELD * 2 + 1

void spielGeruest(char **spielfeld)
{
    int i = 0, j = 0;

    for(i = 0; i < (DIM_ZEILE); i++)
    {
        for(j = 0; j < (DIM_SPALTE); j++)
        {
            if(!(i % 2))
            {
                if(!(j % 2))
                {
                    spielfeld[i][j] = '|';
                }

                else
                {
                    spielfeld[i][j] = '-';
                }
            }

            else
            {
                if(!(j % 2))
                {
                    spielfeld[i][j] = '|';
                }

                else
                {
                    spielfeld[i][j] = 'x';
                }
            }
        }
    }
}

void ausgabeSpielfeld(char **spielfeld)
{
    int x = 0, y = 0;

    for(x = 0; x < DIM_SPALTE; x++)
    {
        for(y = 0; y < DIM_ZEILE; y++)
        {
            printf("%c", spielfeld[x][y]);
        }

        printf("\n");
    }

}

int main()
{
    int i = 0;
    char **spielfeld;

    spielfeld = (char**)malloc(sizeof(char*) * DIM_ZEILE);
    for(i = 0; i < DIM_SPALTE; i++)
    {
        spielfeld[i] = (char*)malloc(sizeof(char*) * DIM_SPALTE);
    }

    spielGeruest(spielfeld);
    ausgabeSpielfeld(spielfeld);

    return 0;
}
