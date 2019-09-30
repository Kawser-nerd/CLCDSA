
#include <stdio.h>
#include <stdlib.h>

long long gap[10];
long long count[10];

void init(void) {
    int i;
    for (i=0;i<10;i++) {gap[i]=-1; count[i]=0; }
}

void findlargest(long long *vv, long long *cc) {
    int l=0;
    int i;
    for (i=1;i<10;i++) {
        if (gap[i]>gap[l]) l=i;
    }
    if (gap[l]==-1) {fprintf(stderr, "table empty for largets\n"); exit(-1);}
    *vv=gap[l];
    *cc=count[l];
    gap[l]=-1;
    count[l]=0;
}

int find(long long v) {
    int i;
    int neg=-1;
    for (i=0;i<10;i++) {
        if (gap[i]==v) return i;
        if (gap[i]==-1LL) neg=i;
    }
    if (neg<0) {fprintf(stderr,"outa space\n"); exit(-1);}
    gap[neg]=v;
    count[neg]=0;
    return neg;
}

long long problem(void) {
    long long N,K;
    long long v,c;
    int i;
    init();
    scanf("%lld %lld",&N, &K);
    gap[0]=N;
    count[0]=1;
    K--;
    while (1) {
        findlargest(&v, &c);
        //printf("largest =%lld(%lld) K=%lld\n",v,c,K);
        if (K<c) return v;
        i=find(v/2);
        count[i]+=c;
        i=find((v-1)/2);
        count[i]+=c;
        K-=c;
    }
}

int main(int argc, char **argv) {
    int i,tc;
    long long r;
    scanf("%d",&tc);
    for (i=1;i<=tc;i++) {
        r=problem();
        printf("Case #%d: %lld %lld\n", i, r/2, (r-1)/2);
    }
    return 0;
}
