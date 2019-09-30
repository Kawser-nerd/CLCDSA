#include <stdio.h>
    #include <stdlib.h>
     
    int dp[50][50];
    int N;
    int D[50][50];
    int Q;
    int P[2500];
    int max[2501];
     
     
    int DP(int h,int w){
        if(dp[h][w]!=-1)return dp[h][w];
        int sq1=0,sq2=0,sq3=0;
        if(h<N-1)sq1=DP(h+1,w);
        if(w<N-1)sq2=DP(h,w+1);
        if(h<N-1&&w<N-1)sq3=DP(h+1,w+1);
        return dp[h][w]=sq1+sq2-sq3+D[h][w];
    }
     
    int main()
    {
        int i,j,k,l;
        scanf("%d",&N);
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                scanf("%d",&D[i][j]);
            }
        }
        scanf("%d",&Q);
        for(i=0;i<Q;i++){
            scanf("%d",&P[i]);
        }
        memset(dp,-1,sizeof(dp));
        DP(0,0);
        memset(max,0,sizeof(max));
        for(i=0;i<N;i++){
            for(j=i;j<N;j++){
                for(k=0;k<N;k++){
                    for(l=k;l<N;l++){
                        int tmp=dp[i][k];
                        if(j!=N-1)tmp-=dp[j+1][k];
                        if(l!=N-1)tmp-=dp[i][l+1];
                        if(j!=N-1&&l!=N-1)tmp+=dp[j+1][l+1];
                        if(max[(j-i+1)*(l-k+1)]<tmp)max[(j-i+1)*(l-k+1)]=tmp;
                    }
                }
            }
        }
        for(i=1;i<=N*N;i++){
            max[i]=max[i]>max[i-1]?max[i]:max[i-1];
        }
        int ans=0;
        for(i=0;i<Q;i++){
            printf("%d\n",max[P[i]]);
        }
        return 0;
    } ./Main.c: In function ‘main’:
./Main.c:34:9: warning: implicit declaration of function ‘memset’ [-Wimplicit-function-declaration]
         memset(dp,-1,sizeof(dp));
         ^
./Main.c:34:9: warning: incompatible implicit declaration of built-in function ‘memset’
./Main.c:34:9: note: include ‘<string.h>’ or provide a declaration of ‘memset’
./Main.c:24:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&N);
         ^
./Main.c:27:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%d",&D[i][j]);
                 ^
./Main.c:30:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&Q);
         ^
./Main.c:32:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&P[i]);
             ^