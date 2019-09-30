#include<cstdio>
using namespace std;
int main(){
    int n,k,dp[6][128]={},t[5][5];
    scanf("%d %d",&n,&k);
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            scanf("%d",&t[i][j]);
        }
        for(int j=0;j<=127;j++){
            if(dp[i][j]){
                for(int l=0;l<k;l++){
                    dp[i+1][j^t[i][l]]=1;
                }
            }
        }
    }
    
    if(dp[n][0]){
        printf("Found\n");
    }
    else{
        printf("Nothing\n");
    }
}