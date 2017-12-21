#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char StringA[101], StringB[101];

    printf("Geben sie den ersten String ein:\n");
    scanf("%s", &StringA[0]);

    printf("Geben sie den zweiten String ein:\n");
    scanf("%s", &StringB[0]);

    printf("Laenge String 1: %i\n", strlen(StringA));
    printf("Laenge String 2: %i\n", strlen(StringB));

    printf("Ergebnis StrCmp: %i\n", strcmp(StringA, StringB));

    printf("Zusammengesetzter String: %s", strcat(StringA, StringB));

    return 0;
}
