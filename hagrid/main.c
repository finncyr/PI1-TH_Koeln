#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    char name[] = "hagrid0000";
    char end[] = ".txt";
    FILE *fp;

    for(i = 1; i <= 999; i++){

        if(i < 10){
            itoa(i, &name[9], 10);
        }
        else if(i < 100){
            itoa(i, &name[8], 10);
        }
        else if(i < 1000){
            itoa(i, &name[7], 10);
        }

        strcat(name, end);

        fp = fopen(name, "w");

        fprintf(fp, "you are a wizard");

        fclose(fp);

    }

    return 0;
}
