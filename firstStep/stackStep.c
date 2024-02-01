//
// Created by Борис Левченков on 25.01.2024.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "libs/stackLib/Item.h"
#include "libs/stackLib/Stack.h"

int main(){
    srand(time(NULL));
    char a[] = {0};
    int i, N;
    N = 10;

    for(i = 0; i < N; i++){
        if(a[i] == '+'){
            STACKpush(STACKpop());
        }
        if(a[i] == '*'){
            STACKpush(STACKpop());
        }
    }
}