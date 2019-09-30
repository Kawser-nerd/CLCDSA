#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rep(n, i) for(int i = 0; i < n; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INF 1000000
void solve(void){
    int n;
    scanf("%d\n", &n);
    int ns[n], t_scores[n][n], a_scores[n][n];
    rep(n, i) scanf("%d\n", &ns[i]);

    //i?j???????????
    for (int i = 0; i < n; i++){            //Takahasi?index
        for (int j = 0; j < n; j++){        //Aoki?index
            if (i == j) {
                t_scores[i][j] = -INF;
                a_scores[i][j] = -INF;
                continue;
            }
            int small = MIN(i, j);
            int large = MAX(i, j);
            int len = large - small + 1;
            int memo[len];                  //i~j??????

            memo[0] = ns[small]; memo[1] = ns[small+1];
            t_scores[i][j] = memo[0];
            a_scores[i][j] = memo[1];

            for (int k = 2; k < len; k++){
                memo[k] = ns[k+small];
                if (k % 2) a_scores[i][j] += memo[k];
                else t_scores[i][j] += memo[k];
            }
        }
    }
    //i???????Aoki??????????j
    int js[n];
    rep (n, i) {
        int aoki_max= a_scores[i][0];
        int max_index = 0;              //Aoki??????????index
        rep (n, j) if (a_scores[i][j] > a_scores[i][max_index]) max_index = j;
        js[i] = max_index;
    }
    //?i????j???????
    int ans = t_scores[0][js[0]];
    rep (n-1, i) if (t_scores[i+1][js[i+1]] > ans) ans = t_scores[i+1][js[i+1]];

    printf("%d\n", ans);
    /*
    rep(n, j) printf("%d ", js[j]);
    printf("\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", t_scores[i][j]);
        }
        printf("\n");
    }
    */
}

int main(void){
  solve();
  return 0;
} ./Main.c: In function ‘solve’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n", &n);
     ^
./Main.c:13:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     rep(n, i) scanf("%d\n", &ns[i]);
               ^