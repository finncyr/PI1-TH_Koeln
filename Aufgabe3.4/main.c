#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loescheSonderzeichen(char *satz)
{
    int i;

    for(i = 0; i <= strlen(satz); i++)
    {
        if((satz[i] > 96 && satz[i] < 123 || satz[i] > 64 && satz[i] < 91))
        {
            memmove(satz[i], satz[i+1] , strlen(satz) - i);
        }
        else
        {
           // memmove(satz[i], satz[i+1] , strlen(satz) - i);

            //realloc(satz, strlen(satz);
        }
    }

    return;
}

int main()
{
    char *Satz1 = calloc(100, sizeof(char));
    char *Satz2 = calloc(100, sizeof(char));

    //scanf("%s", &Satz1[0]);
    fgets(Satz1, 100, stdin);

    loescheSonderzeichen(Satz1);

    printf("%s\n", Satz1);

    return 0;
}
