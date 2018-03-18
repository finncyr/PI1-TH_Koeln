/*
 Dateiname : analyse.h
 Programm  : Enthaelt Definitionen und Includes fuer das Programm analyse.c
 Autor     : Kreiser, F07 FH-Köln
 Version   : 01   vom   2013-01-09
 */

// Definitionen
#define MESSDATEI "werte.txt"
#define MAXMESSZEITPUNKTE 50
#define MAXMESSSTELLEN 5
#define MAXMESSWERTE MAXMESSZEITPUNKTE*MAXMESSSTELLEN

/* erforderliche Bibliotheken */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Typdeklarationen */
typedef enum {FALSE, TRUE} BOOL;
typedef unsigned short word16;
typedef unsigned int word32;
typedef struct{
	word16 id;
	word32 ZeitIndex;
	word32 Wert;
	word16 AnzahlDezimaleNachkommastellen;
	word16 Status;
} Messung;

/* Funktionssignaturen */
word16 BerechneMittelwerte(Messung *md, word16 MesswertID, word16 MittelwertFenster, word16 AnzahlMesswerte, word16 *mpID);
word16 LiesMesswerte(Messung *md, word16 *mpID);
word16 VerarbeiteMesswerte(Messung *md, word16 *mpID, word16 *AnzahlMesswerte);
BOOL LiesParameter(word16 *AnzahlWerte4MW, word16 *id, word16 *AnzahlMesswerte);

