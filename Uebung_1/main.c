#include <stdio.h>
#include <stdlib.h>

float Verbrauch, Tank, Strecke;

int main()
{
    printf("Wie viel Getankt? (Liter)\n");
    scanf("%f", &Tank);
    //if(Tank <= 0){return 0;}
    printf("Wie viel Gefahren? (km)\n");
    scanf("%f", &Strecke);
    //if(Strecke <= 0){return 0;}
    Verbrauch = (Tank/Strecke)*100;
    printf("Der Verbrauch: %f Liter pro 100 km!", Verbrauch);
    return 0;
}
