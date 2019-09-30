#include <stdio.h>
#include <string.h>
#define maxn 11000

int d[maxn],l[maxn],l2[maxn];

int sol(int cas){
    int N,D;
    int i,j;
    int add,ttt;
    memset(d,0,sizeof(d));
    memset(l,0,sizeof(l));
    memset(l2,0,sizeof(l2));
    scanf("%d",&N);
    for (i=0;i<N;i++) scanf("%d%d",d+i,l+i);
    scanf("%d",&D);
    for (i=0;i<N;i++) l2[i]=0;
    l2[0]=d[0]*2;
    if (l2[0]>=D) return 1;
    for (i=0;i<N;i++){
//        if (l2[i]<=0) continue;
        for (j=i+1;j<N;j++){
//            printf("d[%d]=%d l[%d]=%d\n");
            if (d[j]<=l2[i]){
                add = d[j]-d[i];
                if (add>l[j]) add = l[j];
                ttt = d[j]+add;
                if (ttt>=D) return 1;
                if (l2[j]<d[j]+add) l2[j]=d[j]+add;
            }else break;
        }
    }
    return 0;
    if (l2[N-1]<D) 
        printf("Case #%d: NO\n",cas);
    else 
        printf("Case #%d: YES\n",cas);
}

int main(){
    int T,cas;
    scanf("%d", &T);
    for (cas=1;cas<=T;cas++)
        printf("Case #%d: %s\n",cas,sol(cas)?"YES":"NO");
    return 0;
}

