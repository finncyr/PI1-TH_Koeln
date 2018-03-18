/*
 ============================================================================
 Name        : Eisenbahn_clean.c
 Author      : Finn Cyriax
 Version     :
 Copyright   : TH K�ln
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DIMENSION 4

int **DateiEinlesen()
{
	FILE *datei;
	char *buffer;
	int **Tabelle;
	int i, j, k, x = 0, y = 0, Zwischenspeicher[10];
	int Faktor = 0; 			//Faktor f�r Konvertierung in int

	datei = fopen("knoten.txt", "r");

	buffer = calloc(DIMENSION * DIMENSION * 10, sizeof(char));

	Tabelle = calloc(DIMENSION - 1, sizeof(int *));

	for(i = 0; i < DIMENSION; i++)
	{
		Tabelle[i] = calloc(1, sizeof(int));
	}

	for(x = 0; x < DIMENSION; x++) //F�llen der Tabellenelemente mit 0
	{
		for(y = 0; y < DIMENSION; y++)
		{
			Tabelle[x][y] = 0;
		}
	}

	i = 0;

	while(1==1)
	{
		if((buffer[i] = fgetc(datei)) == EOF)
		{
			buffer[i] = '\0';
			break;
		}
		else
		{
			i++;
		}
	}

	k = 0; y = 0, x = 0;

	//			KONVERTIEREN IN INT			//

	for(i = 0; i <= strlen(buffer); i++)
	{
		if(buffer[i] == 32)
		{
			Faktor = pow(10, k - 1);

			for(j = 0; j < k; j++)
			{
				Tabelle[x][y] += Zwischenspeicher[j] * Faktor;
				Faktor /= 10;
			}

			k = 0;
			y++;
		}
		else if(buffer[i+1] == '\n')
		{
			Faktor = pow(10, k - 1);

			for(j = 0; j < k; j++)
			{
				Tabelle[x][y] += Zwischenspeicher[j] * Faktor;
				Faktor /= 10;
			}
			i++;
			k = 0;
			x++;
			y = 0; //Sorgt f�r Probleme ???

		}
		else if(buffer[i] == '\0')
		{
			Faktor = pow(10, k - 1);

			for(j = 0; j < k; j++)
			{
				Tabelle[x][y] += Zwischenspeicher[j] * Faktor;
				Faktor /= 10;
			}

			k = 0;

		}
		else
		{
			Zwischenspeicher[k] = (int)buffer[i] - 48;
			k++;
		}
	}

	fclose(datei);

	return Tabelle;
}


int **CalcResults(int **TabelleIn)
/*
 * Funktionsname: CalcResults
 * Berechnet Werte f�r die unterschiedlichen Strecken
 * Eingabeparameter mit zul�ssigem Wertebereich: int TabelleIn[DIMENSION][DIMENSION]
 * R�ckgabeparameter mit zul�ssigem Wertebereich: int **TabelleOut[maxResults][5]
 * Autor: Cyriax, TH K�ln
 * Version: 4
 * Datum der letzten �nderung: 20.01.2018
 */
{
	int **TabelleOut; //R�ckgabe-Tabelle
	int i, //Z�hlvariable "Zeilencounter-Output"
		a, //Z�hlvariable "Halt 1"
		b, //Z�hlvariable "Halt 2"
		c, //Z�hlvariable "Halt 3"
		d, //Z�hlvariable "Halt 4"
		x, //Z�hlvariable Strecke x
		y, //Z�hlvariable Strecke y
		q, //Z�hlvariable Strecke 2 x
		p, //Z�hlvariable Strecke 2 y
		t, //Z�hlvariable Strecke 3 x
		z, //Z�hlvariable Strecke 3 y
		u, //Z�hlvariable Zeit	  x
		v, //Z�hlvariable Zeit    y
		k, //Z�hlvariable Zeit 2  x
		l, //Z�hlvariable Zeit 2  y
		m, //Z�hlvariable Zeit 3  x
		n; //Z�hlvariable Zeit 3  y

	int maxResults = pow(DIMENSION, 3); //Berechnen max. Anzahl an Streckenkombinationen

	// Allokieren des notwendigen Speichers

	TabelleOut = calloc(maxResults, sizeof(int *));

	for(i = 0; i < maxResults; i++)
	{
		TabelleOut[i] = calloc(6, sizeof(int));
	}

	i = 0;

	//--> Berechnung aller Kombinationen f�r zwei Halte

	for(a = 0; a < DIMENSION; a++)
	{
		for(b = 0; b < DIMENSION; b++)
		{
			if(a != b)
			//Nur wenn es unterschiedliche Haltestellen sind
			{
				TabelleOut[i][0] = a + 1; //Eintragen der Halte f�r die aktuelle Zeile
				TabelleOut[i][1] = b + 1;

				if (a > b) // Fall 1 (Bsp: 2-1)
				{
					x = abs(a - 3); //Berechnung der Koordinaten f�r die Verbindungsl�nge
					y = b;

					u = abs(y - 3); //Berechnung der Koordinaten f�r die Geschwindigkeit
					v = abs(x - 3);

					TabelleOut[i][4] = TabelleIn[x][y]; // Eintragen der Streckenl�nge
					TabelleOut[i][5] = round((float)(TabelleOut[i][4] * 60) / TabelleIn[u][v]); //Eintragen der Zeit in min
				}
				else // Fall 2 (Bsp: 1-2)
				{
					x = abs(b - 3);
					y = a;

					u = abs(y - 3);
					v = abs(x - 3);

					TabelleOut[i][4] = TabelleIn[x][y];
					TabelleOut[i][5] = round((float)(TabelleOut[i][4] * 60) / TabelleIn[u][v]);
				}

				i++; //Erh�hen der Zeilennummer
			}
		}
	}

	for(a = 0; a < DIMENSION; a++)
	{
		for(b = 0; b < DIMENSION; b++)
		{
			for(c = 0; c < DIMENSION; c++)
			{
				if(a != b && b != c && c != a)
				{
					TabelleOut[i][0] = a + 1;
					TabelleOut[i][1] = b + 1;
					TabelleOut[i][2] = c + 1;

					if(a > b && b > c)
					{
						x = abs(a - 3);
						y = b;
						q = abs(b - 3);
						p = c;

						TabelleOut[i][4] = TabelleIn[x][y] + TabelleIn[q][p];
					}
					else if(a > b && b < c)
					{
						x = abs(a - 3);
						y = b;
						q = abs(c - 3);
						p = b;

						TabelleOut[i][4] = TabelleIn[x][y] + TabelleIn[q][p];
					}
					else if(a < b && b > c)
					{
						x = abs(b - 3);
						y = a;
						q = abs(b - 3);
						p = c;

						TabelleOut[i][4] = TabelleIn[x][y] + TabelleIn[q][p];
					}
					else if(a < b && b < c)
					{
						x = abs(b - 3);
						y = a;
						q = abs(c - 3);
						p = b;

						TabelleOut[i][4] = TabelleIn[x][y] + TabelleIn[q][p];
					}

					u = abs(y - 3);
					v = abs(x - 3);
					k = abs(q - 3);
					l = abs(p - 3);

					TabelleOut[i][5] = round((((float)TabelleIn[x][y] / (float)TabelleIn[u][v]) + (((float)TabelleIn[q][p] / (float)TabelleIn[k][l]))) * 60 + 10);

					i++;
				}
			}
		}
	}

	for(a = 0; a < DIMENSION; a++)
	{
		for(b = 0; b < DIMENSION; b++)
		{
			for(c = 0; c < DIMENSION; c++)
			{
				for(d = 0; d < DIMENSION; d++)
				{
					if(a != b && b != c && c != d && a != c && a != d && b != d)
					{
						TabelleOut[i][0] = a + 1;
						TabelleOut[i][1] = b + 1;
						TabelleOut[i][2] = c + 1;
						TabelleOut[i][3] = d + 1;

						if(a > b && b > c && c > d)
						{
							x = abs(a - 3);
							y = b;
							q = abs(b - 3);
							p = c;
							t = abs(c - 3);
							z = d;

							TabelleOut[i][4] = TabelleIn[x][y] + TabelleIn[q][p] + TabelleIn[t][z];
						}
						else if(a > b && b > c && c < d)
						{
							x = abs(a - 3);
							y = b;
							q = abs(b - 3);
							p = c;
							t = abs(d - 3);
							z = c;

							TabelleOut[i][4] = TabelleIn[x][y] + TabelleIn[q][p] + TabelleIn[t][z];
						}
						else if(a > b && b < c && c > d)
						{
							x = abs(a - 3);
							y = b;
							q = b;
							p = abs(c - 3);
							t = abs(c - 3);
							z = d;

							TabelleOut[i][4] = TabelleIn[x][y] + TabelleIn[q][p] + TabelleIn[t][z];
						}
						else if(a > b && b < c && c < d)
						{
							x = abs(a - 3);
							y = b;
							q = b;
							p = abs(c - 3);
							t = abs(d - 3);
							z = c;

							TabelleOut[i][4] = TabelleIn[x][y] + TabelleIn[q][p] + TabelleIn[t][z];
						}
						else if(a < b && b > c && c > d)
						{
							x = abs(b - 3);
							y = a;
							q = abs(b - 3);
							p = c;
							t = abs(c - 3);
							z = d;

							TabelleOut[i][4] = TabelleIn[x][y] + TabelleIn[q][p] + TabelleIn[t][z];
						}
						else if(a < b && b > c && c < d)
						{
							x = abs(b - 3);
							y = a;
							q = abs(b - 3);
							p = c;
							t = abs(d - 3);
							z = c;

							TabelleOut[i][4] = TabelleIn[x][y] + TabelleIn[q][p] + TabelleIn[t][z];
						}
						else if(a < b && b < c && c > d)
						{
							x = abs(b - 3);
							y = a;
							q = b;
							p = abs(c - 3);
							t = abs(c - 3);
							z = d;

							TabelleOut[i][4] = TabelleIn[x][y] + TabelleIn[q][p] + TabelleIn[t][z];

						}
						else if(a < b && b < c && c < d)
						{
							x = abs(b - 3);
							y = a;
							q = b;
							p = abs(c - 3);
							t = abs(d - 3);
							z = c;

							TabelleOut[i][4] = TabelleIn[x][y] + TabelleIn[q][p] + TabelleIn[t][z];
						}

						u = abs(y - 3);
						v = abs(x - 3);
						k = abs(q - 3);
						l = abs(p - 3);
						m = abs(t - 3);
						n = abs(z - 3);

						TabelleOut[i][5] = round((((float)TabelleIn[x][y] / (float)TabelleIn[u][v]) + ((float)TabelleIn[q][p] / (float)TabelleIn[k][l]) + ((float)TabelleIn[t][z] / (float)TabelleIn[m][n])) * 60 + 20);

						i++;
					}
				}
			}
		}
	}

	return TabelleOut;
}

