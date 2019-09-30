#include<cstdio>
#include<algorithm>
using namespace std;
int dp[502][502];
char s[500][510];
int main(){
    int r,c,k,ans=0;
    scanf("%d %d %d",&r,&c,&k);
    for(int i=0;i<r;i++){
        scanf("%s",&s[i]);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(s[i][j]=='x'){
                dp[i+1][j+1]=k;
            }
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
            dp[i][j]=max(dp[i][j],dp[i+1][j]-1);
            dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
            dp[i][j]=max(dp[i][j],dp[i][j+1]-1);
        }
    }
    for(int i=r;i>=1;i--){
        for(int j=c;j>=1;j--){
            dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
            dp[i][j]=max(dp[i][j],dp[i+1][j]-1);
            dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
            dp[i][j]=max(dp[i][j],dp[i][j+1]-1);
        }
    }
    for(int i=k;i<=r-k+1;i++){
        for(int j=k;j<=c-k+1;j++){
            if(!dp[i][j]){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
} ./Main.cpp:10:20: warning: format specifies type 'char *' but the argument has type 'char (*)[510]' [-Wformat]
        scanf("%s",&s[i]);
               ~~  ^~~~~
1 warning generated.