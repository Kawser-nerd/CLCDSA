
#include <stdio.h>

typedef struct node {
    struct node *next;
    int v;
} node;

node A[1100];
int N;
int Max;

node *tosort;
int inversions;

void readstuff(void) {
    int i;
    Max=-1;
    scanf("%d",&N);
    for (i=0;i<N;i++) {
        scanf("%d",&(A[i].v));
        if (A[i].v>Max) Max=A[i].v;
    }
}

node *merge(node *a, node *b) {
    node c0,*c=&c0;
    int cnt=0;
    while (a || b) {
        if (b==NULL || a && a->v <= b->v) {
            inversions+=cnt;
            c=c->next=a;a=a->next;
            
        } else {
            cnt++;
            c=c->next=b;b=b->next;
        }
    }
    return c0.next;
}

int bump(void) {
    int i=0;
    while (i<N && A[i].v>=Max) {
        A[i].v=2*Max-A[i].v;
        i++;
    }
    if (i>=N) return 0;
    A[i].v=2*Max-A[i].v;
    return 1;
}

node *sort(int n) {
    node *a,*b;
    if (n==1) {
        a=tosort++;
        a->next=NULL;
        return a;
    } else {
        a=sort(n/2);
        b=sort(n-n/2);
        return merge(a,b);
    }
}

void picksides(void) {
    int i;
    node *list, *q,*p,*m,*mp;
    int n;
    int mi;
    for (i=0;i<N-1;i++)
        A[i].next=A+i+1;
    A[N-1].next=NULL;
    list=A;
    n=N;
    while (n>1) {
        mi=0;
        i=0;
        p=mp=NULL;
        q=m=list;
        while (q) {
            if (q->v < m->v) {
                m=q;mp=p;mi=i;
            }
            p=q;
            q=q->next;
            i++;
        }
        if (mi>=n/2) {
            //printf("hi(%d) ",m->v);
            m->v=2*Max-m->v;
        }
        if (mp) mp->next=m->next;
        else list=m->next;
        n--;    
    }
}

void mincmp(void) {
    int m;
    readstuff();
    picksides();
    tosort=A;
    inversions=0;
    sort(N);
    m=inversions;
    printf("%d\n",m);
}

int main(int argc, char **argv) {
    int i,tc;
    scanf("%d",&tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        mincmp();
    }
    return 0;
}