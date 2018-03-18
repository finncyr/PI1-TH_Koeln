#include <stdio.h>
#include <stdlib.h>

void selectionSort(double X[], int Anzahl);

int main()
{
    int Menu, Anz;

    do{

        printf("1.)  Werte einlesen\n");
        printf("2.)  Sortiere\n\n");

        printf("Menuenummer eingeben: ");
        scanf("%i", &Menu);

        switch(Menu)
        {
        case 1:

            printf("\n\nAnzahl eingeben: ");
            scanf("%i", &Anz);



            break;

        case 2:

            break;

        case default:

            break;
        }
    } while(Menu == 2 || Menu == 3);

    return 0;
}
