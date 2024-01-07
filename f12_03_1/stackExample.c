//
// Created by Борис Левченков on 06.01.2024.
//

#include <stdio.h>
#include <stdlib.h>

struct stackNode{
    int data;
    struct stackNode *nextNodePtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, int result);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructionsStack();

int main(){
    StackNodePtr  stackPtr = NULL;
    unsigned int choice;
    int value;

    instructionsStack();
    printf("%s", "? ");
    scanf("%u", &choice);

    while (choice != 3){
        switch (choice) {
            case 1:
                printf("%s", "Enter an integer: ");
                scanf("%d", &value);
                push(&stackPtr, value);
                printStack(stackPtr);
                break;
            case 2:
                if(!isEmpty(stackPtr)){
                    printf("The popped value is %d.\n", pop(&stackPtr));
                }
                printStack(stackPtr);
                break;
            default:
                puts("Invalid choice.\n");
                instructionsStack();
                break;
        }
        printf("%s", "? ");
        scanf("%u", &choice);
    }
    puts("End of run.");
}

//insert rec
void push(StackNodePtr *topPtr, int result) {
    StackNodePtr newPtr = malloc(sizeof(StackNode));

    if(newPtr != NULL){
        newPtr->data = result;
        newPtr->nextNodePtr = *topPtr;
        *topPtr = newPtr;
    }else{
        printf("$d not inserted. NO memory available.\n", result);
    }
}

int pop(StackNodePtr *topPtr) {
    StackNodePtr tempPtr;
    int popValue;

    tempPtr = *topPtr;
    popValue = (*topPtr)->data;
    *topPtr=(*topPtr)->nextNodePtr;
    free(tempPtr);
    return popValue;
}

int isEmpty(StackNodePtr topPtr) {
    return topPtr == NULL;
}

void printStack(StackNodePtr currentPtr) {
    if(currentPtr == NULL){
        puts("The stack is empty.\n");
    }else{
        puts("The stack is: ");
        while (currentPtr != NULL){
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextNodePtr;
        }
        puts("NULL\n");
    }
}

void instructionsStack() {
    puts("Enter choice:\n"
         "1 to push a value on the stack\n"
         "2 to pop a value off the stack\n"
         "3 to end program");
}
