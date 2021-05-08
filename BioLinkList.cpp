#include <stdio.h>
#include <stdlib.h>

typedef struct BioLNode{
    struct BioLNode *prior;
    int data;
    struct BioLNode *next;
} BioLNode, *BioLinkList;



bool initBioLinkList(BioLinkList &L){
    L = (BioLNode *) malloc(sizeof(BioLNode));
    L->next = NULL;
    L->prior = NULL;
    return true;
}


bool appendElem(BioLinkList &L, int new_data){

    
    int j = 0;
    BioLNode* p = L;
    while (p->next != NULL)
    {
        p = p->next;
        j ++;
    }

    BioLNode *s = (BioLNode *) malloc(sizeof(BioLNode));
    s->data = new_data;
    s->next = NULL;
    p->next = s;
    s->prior = p;
    printf("Element %d added.", new_data);

    return true;
}


void printBioLinkList(BioLinkList L){
    BioLNode* p = L;
    while (L->next != NULL){
        p = p->next;
        printf(" %d ", p->data);
    }
}


int main()
{
    BioLinkList L;
    initBioLinkList(L);
    appendElem(L, 12);
    // printBioLinkList(L);
    return 0;
}


