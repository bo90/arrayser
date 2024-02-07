//
// Created by borle on 07.02.2024.
//

#ifndef FIG12_03_POLY_H
#define FIG12_03_POLY_H

#endif //FIG12_03_POLY_H

typedef struct poly *P;
void showPoly(P);
P Poly_term(int, int);
P Poly_add(P, P);
P Poly_mult(P, P);
float Poly_eval(P, float );