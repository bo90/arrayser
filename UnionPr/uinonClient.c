//
// Created by borle on 01.02.2024.
//
#include <stdio.h>
#include "libs/equalent/UF.h"
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    int N = rand() / 100;
    int p, q;
    UFinit(N);

    while (scanf("%d  %d", &p, &q) == 2){
        if(!UFfind(p,q)){
            UFunion(p,q);
            printf("    %d  %d\n", p, q);
        }
    }
}