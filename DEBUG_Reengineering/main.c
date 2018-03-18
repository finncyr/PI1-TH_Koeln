/*
 Dateiname : analyse.c
 Programm  : Gleitende Mittelwertberechnung über Messwerte derselben Messstelle
             Beispielhafte Musterlösung für Aufgabe 001 aus POOL3
 Eingaben  : keine (beim Programmaufruf)
             Programmaufruf über Konsole. Aufruf mit: ./analyse
 Ausgaben  : nicht verwendet (immer 0)
 Autor     :
 Version   : 01   vom   2013-01-09
 */

 #include "analyse.h"

/*
 Funktion  : word16 BerechneMittelwerte(Messung *md, word16 MesswertID, word16 MittelwertFenster, word16 AnzahlMesswerte, word16 *mpID)
 Aufgabe   : Berechnet die gleitenden Mittelwerte (double) ueber MittelwertFenster Messwerte (int) der
 	 	 	 Messtelle <MesswertID> aus dem nach aufsteigender MesswertID geordneten Messwertevektor md.
 	 	 	 Fuer die ersten MittelwertFenster-1 Messwerte wird als Mittelwert der Messwert genommen und
 	 	 	 als Status fuer den Mittelwert 1 gesetzt. Fuer berechnete Mittelwerte ist der Status 0.
 Eingaben  : md = strukturierter Messwertevektor enthält Messwerte aller gelesenen Messstellen, wobei
             die Messwerte einer Messtelle zeitlich und die Messstellen num. aufsteigend geordnet sind
             MesswertID = Messtelle, fuer die die Mittelwerte berechnet werden
             MittelwertFenster = Anzahl der in den Mittelwert einzubeziehenden Messwerte der Messstelle
             AnzahlMesswerte = Gesamtzahl der Messwerte im Messwertevektor
             mpID = Vektor mit Anzahl der Messzeitpunkte (Messwerte) je Messstelle
 Ausgaben  : Anzahl der berechneten Mittelwerte
 Autor     :
 Version   : 01
 Datum der letzten Änderung: 2013-01-09
 */
word16 BerechneMittelwerte(Messung *md, word16 MesswertID, word16 MittelwertFenster, word16 AnzahlMesswerte, word16 *mpID){

	char NameAusgabedatei[] = "mittelwerte_0_00.txt";
	char Ausgabezeile[81];
	char FormatStr[]="\n%15d\t%14d\t%28g\t%6d"; //Ausgabeformatierung

	word16 startIndex, AnzahlMittelwerte;

	struct{
		word16 ZeitIndex;
		word16 Status;
		word32 Wert;
	} ganzzahligerMesswert[MAXMESSZEITPUNKTE]={{0}};

	double Mittelwert=0, SummeFensterWerte=0, divisor;

	word16 i,j;
	FILE *fp;

	for(i = 0, startIndex = 0; i < MesswertID; i++){
		startIndex+=mpID[i];
	}

	printf("\n Ausgeben der verrechneten Messwerte und der Mittelwerte in Datei ...");

	fp = fopen(NameAusgabedatei,"w+");

	if(fp!=NULL){

		sprintf(Ausgabezeile,"%s\t%s%d%s\t%s%d%s\t%s", "Messzeitpunkt T","Messwert X",MesswertID, "(T)", "Mittelwert ueber ", MittelwertFenster, " Messwerte", "Status" );
		fwrite(Ausgabezeile,strlen(Ausgabezeile),1,fp);
	}

	fclose(fp);

	return AnzahlMittelwerte;
}

