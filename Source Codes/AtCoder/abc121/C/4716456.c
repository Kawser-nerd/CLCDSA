#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define FOR(i,a,n) for(i=(a);i<(n);i++)
#define swap(type,a,b) do{type t=a; a=b; b=t}while(0)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define SIZE 100005
typedef long long ll;
const ll INF=100000000;
const ll MOD=1000000007;
typedef struct{
    int v1,v2;
}Pair;
int comp(const void *a,const void *b){
    return ((Pair*)a)->v1 - ((Pair*)b)->v1;
}
Pair p[SIZE];
int main(void){
    int n,m,i;
    ll res;
    scanf("%d%d",&n,&m);
    FOR(i,0,n) scanf("%d%d",&p[i].v1,&p[i].v2);
    qsort(p,n,sizeof(Pair),comp);
    FOR(i,0,n){
        int k=MIN(m,p[i].v2);
        res += (ll)k*(ll)p[i].v1;
        m -= k;
        if(m==0) break;
    }
    printf("%lld\n",res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:25:16: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     FOR(i,0,n) scanf("%d%d",&p[i].v1,&p[i].v2);
                ^