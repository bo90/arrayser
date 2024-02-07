//
// Created by borle on 07.02.2024.
//
#include <stdlib.h>
#include "Poly.h"

struct poly {
    int N;
    int *a;
};

P Poly_term(int cff, int expr){
    int i;
    P t = malloc(sizeof(*t));
    t->a = malloc((expr+1)*sizeof(int));
    t->N = expr+1;
    t->a[expr] = cff;

    for (int j = 0; j < expr; j++) {
        t->a[j] = 0;
    }
    return t;
}

P Poly_add(P org, P fut){
    int i;
    P t;

    if(org->N < fut->N){
        t = org;
        org = fut;
        fut = t;
    }

    for(i=0; i < fut->N; i++){
        org->a[i] += fut->a[i];
    }
    return org;
}

P Poly_mult(P p, P q){
    int i, j;
    P t = Poly_term(0, (p->N-1)+(q->N-1));
    for(i=0; i < p->N; i++){
        for(j=0; j < q->N; j++){
            t->a[i+j] += p->a[i]*q->a[j];
        }
    }
    return t;
}

float Poly_eval(P poly, float x){
    int i;
    double t = 0.0;
    for(i=poly->N-1; i >= 0; i--){
        t = t*x + poly->a[i];
    }
    return t;
}