#include <stdlib.h>
#include <stdio.h>

typedef struct Vektor2 // Als Variablentyp
{
  float x;
  float y;
} Vektor2;

int main(void)
{
  struct Vektor3 //Definition der Struktur
  {
    float x;   //Elemente
    float y;
    float z;
  } A, B, C; //Definierte Variablen


  Vektor2 T; //Variable mit typedef

  T.x = 23;
  T.y = 24;

  A.x = 1;
  A.y = 1;
  A.z = 1;

  B.x = 0;
  B.y = 12;
  B.z = 0;

  printf("%.2f\n%.2f\n%.2f\n\n", A.x, A.y, A.z); // Aufrufen einer Struktur
  printf("%.2f\n%.2f\n", T.x, T.y);

  return 0;
}