void printResult(int **Table)
/*
 * Funktionsname: printResult
 * Gibt die Tabelle mit den berechneten Werten aus
 * Eingabeparameter mit zul�ssigem Wertebereich: int **Table[maxResults][5]
 * R�ckgabeparameter mit zul�ssigem Wertebereich: -
 * Autor: Cyriax, TH K�ln
 * Version: 2
 * Datum der letzten �nderung: 20.01.2018
 */

{
	int i; //Z�hlvariable i
	int maxResults = pow(DIMENSION, 3); //Wert der definitiv �ber

	printf("Strecke\t\tLaenge[km]\tFahrzeit[min]\n");

	for(i = 0; i < maxResults; i++)
	//Schleife die alle Elemente der Tabelle durchl�uft
	{

		if (Table[i][0] != 0)
		//Nur wenn �berhaupt etwas in der Tabelle steht
		{
			//F�r unterschiedliche Kombinationen jeweils eine if-Abfrage

			if (Table[i][2] == 0 && Table[i][3] == 0)
				// Zweier Kombinationen
			{
				printf("  %i-%i\t\t %i\t\t %i", Table[i][0], Table[i][1], Table[i][4], Table[i][5]);
				printf("\n");
			}
			else if(Table[i][3] == 0)
				// Dreier Kombinationen
			{
				printf(" %i-%i-%i\t\t %i\t\t %i", Table[i][0], Table[i][1], Table[i][2], Table[i][4], Table[i][5]);
				printf("\n");
			}
			else
				// Vierer Kombinationen
			{
				printf("%i-%i-%i-%i\t\t %i\t\t %i", Table[i][0], Table[i][1], Table[i][2], Table[i][3], Table[i][4], Table[i][5]);
				printf("\n");
			}
		}

	}
}

int main(void) {

	int **Test; //Tabelle f�r die einzulesende Datei
	int **Table;//Tabelle f�r die zu berechnenden Werte

	Test = DateiEinlesen(); //Importieren der Datei

	Table = CalcResults(Test); //Berechnen der Werte

	printResult(Table); // Ausgeben der Werte

	return EXIT_SUCCESS;
}

