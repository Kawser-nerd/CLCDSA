#include<stdio.h>
#include<limits.h>

int N;
int A[50];

int Z[50][50][2];

void solve(){
    int i,j;
    for (i=0;i<N-1;i++){
        int p=1,x=0,y=0;
        for (j=i;j<N;j++){
            if (p%2){
                x+=A[j];
            }else{
                y+=A[j];
            }

            Z[i][j][0] = x;
            Z[j][i][0] = x;
            Z[i][j][1] = y;
            Z[j][i][1] = y;
            p++;
        }
    }

    int ans = INT_MIN;
    for (i=0;i<N;i++){
        int aoki_max = INT_MIN,takahashi = INT_MIN;
        for (j=0;j<N;j++){
            if (i != j){
                if (aoki_max < Z[i][j][1]){
                    aoki_max = Z[i][j][1];
                    takahashi = Z[i][j][0];
                }
            }
        }
        if (ans < takahashi){
            ans = takahashi;
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&N);
    int i;
    for (i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    solve();
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:50:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&A[i]);
         ^