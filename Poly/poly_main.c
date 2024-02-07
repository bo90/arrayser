//
// Created by borle on 07.02.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Poly.h"

int main(){
    srand(time(NULL));
    int N = rand() % 1000;

    float p = (rand() % 100) / 100;
    P t, x;
    int i,j;

    printf("Binomial coefficients\n");
    t= Poly_add(Poly_term(1,1), Poly_term(1,0));

    for(i=0, x = t; i < N; i++){
        x = Poly_mult(t,x);
        showPoly(x);
    }
    printf("%f\n", Poly_eval(x, p));
}
