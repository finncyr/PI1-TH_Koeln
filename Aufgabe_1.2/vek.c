#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _USE_MATH_DEFINES

float betrag, winkel, x, y, bogenmas;

int main()
{
    printf("Bitte geben sie den Betrag und Winkel (in Grad) durch ein Leerzeichen getrennt ein: (Betrag Winkel)\n\n");
    scanf("%f %f", &betrag, &winkel);

    betrag = fabs(betrag);
    bogenmas = winkel*M_PI/180;

    x = betrag * cos(bogenmas);
    y = betrag * sin(bogenmas);

    printf("Das Ergebnis lautet: \n\n Betrag:\t%.02f\n Winkel:\t%.02f\n\n X:\t\t%.02f\n Y:\t\t%.02f\n\n", betrag, winkel, x, y);
    return 0;
}