/*
 Funktion  : word16 LiesMesswerte(Messung *md, word16 *mpID)
 Aufgabe   : Liest maximal MAXMESSZEITPUNKTE strukturierte Messwerte aus der MESSDATEI
 	 	 	 für alle enthaltenen Messstellen in den Messwertevektor md und vermerkt die
 	 	 	 Anzahl der für jede Messstelle eingelesenen Messwerte im Vektor mpID
 Eingaben  : md = strukturierter Messwertevektor enthält alle eingelesenen Messwerte in der
 	 	 	 von der MESSDATEI vorgegebenen Reihenfolge. Es wird erwartet, dass die Messzeitpunkte
 	 	 	 zu jeder Messstelle in aufsteigender Reihenfolge vorliegen.

 	 	 	 mpID = Vektor mit Anzahl der gelesenen Messwerte zu jeder erlaubten Messstelle (ID)
 Ausgaben  : Anzahl gelesener Messwerte insgesamt
 Autor     :
 Version   : 01
 Datum der letzten Änderung: 2013-01-09
 */

word16 LiesMesswerte(Messung *md, word16 *mpID) {

  word16 i = 0, j = 0;
  char eineZeile[41], *eZp;
  size_t result=0;
  FILE *fp;

  printf("\n Einlesen der Messwerte von Datei ...");

  fp = fopen(MESSDATEI, "r");

  for(i = 0; i < MAXMESSZEITPUNKTE; i++) {

	  if(fp != NULL){

		  if(fscanf(fp, "%i,%i,%i,%i\n", &md->id, &md->ZeitIndex, &md->Wert, &md->Status) != 4){
			  return 0;
		  }
		  else{
			  j++;
		  }
	  }
  }

  rewind(fp);
  fclose(fp);

  return j; // Anzahl gelesener Messwerte insgesamt
}

/*
 Funktion  : BOOL LiesParameter(word16 *AnzahlWerte4MW, word16 *id, word16 *AnzahlMesswerte)
 Aufgabe   :
 Eingaben  :
 Ausgaben  :
 Autor     : Kreiser
 Version   : 01
 Datum der letzten Änderung: 2013-01-09
 */
BOOL LiesParameter(word16 *AnzahlWerte4MW, word16 *id, word16 *AnzahlMesswerte){

  BOOL error = TRUE;

  printf ("\nFuer welche MesswertID sollen Mittelwerte berechnet werden ? :\t");

  scanf("%hd", id);

  fflush (stdin); // NOTIZ AN FINN: FFLUSH GEHT UNTER LINUX NICHT!!!!!!!

  if (*id < MAXMESSSTELLEN){

	  if (AnzahlMesswerte[*id]>0){

	  	  printf ("\nWieviele Messwerte sollen im Mittelwert beruecksichtigt werden ? :\t");
	  	  scanf("%hd", AnzahlWerte4MW);

	  	  fflush (stdin);

	  	  if ((*AnzahlWerte4MW > 0) && (*AnzahlWerte4MW <= AnzahlMesswerte[*id])){
	  		  error = FALSE;
	  	  }
	  }
  }

  return error;
}

/*
 Funktion  : word16 VerarbeiteMesswerte(Messung *md, word16 *mpID, word16 *AnzahlMesswerte)
 Aufgabe   : Sortiert und vervollständigt den strukturierten Messwertevektor md:
 	 	 	 Sortierung aufsteigend nach MesstellenID,
 	 	 	 Auffuellen fehlender Messzeitpunkte, falls zur MessstellenID Messwerte fuer einen
 	 	 	 vorausgehenden und einen nachfolgenden Messzeitpunkt vorhanden sind (eingelesen wurden).
 	 	 	 Fuer fehlende Messzeitpunkte wird der Wert des letzten eingelesenen Messzeitpunkts kopiert.
 Eingaben  : md = strukturierter Messwertevektor enthält alle eingelesenen Messwerte in der
 	 	 	 von der MESSDATEI vorgegebenen Reihenfolge. Es wird erwartet, dass die Messzeitpunkte
 	 	 	 zu jeder Messstelle in aufsteigender Reihenfolge vorliegen.
 	 	 	 mpID = Vektor mit Anzahl der gelesenen Messwerte zu jeder erlaubten Messstelle
 	 	 	 AnzahlMesswerte = Anzahl der Werte im Vektor md
 Ausgaben  : md = strukturierter Messwertevektor enthält vervollstaendigte Messwerte zu jeder
 	 	 	 zu jeder Messstelle in aufsteigender Reihenfolge der Messzeitpunkte. Dabei sind die
 	 	 	 Messstellen ebenfalls in aufsteigender Reihenfolge im Vektor hinterlegt.
 	 	 	 mpID = Vektor mit Anzahl der vervollstaendigten Messwerte zu jeder erlaubten Messstelle.
 	 	 	 AnzahlMesswerte = Anzahl der vervollstaendigten Werte im Vektor md
 	 	 	 Rueckgabewert: Anzahl ergaenzter Messwerte insgesamt (alle Messstellen)
 Autor     :
 Version   : 01
 Datum der letzten Änderung: 2013-01-09
 */

