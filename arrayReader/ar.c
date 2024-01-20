//
// Created by Борис Левченков on 20.01.2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 100

void RandomItems(int arr[], int size);

int main(){

}

void RandomItems(int arr[], int size) {
    srand(time(NULL));
    for(int i = 0; i < size; ++i){
        int val = rand() % 100;
        arr[i] = val;
    }
}