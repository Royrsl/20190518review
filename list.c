#include <stdio.h>
#include <stdlib.h>
typedef struct node node;
struct node
{
    int data;
    node * next;
};

node * cteate()
{
    int i = 0;
    node *head, *p, *q; 
    int x = 0;
    head = (node *)malloc(sizeof(node));

    while(1)
    {
        printf("please input the data:");
        scanf("%d", &x);
        if(x==0)
            break;
        p = (node *)malloc(sizeof(node));
        p->data = x;
  
        if(++i==1)
        {
            head->next = p;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
    q ->next = NULL;
    return head;
}

int length(node * L)
{
    int i = 0;
    node * q;
    q = L -> next;
    while(q != NULL)
    {
        i++;
        q = q->next;
    }
    return i;
}
void print(node * L)
{
    int i = 0;
    node * p ;
    p = L -> next;
    if(p == NULL)
    {
        printf("Empty list!");
        return;
    }
    while(p != NULL)
    {
        printf("data=%d\n", p->data);
        p = p->next;
    }
}
node * find(node * L, int pos)
{
    int length = 0, i = 0;
    node * p;
    if(pos < 0)
    {
        printf("ERROR POS!");
        return NULL;
    }
    if(L == NULL)
    {
        printf("NULL LIST!");
        return NULL;
    }
    if(pos == 0)
    {
        return L;
    }
    p = L->next;
    while(--pos)
    {
        if(p->next == NULL)
        {
            printf("pos is longger than length of the list");
            break;
        }
        p = p->next;
    }
    return p;
}

node * insert(node * L, int pos, int data)
{
    node * p;
    node * q = NULL;
    q = (node *)malloc(sizeof(node));
    q->data = data;
    if(pos < 0)
    {
        printf("ERROR POS!");
        return NULL;
    }

    if(L == NULL)
    {
        printf("NULL LIST!");
        return NULL;
    }

    if(pos == 0)
    {
        L->next = q;
        return L;
    }

    p = L->next;
    while(--pos)
    {
        if(p->next == NULL)
        {
            printf("pos is longger than length of the list");
            break; 
        }
        p = p->next;
    }

    q->next = p->next;
    p->next = q;
    return L;
}

node * del(node * L, int pos)
{
    node * p,*q;
    if(L == NULL)
    {
        printf("ERROR LIST!");
        return NULL;
    }
    if(pos < 0)
    {
        printf("ERROR POS!");
        return NULL;
    }
    if(pos == 0)
    {
        L = L->next;
        return L;
    }
    q = L;
    p = L->next;
    while(--pos)
    {
        if(p->next == NULL)
        {
            printf("pos is longger than length of the list");
            break;
        }
        q = p;
        p = p->next;
    }
    q->next = p ->next;
    return L;
}

node * revise(node * L)
{
    int l = 0;
    node * p, *q, *tmp;
    tmp = (node *)malloc(sizeof(node));
    if(L == NULL)
    {
        printf("ERROR LIST!");
        return NULL;
    }
    l = length(L);
    q = find(L, l);
    tmp -> next = q;
    while(--l)
    {
        q = find(L, l+1);
        p = find(L, l);
        q -> next = p;
    }
    p ->next = NULL;
    return tmp;
}
int main()
{
    int i = 0;
    node * L = cteate();
    i = length(L);
    printf("i=%d\n", i);
    print(L);
    print(revise(L));
    
    return 0;
}