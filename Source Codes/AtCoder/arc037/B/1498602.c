#include<stdio.h>
#define REP(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)

int N,M;

char graph[100][100];
int used[100];


int search(int pos,int from){
    if (used[pos]){
        return 0;
    }
    used[pos] = 1;
    int i;
    for (i=0;i<N;i++){
        if (graph[pos][i] && i != from){
            int res = search(i,pos);
            if (!res){
                return 0;
            }
        }
    }
    return 1;
}



int main(void){
    int i,j;
    REP(i,N){
        REP(j,N){
            graph[i][j] = 0;
        }
        used[i] = 0;
    }


    scanf("%d %d",&N,&M);
    REP(i,M){
        int u,v;
        scanf("%d %d",&u,&v);
        u--;v--;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    
    int ans = 0;
    REP(i,N){
        ans += search(i,-1);
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:40:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^
./Main.c:43:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&u,&v);
         ^