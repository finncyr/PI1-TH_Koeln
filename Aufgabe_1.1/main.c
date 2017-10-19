#include <stdio.h>
#include <stdlib.h>

int main()
{
    int eins,zwei;

    printf("Geben Sie eine Zahl ein.\r\n");
    scanf("%d",&eins);
    printf("Geben Sie eine zweite Zahl ein.\r\n");
    scanf("%d",&zwei);

    eins=eins*zwei;
    eins+=zwei*5;
    eins-=eins*3;

    printf("Das Ergebnis ist: %d",eins);

    return 0;
}
