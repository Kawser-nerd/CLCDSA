#include <stdio.h>
#include <string.h>

#define PAIR 1
#define VIST 2
#define NOVIS 0

int max(int a, int b){return a>b?a:b;}

int f[1024], in[1024], h[1024];
char tag[1024];

void solve(int t){
    int N, x;
    int i,j,nx;
    int h1,h2,ht,ct,maxc;
    int pair_cnt = 0;
    scanf("%d", &N);
    memset(in, 0, sizeof(in[0])*(N+1));
    memset(tag, 0, sizeof(tag[0])*(N+1));
    memset(h, 0, sizeof(h[0])*(N+1));
    for (i=1;i<=N;i++){
        scanf("%d", &x);
        f[i]=x;
        in[x]++;
    }
    // pairs
    for (i=1;i<=N;i++){
        j = f[i];
        if (j>i && f[j] == i){
            tag[i] = tag[j] = PAIR;
            pair_cnt++;
        }
    }
    // leaves
    for (i=1;i<=N;i++){
        if (0 == in[i] && 0 == h[i]){
            j = i;
            while (1){
                nx = f[j];
                in[nx]--;
                h[nx] = max(h[nx], h[j]+1);
                if (in[nx]!=0) break;
                j = nx;
            }
        }
    }
    // max leaves, and circles
    h1=0;
    maxc = 0;
    for (i=1;i<=N;i++){
        if (tag[i] == PAIR){
            h1 += h[i];
        }else if (in[i]>0 && tag[i]==0){
            // do circle
            ct = 0;
            j = i;
            while (1) {
                if (tag[j]==NOVIS){
                    tag[j] = VIST;
                    ct++;
                    j = f[j];
                }else break;
            }
            maxc = max(maxc,ct);
        }
    }
    printf("Case #%d: %d\n", t, max(pair_cnt*2+h1, maxc));
}

int main(){
    int t, T;
    scanf("%d", &T);
    for (t=1; t<=T; t++){
        solve(t);
    }
    return 0;
}
