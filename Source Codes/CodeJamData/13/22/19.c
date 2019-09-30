
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int x;
    struct NODE* next;
};

struct NODE *P[10000];
int X, Y, T, N, height;
double output;

void insert(int x, int y, double prob)
{
    if((y+2) > height)  height = y+2;
    if(x == X && y == Y)
    {
        output += prob;
    }
    struct NODE *temp,*p = P[y],*prev = P[y];
    if(p == NULL || p->x > x)
    {
        temp =(struct NODE *)malloc(sizeof(struct NODE));
        temp->x = x;
        temp->next = p;
        P[y] = temp;
        return;
    }
    while(p!= NULL && p->x < x)
    {
        prev = p;
        p = p->next;
    }
    if(prev->x < x)
    {
        temp =(struct NODE *)malloc(sizeof(struct NODE));
        temp->x = x;
        temp->next = prev->next;
        prev->next = temp;
        return;
    }
}

void removeNode(int x, int y)
{

    struct NODE *p = P[y],*prev;
    if(p->x == x)
    {
        P[y] = p->next;
        free(p);
        return;
    }

    while(p->x != x)
    {
        prev = p;
        p = p->next;
    }
    prev->next = p->next;
    free(p);
}

void recFree(struct NODE *p)
{
    if(p!=NULL)
    {
        recFree(p->next);
        free(p);
        p = NULL;
    }
}
void freeNode()
{
    int y;
    for(y=0;y<10000;y++)
        recFree(P[y]);
}


int check(int x , int y)
{

    if(y < 0)
        return 0;
    struct NODE *p = P[y];
    while(p!=NULL)
    {
        if(p->x == x)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

void start(int x, int y, double prob, int n)
{
    int l = check(x-1,y-1), r = check(x+1 , y-1);
    if(y==0 || (l==1 && r==1))
    {
        insert(x , y, prob);
        if(n>0)   start(0 , height , prob , n-1);
        removeNode(x, y);
        return;
    }
    else if(l==1 && r==0)
        start(x+1, y-1, prob, n);
    else if(l==0 && r==1)
        start(x-1,y-1,prob, n);
    else
    {
        if(check(x,y-2))
        {
            start(x+1, y-1, prob/2, n);
            start(x-1, y-1, prob/2, n);
        }
        else
            start(x,y-1,prob,n);
    }
}

int main()
{
    int t;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d",&N, &X, &Y);
        height = 2;
        output = 0.0;
        start(0 , height , 1 , N-1);
        freeNode();
        printf("Case #%d: %f\n",t,output);
    }
    return 0;
}
