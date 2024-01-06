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
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;

    if(value == (*sPtr)->data){
        tempPtr = *sPtr;
        *sPtr = (*sPtr);
        free(tempPtr);
        return value;
    }else{
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;

        while (currentPtr != NULL && currentPtr->data != value){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if(currentPtr != NULL){
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return '\0';
}

int isEmpty(ListNodePtr sPtr) {
    return sPtr == NULL;
}

void printList(ListNodePtr currentPtr) {
    if(isEmpty(currentPtr)){
        puts("List is empty.\n");
    }else{
        puts("The list is: ");
        while (currentPtr != NULL){
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        puts("NULL\n");
    }
}

void instructions() {
    puts("Enter your choice:\n"
         "1 to insert an element into the list.\n"
         "2 to delete an element from the list.\n"
         "3 to end.");
}
