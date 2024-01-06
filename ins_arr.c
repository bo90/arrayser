#include <stdio.h>
#include <stdlib.h>

struct listNode{
    char data;
    struct listNode *nextPtr;
};
// alias
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

//Prototypes
void insert (ListNodePtr *sPtr, char value);
char delete (ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions();

int main(){

}

void insert(ListNodePtr *sPtr, char value)
{
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    // create new node
    newPtr = malloc(sizeof(ListNode));

    if(newPtr!=NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        previousPtr = NULL;
        currentPtr = *sPtr;

        while (currentPtr != NULL){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if(previousPtr == NULL){
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }else{
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }else{
        printf("%c not inserted. NO memory available.\n", value);
    }
}

char delete (ListNodePtr *sPtr, char value){

}

int isEmpty(ListNodePtr sPtr) {
    return 0;
}

void printList(ListNodePtr currentPtr) {

}

void instructions() {

}
