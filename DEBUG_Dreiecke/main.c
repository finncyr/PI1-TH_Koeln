/*
 Dateiname : Dreiecke.c
 Programm  : Das Programm berechnet sämtliche Parameter eines
 	 	 	 Dreiecks bei eingegebenen Eckkoordinaten im drei-
 	 	 	 dimensionalen Raum.
 Eingaben  : KEINE Parametereingabe bei Programmaufruf über Konsole.
 Ausgaben  : Rückgabewerte des Programms (int):
             0 falls keine Fehler
			 -1 falls kein Dreieck entsteht
 Autor     : Cyriax, TH Köln
 Version   : 13 vom 23.01.2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _USE_MATH_DEFINES

int main() {

	float A[2], 	//Ortsvektor Punkt A
		  B[2], 	//Ortsvektor Punkt B
		  C[2]; 	//Ortsvektor Punkt C
	float CheckInput[2]; //Überprüfen der Eingaben
	float lAB,  	//Länge zwischen A und B
		  lAC,  	//Länge zwischen A und C
		  lBC,  	//Länge zwischen B und C
		  lBA;  	//Länge zwischen B und A
	float U;    	//Umfang des Dreiecks
	float phiA, 	//Winkel am Punkt A
		  phiB, 	//Winkel am Punkt B
		  phiC; 	//Winkel am Punkt C
	float F;    	//Flächeninhalt
	float S1[2],	//Schnittpunkt Seite AC mit der Mittelsenkrechten von AC
		  S2[2], 	//Schnittpunkt Seite BC mit der Mittelsenkrechten von AC
		  MBC[2],   //Mittelpunkt der Strecke BC
		  S1toS2[2],//Vektor von Schnittpunkt 1 zu Schnittpunkt 2
		  lS1toS2,  //Länge zwischen beiden Schnittpunkten
		  lS2MU;	//Länge zwischen Schnittpunkt 2 und dem gesuchten Mittelpunkt des Umkreises
	float rI, 		//Radius Inkreis
	 	  MI[2], 	//Mittelpunkt Inkreis
		  rU, 		//Radius Umkreis
		  MU[2];	//Mittelpunkt Umkreis
	float SwP[2];	//Schwerpunkt



	printf("Geben sie die Kordinaten des Punktes A ein: (x,y,z)\n");
	scanf("%f,%f,%f", &A[0], &A[1], &A[2]);

	printf("Geben sie die Kordinaten des Punktes B ein: (x,y,z)\n");
	scanf("%f,%f,%f", &B[0], &B[1], &B[2]);

	printf("Geben sie die Kordinaten des Punktes C ein: (x,y,z)\n");
	scanf("%f,%f,%f", &C[0], &C[1], &C[2]);


	// --------CHECK DER EINGABEN-------- //

	CheckInput[0] = ( (B[1] - A[1])*(C[2] - A[2]) - (B[2] - A[2])*(C[1] - A[1]) );
	CheckInput[1] = ( (B[2] - A[2])*(C[0] - A[0]) - (B[0] - A[0])*(C[2] - A[2]) );
	CheckInput[2] = ( (B[0] - A[0])*(C[1] - A[1]) - (B[1] - A[1])*(C[0] - A[0]) );

	if( sqrt(pow(CheckInput[0], 2) + pow(CheckInput[1], 2) + pow(CheckInput[2], 2)) == 0)
	{
		printf("\nPUNKTE ERGEBEN KEIN DREIECK!\n");
		return -1;
	}


	// ---------SEITENLAENGEN------------ //

	lAB = (float)sqrt(pow((B[0] - A[0]), 2) + pow((B[1] - A[1]), 2) + pow((B[2] - A[2]), 2));
	lAC = (float)sqrt(pow((C[0] - A[0]), 2) + pow((C[1] - A[1]), 2) + pow((C[2] - A[2]), 2));
	lBC = (float)sqrt(pow((C[0] - B[0]), 2) + pow((C[1] - B[1]), 2) + pow((C[2] - B[2]), 2));
	lBA = (float)sqrt(pow((A[0] - B[0]), 2) + pow((A[1] - B[1]), 2) + pow((A[2] - B[2]), 2));


	// --------------UMFANG-------------- //

	U = (float)lAB + lAC + lBC;


	// -----------INNENWINKEL------------ //

	phiA = (float)(180 / M_PI) * acos((double)((B[0] - A[0])*(C[0] - A[0]) + (B[1] - A[1])*(C[1] - A[1]) + (B[2] - A[2])*(C[2] - A[2]))/(lAB * lAC));
	phiB = (float)(180 / M_PI) * acos((double)((C[0] - B[0])*(A[0] - B[0]) + (C[1] - B[1])*(A[1] - B[1]) + (C[2] - B[2])*(A[2] - B[2]))/(lBC * lBA));
	phiC = (float)180 - phiA - phiB;


	// -----------FLAECHENINHALT--------- //
	//             nach Heron             //

	F = (float)sqrt((U/2) * ((U/2) - lAB) * ((U/2) - lAC) * ((U/2) - lBC));


	// -------------INKREIS------------- //

	MI[0] = (float)(1/U) * (lBC*A[0] + lAC*B[0] + lAB*C[0]);
	MI[1] = (float)(1/U) * (lBC*A[1] + lAC*B[1] + lAB*C[1]);
	MI[2] = (float)(1/U) * (lBC*A[2] + lAC*B[2] + lAB*C[2]);

	rI = (float)sqrt( pow(( (MI[1] - A[1])*(B[2] - A[2]) - (MI[2] - A[2])*(B[1] - A[1]) ), 2) + pow( ((MI[2] - A[2])*(B[1] - A[1]) - (MI[1] - A[1])*(B[2] - A[2])) , 2) + pow( ((MI[0] - A[0])*(B[1] - A[1]) - (MI[1] - A[1])*(B[0] - A[0])) , 2) ) / lAB;


	// -------------UMKREIS------------- //

	rU = (float)(lAB * lAC * lBC) / (4 * F);

	S1[0] = (float)A[0] + (0.5 * (C[0] - A[0])); //Schnittpunkt Seite AC und Mittelsenkrechte AC
	S1[1] = (float)A[1] + (0.5 * (C[1] - A[1]));
	S1[2] = (float)A[2] + (0.5 * (C[2] - A[2]));

	S2[0] = (float)C[0] + (((lAC / 2) / (cos((double)phiC * M_PI/180))) / lBC) * (B[0] - C[0]); //Schnittpunkt Seite BC und Mittelsenkrechte AC
	S2[1] = (float)C[1] + (((lAC / 2) / (cos((double)phiC * M_PI/180))) / lBC) * (B[1] - C[1]);
	S2[2] = (float)C[2] + (((lAC / 2) / (cos((double)phiC * M_PI/180))) / lBC) * (B[2] - C[2]);

	MBC[0] = (float)((B[0] - C[0])/2) + C[0]; //Mittelpunkt Seite BC
	MBC[1] = (float)((B[1] - C[1])/2) + C[1];
	MBC[2] = (float)((B[2] - C[2])/2) + C[2];

	S1toS2[0] = (float)S2[0] - S1[0]; //Vektor zwischen den beiden Schnittpunkten
	S1toS2[1] = (float)S2[1] - S1[1];
	S1toS2[2] = (float)S2[2] - S1[2];

	lS1toS2 = (float)sqrt(pow(S1toS2[0], 2) + pow(S1toS2[1], 2) + pow(S1toS2[2], 2)); // Länge zwischen den Schnittpunkten

	lS2MU = (float)(sqrt(pow(S2[0] - MBC[0], 2) + pow(S2[1] - MBC[1], 2) + pow(S2[2] - MBC[2], 2) ))/(cos((M_PI/180) * (90 - phiC)));
	//Länge zwischen Schnittpunkt 2 und dem gesuchten Punkt

	MU[0] = (float)S1[0] + ((S1toS2[0] / lS1toS2) * (lS1toS2 - lS2MU)); //Berechnung Mittelpunkt Umkreis
	MU[1] = (float)S1[1] + ((S1toS2[1] / lS1toS2) * (lS1toS2 - lS2MU));
	MU[2] = (float)S1[2] + ((S1toS2[2] / lS1toS2) * (lS1toS2 - lS2MU));


	// ----------SCHWERPUNKT---------- //

	SwP[0] = (float)(A[0] + B[0] + C[0]) / 3;
	SwP[1] = (float)(A[1] + B[1] + C[1]) / 3;
	SwP[2] = (float)(A[2] + B[2] + C[2]) / 3;

	// ###### AUSGABE DER WERTE ###### //

	printf("\n");
	printf("Seitenlaenge AB:   %f\n", lAB);
	printf("Seitenlaenge AC:   %f\n", lAC);
	printf("Seitenlaenge BC:   %f\n", lBC);
	printf("\n");
	printf("Umfang:            %f\n", U);
	printf("Flacheninhalt:     %f\n", F);
	printf("\n");
	printf("Innenwinkel phiA:  %f\n", phiA);
	printf("Innenwinkel phiB:  %f\n", phiB);
	printf("Innenwinkel phiC:  %f\n", phiC);
	printf("\n");
	printf("MP Innenkreis:     (%.2f;%.2f;%.2f)\n", MI[0]+0.005, MI[1]+0.005, MI[2]+0.005);
	printf("Radius Inkreis:    %f\n", rI);
	printf("\n");
	printf("MP Umkreis:        (%.2f;%.2f;%.2f)\n", MU[0]+0.005, MU[1]+0.005, MU[2]+0.005);
	printf("Radius Umkreis:    %f\n", rU);
	printf("\n");
	printf("Schwerpunkt:       (%.2f;%.2f;%.2f)\n", SwP[0]+0.005, SwP[1]+0.005, SwP[2]+0.005);

	return 0;
}
