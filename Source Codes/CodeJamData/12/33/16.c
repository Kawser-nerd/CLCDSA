
#include <stdio.h>

int N,M;

long long a[10];
int A[10];
long long b[110];
int B[110];

long long maxscore;

void readstuff(void) {
    int i;
    scanf("%d %d",&N,&M);
    for (i=0;i<N;i++)
        scanf("%lld %d",a+i,A+i);
    for (i=0;i<M;i++)
        scanf("%lld %d",b+i,B+i);
}

void scoring(int ai, int bi, long long score) {
    long long ds;
    if (ai>=N || bi>=M) {
        if (score>maxscore) maxscore=score;
        return;
    }
    scoring(ai+1,bi,score); //skip ai
    if (a[ai]==0) return;
    for (;bi<M;bi++) {
        if (A[ai]==B[bi] && b[bi]) {
            ds=a[ai];
            if (b[bi]<ds) ds=b[bi];
            a[ai]-=ds;
            b[bi]-=ds;
            scoring(ai,bi,score+ds);
            a[ai]+=ds;
            b[bi]+=ds;
            return;
        }
    }
}
void box(void) {
    readstuff();
    maxscore=0;
    scoring(0,0,0);
    printf("%lld\n",maxscore);
}

int main(int argc, char **argv) {
    int i,tc;
    scanf("%d",&tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        box();
    }
    return 0;
}
