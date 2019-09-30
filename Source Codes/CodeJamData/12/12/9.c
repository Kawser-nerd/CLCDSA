#include <stdio.h>
#define maxn 1000

int a[maxn],b[maxn],c[maxn];
int N;

int solve(){
    int i,j,cur,cnt;
    scanf("%d",&N);
    for (i=0;i<N;i++)
        scanf("%d%d",a+i,b+i);
    for (i=0;i<N;i++) c[i]=0;
    cur = 0; cnt = 0;
    while (cur<N+N){
        int done = 0;
        // clear 2 stars
        while (1){
            int in_done = 0;
            for (i=0;i<N;i++){
                if (cur>=b[i] && c[i]<2){
 //                   printf("%d: %d to %d\n",i,c[i],2);
                    cur+=2-c[i];
                    c[i]=2;
                    done = 1;
                    in_done = 1;
                    cnt++;
                }
            }
            if (!in_done) break;
        }
        // clear highest first stars
        int tc = -1;
        int mb = -1;
        for (i=0;i<N;i++){
            if (c[i]==0 && a[i]<=cur && b[i]>mb){
                mb = b[i];
                tc = i;
            }
        }
        if (tc>=0){
//            printf("%d: o to 1\n",tc);
            c[tc]=1;
            cur++;
            cnt++;
            done = 1;
        }
        if (done==0) return -1;
    }
    return cnt;
}

int main(){
    int T,cas,r;
    scanf("%d",&T);
    for (cas=1;cas<=T;cas++){
        r = solve();
        printf("Case #%d: ",cas);
        if (r==-1) printf("Too Bad\n");
        else printf("%d\n",r);
    }
    return 0;
}

