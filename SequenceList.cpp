#include<stdio.h>
#include<stdlib.h>

#define InitSize 10

struct SqList
{
    int *data;
    int MaxSize, length;
};

void initList(SqList &L){
    // L.data = new int[InitSize];
    // 分配内存区域
    L.data = (int *) malloc(sizeof(int) * InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

void increaseList(SqList &L, int len){
    int *p = L.data;
    L.data = (int *) malloc(sizeof(int) * (L.MaxSize + len));
    // 将原数据复制到新内存中
    for (int i; i<L.length; i++){
        L.data[i] = p[i];
    }
    L.MaxSize += len;
    free(p);
}

int main(){
    SqList L;
    initList(L);

}
