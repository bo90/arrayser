//
// Created by borle on 07.02.2024.
//

#ifndef FIG12_03_CMPLX_H
#define FIG12_03_CMPLX_H

#endif //FIG12_03_CMPLX_H

typedef struct complex *Complex;
Complex COMPLEX_init(float, float);
float   Re(Complex);
float   Im(Complex);
Complex COMPLEX_mult(Complex, Complex);