word16 VerarbeiteMesswerte(Messung *md, word16 *mpID, word16 *AnzahlMesswerte) {

  word16 i,j,k, AnzahlErgaenzteMesswerte;

  word32 ZeitIndex, maxZeitIndex[MAXMESSSTELLEN], minZeitIndex[MAXMESSSTELLEN];

  Messung vMesswerte[MAXMESSWERTE]={0};
  //minimalen und maximalen Zeitindex fuer die zu verarbeitenden Messstellen bestimmen

  // Berechnung der Anzahl vorhandener Messzeitpunkte zur Messstelle und Anzahl der vorhandenen Messstellen

  //Verarbeite alle erlaubten MessstellenIDs

  for(i=0,k=0;i<MAXMESSSTELLEN;i++){ //i: Laufindex Messwertevektor, k: Laufindex vervollst. Messwertevektor

  } //for i
  AnzahlErgaenzteMesswerte=k-*AnzahlMesswerte;
  *AnzahlMesswerte=k; //Anzahl inkl. ergaenzter Messwerte
  //Zurueckspeichern der verarbeiteten Messwerte in den Messwertevektor md
  memcpy(&md[0], &vMesswerte[0], k*sizeof(Messung));
  return (AnzahlErgaenzteMesswerte);
}

int main(void){
  Messung  Messwerte[MAXMESSWERTE]={{0}};
  word16   AnzahlMesszeitpunkteID[MAXMESSSTELLEN]={0};
  word16   AnzahlEingelesen, AnzahlMesswerte, AnzahlErgaenzteMesswerte, AnzahlWerteImMittelwert;
  word16   AnzahlMittelwerte, ID, i;
  BOOL     ende;

  AnzahlEingelesen = LiesMesswerte(Messwerte, AnzahlMesszeitpunkteID);

  printf ("\nAnzahl eingelesener Messwerte:\t %d", AnzahlEingelesen);

  for(i = 0; i < MAXMESSSTELLEN; i++){

	  if(AnzahlMesszeitpunkteID[i] > 0){

		  printf("\nAnzahl eingelesener Messwerte zur MesstellenID %d:\t %d", i, AnzahlMesszeitpunkteID[i]);
	  }
  }

  AnzahlErgaenzteMesswerte = VerarbeiteMesswerte(Messwerte, AnzahlMesszeitpunkteID, &AnzahlMesswerte);

  printf("\nGesamtanzahl ergaenzter Messwerte:\t %d", AnzahlErgaenzteMesswerte);

  for(i = 0; i < MAXMESSSTELLEN; i++) {

	  if(AnzahlMesszeitpunkteID[i] > 0) {

		  printf("\nAnzahl verarbeitbarer Messwerte zur MesstellenID %d:\t %d", i, AnzahlMesszeitpunkteID[i]);
	  }
  }

  do {
	ende = LiesParameter(&AnzahlWerteImMittelwert, ID, AnzahlMesszeitpunkteID);

      if(ende){
    	  AnzahlMittelwerte = BerechneMittelwerte(Messwerte, ID, AnzahlWerteImMittelwert, AnzahlMesswerte, AnzahlMesszeitpunkteID);
      }
  }
  while(ende);

  printf("Ende");

  return 0;
}

