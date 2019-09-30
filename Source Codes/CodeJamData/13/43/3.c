
#include <stdio.h>

int X[2020];
int A[2020];
int B[2020];
//int expA[2020]; //expected A
//int expB[2020]; //expected B
int N;
int found;

void erdos(int i);


void label(int a, int b, int del, int *ex,int *AB) {
    int i;
    int m=0;
    for (i=a;i!=b;i+=del) {
        if (X[i]) {
            if (AB[i]>m) m=AB[i];
            ex[i]=0;
        } else {
            ex[i]=m+1;
        }
    }
}

void findX(int x, int *expA, int *expB) {
    int i;
    //int found=0;
    for (i=1;i<=N;i++) {
        if (expA[i]==A[i] && expB[i]==B[i]) {
            X[i]=x;
            erdos(x+1);
            X[i]=0;
            //break;
        }
    }
}

void readstuff(void) {
    int i;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    for (i=1;i<=N;i++) scanf("%d",B+i);
    for (i=1;i<=N;i++) X[i]=0;
    found=0;
}

void dump(int i, int *expA, int*expB) {
    printf("i=%d\n",i);
    for (i=1;i<=N;i++) printf("%d ",expA[i]);
    printf("\n");
    for (i=1;i<=N;i++) printf("%d ",expB[i]);
    printf("\n");
}

void erdos(int i) {
    //int i;
    int expA[30];
    int expB[30];
    if (found) return;
    if (i<=N) {
        label(1,N+1,1,expA,A);
        label(N,0,-1,expB,B);
        //dump(i,expA,expB);
        findX(i,expA,expB);
    } else {
        found=1;
        for (i=1;i<=N;i++) printf("%d ",X[i]);
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int i,T;
    scanf("%d",&T);
    for (i=1;i<=T;i++) {
        printf("Case #%d: ",i);
        readstuff();
        erdos(1);
    }
    return 0;
}