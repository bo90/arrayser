#include <stdio.h>
#include <stdlib.h>

struct listnNode{
    char data;
    struct listnNode *nextPtr;
};
// alias
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

//Prototypes
void insert (ListNodePtr *sPtr, char value);
char delete (ListNodePtr *sPtr, char value);

void insert(ListNodePtr *sPtr, char value)
{

}
