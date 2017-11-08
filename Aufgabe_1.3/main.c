#include <stdio.h>
#include <stdlib.h>
#include <math.h>

short zahl, zZt, zT, zH, zZ, zE;

int main()
{
    printf("Bitte geben sie eine Zahl ein: (max. 32767)\n");
    scanf("%d", &zahl);

    zZt  = (zahl % 100000)/10000;
    zT   = (zahl % 10000) /1000;
    zH   = (zahl % 1000)  /100;
    zZ   = (zahl % 100)   /10;
    zE   = (zahl % 10);

    printf("\n");
    printf("zZt:\t %d \n", zZt);
    printf("zT: \t %d \n", zT);
    printf("zH: \t %d \n", zH);
    printf("zZ: \t %d \n", zZ);
    printf("zE: \t %d \n", zE);

    return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        