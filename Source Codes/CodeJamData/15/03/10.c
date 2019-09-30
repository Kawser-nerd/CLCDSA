
#include <stdio.h>

int Llen;
long long XLL;
int X;

char Lch[1100000];

int L[1100000];

//in arrays 1==1 2==i 3==j 4==k
//as index subtract 1
int times[4][4]={
    { 1, 2, 3, 4 },
    { 2, -1, 4, -3},
    { 3, -4, -1, 2},
    { 4, 3, -2, -1}}; 

void convert(void) {
    int i;
    int ch;
    for (i=0;i<Llen;i++) {
        ch=Lch[i];
        if (ch=='i') L[i]=2;
        if (ch=='j') L[i]=3;
        if (ch=='k') L[i]=4;
    }
}

void expand(void) {
    int i,j;
    int base;
    for (i=0;i<X;i++) {
        base=Llen*i;
        for (j=0;j<Llen;j++) {
            L[base+j]=L[j];
        }
    }
}

int qtimes(int a, int b) {
    int sign=1;
    int ab;
    if (a<0) {sign=-sign; a=-a;}
    if (b<0) {sign=-sign; b=-b;}
    ab=times[a-1][b-1];
    return sign*ab;
}

int hasIJK() {
    int hasI=0;
    int hasIJ=0;
    int r=1;
    int i;
    for (i=0;i<Llen*X;i++) {
        r=qtimes(r,L[i]);
        if (!hasI) {
            if (r==2) hasI=1;
        } else {
            if (!hasIJ && r==4) hasIJ=1;
        }
    }
    return hasIJ && r==-1;
}

void reduceX(void) {
    long long simpleX;
    simpleX=24+(XLL & 3); //could be 12+(X % 3)??
    if (simpleX < XLL) X=(int) simpleX;
    else X=(int) XLL; 
}

void dijkstra(void) {
    scanf("%d %lld",&Llen,&XLL);
    scanf("%s",Lch);
    reduceX();
    convert();
    expand();
    if (hasIJK()) printf("YES\n");
    else printf("NO\n");
}

int qpower(int a, int n) {
    int i,r=1;
    for (i=0;i<n;i++)
        r=qtimes(r,a);
    return r;
}

int mainTest(int argc, char **argv) {
    int q;
    for (q=-4;q<=4;q++) {
        if (q==0) continue;
        printf("q=%d q**4=%d\n",q,qpower(q,4));
    }
    return 0;
}

int main(int argc, char **argv) {
    int i,tc;
    scanf("%d", &tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        dijkstra();
    }
    return 0;
}
