#include <stdio.h>
#define REP(i, n) for(i = 0; i < n; ++i)
#define FOR(i, a, b) for(i = a; i < b; ++i)

void yes_or_no(char boolean){
    if(boolean){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}

void traverse(int now,int N, char chk[N], char matrix[N][N]){
     chk[now] = 1;
     int next;

     REP(next, N){
         if(matrix[now][next] == 1 && chk[next] != 1){
             traverse(next, N, chk,  matrix);
         }
     }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    char matrix[N][N];
    int list_p[M], list_q[M];
    char chk[N];
    int x, y;
    int i;
    int ans = 0;

    REP(x, N){
        chk[x] = 0;
        REP(y, N){
            matrix[x][y] = (x == y)? 1 : 0;
        }
    }

    REP(i, M){
        scanf("%d %d", &list_p[i], &list_q[i]);
        x = list_p[i] - 1, y = list_q[i] - 1;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }

    REP(i, M){
        x = list_p[i] - 1, y = list_q[i] - 1;
        matrix[x][y] = 0;
        matrix[y][x] = 0;


        traverse(0, N, chk, matrix);

        int k;
        char bridge = 0;

        REP(k, N){
            if(chk[k] == 0){
                bridge = 1;
            }else{
                chk[k] = 0;
            }
        }


        if(bridge) ans++;

        matrix[x][y] = 1;
        matrix[y][x] = 1;         
    }

    printf("%d\n", ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^
./Main.c:42:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &list_p[i], &list_q[i]);
         ^