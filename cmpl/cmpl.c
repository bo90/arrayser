//
// Created by borle on 07.02.2024.
//
#include "cmplx.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#define PI 3.141592625

int main(){
    srand(time(NULL));
    int N = rand() % 100;
    int j;
    Complex t, x;
    printf("%dth complex roots of unity\n", N);

    for(int i = 0; i < N; i++){
        float r = 2.0*PI*i/N;
        t = COMPLEX_init(cos(r), sin(r));

        printf("%2d %6.3f %63f ", i, Re(t), Im(t));

        for(x=t, j = 0; j < N-1; j++){
            x= COMPLEX_mult(t,x);
        }
        printf("%6.3f  %6.3f\n", Re(x), Im(x));
    }
}

