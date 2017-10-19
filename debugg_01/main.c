/*
    Nummer: 228 & 238
    Cyriax, Finn, Matrikel-Nr.: 11124865
    Taschbach, Jan, Matrikel-Nr.:
    Aufgabenbeschreibung: Aufgabe 0.2
    Datum: 18.10.2017
    Version: 1.0
*/
#include <stdio.h>
#include <stdlib.h>

#define SHORT_MAX  32767


short foo(short x){
    //Bildschirmausgabe mit Zeilenumbruch \n
    printf("In der Funktion foo()\n");
    //Bildschirmausgabe mit Werten der Variablen x und x+1
    printf("x = %d\tx + 1 = %d\n",x,x+1);
    //Rückgabewert der Funktion foo()
    //1, wenn Ausdruck korrekt, 0 wenn Ausdruck falsch
    return (x + 1) > x;
}


int main(){
    //Variablen-Deklaration und Variablen-Initialisierung
    int a = SHORT_MAX, b = SHORT_MAX + 1;
    short rueckFunk = 0;

    printf("Einfuehrung Debugger\n\n");
    printf("Team-Nr.: XXX \n\n");

    if (a > b)
        //Ausgabe der Werte von a und b
        printf("a ist > b, weil\n\t a = %d \n und\n\t b = %d\n\n",a,b);
    else
        printf("a ist < b, weil\n\t a = %d \n und\n\t b = %d\n\n",a,b);

    //Aufruf der Funktion foo() und Speichern des Rückgabewerts von foo() in rueckFunk
    rueckFunk = foo(a);
    printf("Rueckgabewert von foo: %d\n\n\n", rueckFunk); //Ausgabe von rueckFunk
    return 0;
}

