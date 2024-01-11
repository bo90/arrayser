//
// Created by Борис Левченков on 11.01.2024.
//
#include <stdio.h>
#include <stdlib.h>

struct queueNode{
    char data;
    struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;
void printQueue(QueueNodePtr currentPtr);
int isEmptyQue(QueueNodePtr headPtr);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr,
             char value);
void instructQueue();

void instructQueue() {
    printf("Enter your choice:\n"
           "    1 to add an item to the queue\n"
           "    2 to remove an item from the queue\n"
           "    3 to end\n");
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value) {
    QueueNodePtr newPtr = malloc(sizeof(QueueNode));
    if(newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        if(isEmptyQue(*headPtr)){
            *headPtr = newPtr;
        }else{
            (*tailPtr)->nextPtr = newPtr;
        }
        *tailPtr = newPtr;
    }else{
        printf("%c not inserted. No memory available.\n", value);
    }
}

char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) {
    char val;
    QueueNodePtr  tmpPtr;

    val = (*headPtr)->data;
    tmpPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    if(*headPtr == NULL){
        *tailPtr = NULL;
    }
    free(tmpPtr);
    return val;
}

int isEmptyQue(QueueNodePtr headPtr) {
    return headPtr == NULL;
}

void printQueue(QueueNodePtr currentPtr) {
    if(currentPtr == NULL){
        puts("Queue is empty.\n");
    }else{
        puts("The queue is:");
        while (currentPtr != NULL){
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        puts("NULL\n");
    }
}

int main(){
    QueueNodePtr headPtr = NULL;
    QueueNodePtr tailPtr = NULL;
    unsigned int choice;
    char item;

    instructQueue();
    printf("%s", "? ");
    scanf("%u", &choice);

    while (choice != 3){
        switch (choice) {
            case 1:
                printf("%s", "Enter a character: ");
                scanf("\n%c", &item);
                enqueue(&headPtr, &tailPtr, item);
                printQueue(headPtr);
                break;
            case 2:
                if(!isEmptyQue(headPtr)){
                    item = dequeue(&headPtr, &tailPtr);
                    printf("%c has been dequeued.\n", item);
                }
                printQueue(headPtr);
                break;
            default:
                puts("Invalid choice.\n");
                instructQueue();
                break;
        }
        printf("%s", "? ");
        scanf("%u", &choice);
    }
    puts("End od run.");
}