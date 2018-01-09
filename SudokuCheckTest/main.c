/** AUFGABE 3.2 - PI Praktikum
 *
 *  Ersteller:  Cyriax
 *  Version:    2
 *  Datum:      16.12.2017
 *
 */

 /* TODO

    RegelFunktion check!

    Hängt sich auf!!

 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define GROESSE_FELD 4
#define DIM_ZEILE GROESSE_FELD * 2 + 1
#define DIM_SPALTE GROESSE_FELD * 2 + 1

bool Playable, WinSwitch;

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

void sudokuVorlage(char **spielfeld)
{
    int x = 0, y = 0, xFeld = 0, yFeld = 0;
    char Eingabe[1];
    bool trigger = false;

    x++;
    y++;

    printf("SUDOKU-EINGABE\n(Zahlen 1-4 oder Unterstrich)\n");

    ausgabeSpielfeld(spielfeld);

    printf("\n");

    for(x = 0; x < DIM_SPALTE; x++)
    {
        for(y = 0; y < DIM_ZEILE; y++)
        {
            if(spielfeld[x][y] == 'x')
            {
                xFeld = 0.5 * x + 0.5;
                yFeld = 0.5 * y + 0.5;

                while(1){
                    printf("\nSpalte %i Zeile %i: ", yFeld, xFeld);

                    scanf("%s", &Eingabe[0]);

                    if(Eingabe[0] == '1' || Eingabe[0] == '2' || Eingabe[0] == '3' || Eingabe[0] == '4' || Eingabe[0] == '_')
                    {
                        if(Eingabe[0] == '_'){
                            Eingabe[0] = 32;
                            trigger = true;
                        }

                        spielfeld[x][y] = Eingabe[0];

                        printf("\n");

                        ausgabeSpielfeld(spielfeld);

                        break;
                    }
                }
            }
        }
        printf("\n");
    }

    if(trigger)
    {
        printf("Erstellung abgeschlossen!\n\n");
        Playable = true;
    }
    else
    {
        Playable = false;
    }
}

void sudokuStart(char **spielfeld)
{
    bool EmptyFields = true, trigger = true;
    int x, y, xFeld, yFeld;
    char Eingabe[1];

    printf("SUDOKU#\n#######\n\n");

    ausgabeSpielfeld(spielfeld);
    printf("\n");


    while(EmptyFields)
    {
        while(1)
        {
            printf("Geben sie durch ein Komma getrennt Zeile und Spalte ein,\ndie gefüllt werden soll: ");
            scanf("%i,%i", &xFeld, &yFeld);

            x = xFeld * 2 - 0.5;
            y = yFeld * 2 - 0.5;

            if(spielfeld[x][y] == 32)
            {
                while(1)
                {
                    printf("Bitte Zahl eingeben: ");
                    scanf("%s", &Eingabe);

                    if(Eingabe[0] != '1' && Eingabe[0] != '2' && Eingabe[0] != '3' && Eingabe[0] != '4')
                    {
                       printf("\n###Nur gültige Zahlen eingeben!###\n");
                    }
                    else
                    {
                        spielfeld[x][y] = Eingabe[0];
                        break;
                    }
                }

               break;
            }
            else
            {
                printf("\nBitte leeres Feld angeben!\n");
            }
        }

        ausgabeSpielfeld(spielfeld);

        trigger = false;

        for(x = 0; x < DIM_SPALTE; x++)
        {
            for(y = 0; y < DIM_ZEILE; y++)
            {
                if(spielfeld[x][y] == 32)
                {
                    trigger = true;
                }
            }
        }

        if(!trigger)
        {
            EmptyFields = false;
        }
    }
}


void sudokuCheck(char **spielfeld)
{
    bool Regeln, check[4], Fail;
    int x, y, i;

    WinSwitch = false;


    for(x = 0; x < DIM_SPALTE; x++)
    {
        check[0] = false;
        check[1] = false;
        check[2] = false;
        check[3] = false;

        for(y = 0; y < DIM_ZEILE; y++)
        {
            if(spielfeld[x][y] > 48 && spielfeld[x][y] < 53)
            {
                if(spielfeld[x][y] == '1')
                {
                    if(check[0] == true) return;
                    else check[0] = true;
                }
                else if(spielfeld[x][y] == '2')
                {
                    if(check[1] == true) return;
                    else check[1] = true;
                }
                else if(spielfeld[x][y] == '3')
                {
                    if(check[2] == true) return;
                    else check[2] = true;
                }
                else if(spielfeld[x][y] == '4')
                {
                    if(check[3] == true) return;
                    else check[3] = true;
                }
            }
        }
    }


    for(y = 0; y < DIM_ZEILE; y++)
    {
        check[0] = false;
        check[1] = false;
        check[2] = false;
        check[3] = false;

        for(x = 0; x < DIM_SPALTE; x++)
        {
            if(spielfeld[x][y] > 48 && spielfeld[x][y] < 53)
            {
                if(spielfeld[x][y] == '1')
                {
                    if(check[0] == true) return;
                    else check[0] = true;
                }
                else if(spielfeld[x][y] == '2')
                {
                    if(check[1] == true) return;
                    else check[1] = true;
                }
                else if(spielfeld[x][y] == '3')
                {
                    if(check[2] == true) return;
                    else check[2] = true;
                }
                else if(spielfeld[x][y] == '4')
                {
                    if(check[3] == true) return;
                    else check[3] = true;
                }
            }
        }
    }

    WinSwitch = true;

    return;
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

    sudokuVorlage(spielfeld);

    if(!Playable)
    {
        printf("KEINE LEERSTELLEN GELASSEN!\n");
        return -1;
    }

    sudokuStart(spielfeld);

    sudokuCheck(spielfeld);

    if(WinSwitch == true)
    {
        printf("\n\n\t\tGEWONNEN!\n");
    }
    else
    {
        printf("\n\n\t\tVERLOREN!\n");
    }


    return 0;
}
