#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main () {
    int wresErgasias;
    long wriaiaAntimisthia,katharesApodoxes;
    double posostoKrathsewn,krathseis,akatharistesApodoxes;

    printf ("Dwse ton arithmo twn wrwn:");
    wresErgasias = GetInteger();
    printf ("Dwse thn wriaia antimisthia:");
    wriaiaAntimisthia = GetLong();
    printf ("Dvse to pososto twn krathsewn:");
    posostoKrathsewn = GetReal();
    katharesApodoxes=wresErgasias * wriaiaAntimisthia;
    krathseis=(double) katharesApodoxes * posostoKrathsewn;
    akatharistesApodoxes=(double) katharesApodoxes + krathseis;
    printf("Oi akatharistes apodoxes einai %g\n",akatharistesApodoxes);
    printf("Oi krathseis einai %g\n",krathseis);
    printf("Oi kathares apodoxes einai %ld\n",katharesApodoxes);
}

