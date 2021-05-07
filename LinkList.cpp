#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <exception>
#include <iostream>

extern int errno ;

typedef struct LNode
{
    int Data;
    struct LNode* next;
}LNode, *LinkList;

// 等同于 typedef struct LNode LNode; typedef struct LNode * LinkList;

// // 不带头结点的链表
// bool initLinkList(LinkList &L){
//     L = NULL;  // 初始化时设定为一个空表
//     return true;
// }

// bool isEmpty(LinkList L){
//     return (L == NULL);
// }

// 带头结点的链表，推荐
bool initLinkListwithHead(LinkList &L){
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL){
        return false;  // 内存不足，内存分配失败
    }
    L->next = NULL;  // 头结点后暂时没有结点
    return true;
}

bool isEmptywithHead(LinkList L){
    return (L->next == NULL);
}

bool appendElement(LinkList &L, int data){
    LNode *p = (LNode *) malloc(sizeof(LNode));
    LNode *k = L;
    while (k->next != NULL){
        k = k->next;
    }
    p->Data = data;
    p->next = NULL;
    k->next = p;
    return true;
}

bool insertElem(LinkList &L, int loc, int data){
    int j = 0;
    LNode *p = L;
    while (j < loc)
    {
        p = p->next;
        j ++;
    }
    LNode *n = (LNode *) malloc(sizeof(LNode));
    n->next = p->next;
    n->Data = data;
    p->next = n;
    return true;
}

void printLinkList(LinkList L){
    LNode *p = L;
    while (p->next != NULL){
        p = p->next;
        printf(" %d ", p->Data);
    }
}

void test(){
    LinkList L;
    initLinkListwithHead(L);
    appendElement(L, 12);
    appendElement(L, 24);
    appendElement(L, 345);
    insertElem(L, 1, 45);
    printLinkList(L);
    perror("\nTest");
    
}

int main()
{
    int errnum;
    try
    {
        test();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    errnum = errno;
    printf("Hello, World! \n");
    // printf("%d", 12);
    return 0;
}


