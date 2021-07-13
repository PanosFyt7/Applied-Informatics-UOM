#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main () {
    int ilikia,upsos;
    double varos,BMR;

    printf ("Dwse varos se kila :");
    varos = GetReal();
    printf ("Dwse upsos se cm :");
    upsos = GetReal();
    printf ("Dwse ilikia se xronia:");
    ilikia = GetInteger();
    BMR = 655 + (9.6*varos) + (1.8*upsos) - (4.7*ilikia);
    printf ("To BMR einai %g\n",BMR);

}
