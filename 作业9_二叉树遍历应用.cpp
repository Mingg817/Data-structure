#include<stdio.h>
#include<malloc.h>

typedef struct btree{
    int data;
    struct btree *left;
    struct btree *right;
}*Btree;

int init_btree(Btree L)
{
    L=(Btree)malloc(sizeof(struct btree));
    
}