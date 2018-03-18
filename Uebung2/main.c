#include <stdio.h>
#include <stdlib.h>

int main()
{
    char statSatz[6][10] = {"Hello", "World", "how", "beautiful", "are", "thou"};
    char **Satz;

    Satz = calloc(6, sizeof(char *));

    for(int i = 0; i <= 6; i++)
    {
        Satz[i] = calloc(10, sizeof(char));
    }

    Satz[0] = "Hello";
    Satz[1] = "World";
    Satz[2] = "how";
    Satz[3] = "beautiful";
    Satz[4] = "are";
    Satz[5] = "thou";

    for(int i = 0; i <= 6; i++)
    {
        printf("%s ", Satz[i]);
    }

    printf("\n");

    for(int i = 0; i < 6; i++)
    {
        printf("%s ", statSatz[i]);
    }

    return 0;
}
