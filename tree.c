#include <stdio.h>
#include <string.h>

typedef struct BinNode
{
    char data;
    struct BinNode *lchild, *rchild;
}BinNode, *BinNode;

void PreOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    printf("%c", T->data);
    PreOrderTraverse(lchild);
    PreOrderTraverse(rchild);
}

void InOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    InOrderTraverse(lchild);
    printf("%c", T->data);
    InOrderTraverse(rchild);
}

void PostOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    InOrderTraverse(lchild);
    InOrderTraverse(rchild);
    printf("%c", T->data);
}
