
#include <stdio.h>

int D;
int P[2000];

void readstuff(void) {
    int i;
    scanf("%d",&D);
    for (i=0;i<D;i++)
        scanf("%d",P+i);
}

int maxelement(void) {
    int i;
    int m=P[0];
    for (i=1;i<D;i++) {
        if (P[i]>m) m=P[i];
    }
    return m;
}

//number of turns when splitting pancake piles to size x
int splitatsize(int x) {
    int splits=0;
    int i;
    for (i=0;i<D;i++) splits+=(P[i]-1)/x;
    return x+splits;
}

void pancakes(void) {
    int best;
    int m,i,turns;
    readstuff();
    best=m=maxelement();
    for (i=1;i<m;i++) {
        turns=splitatsize(i);
        if (turns<best) best=turns;
    }
    printf("%d\n",best);
}

int main(int argc, char **argv) {
    int T,casenum;
    scanf("%d",&T);
    for (casenum=1;casenum<=T;casenum++) {
        printf("Case #%d: ",casenum);
        pancakes();
    }
    return 0;
}
