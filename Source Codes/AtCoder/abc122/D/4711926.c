#include <stdio.h>
#define MOD (1000000007)
/*AGC,GAC,ACG,AG-C,A-GC=>023,203,032,02-3,0-23*/
/*
[2][3][-]?[0][2][3]
[0][3][-]?[2][0][3]
[3][2][-]?[0][3][2]
[2][-][3]?[0][2][-]
[-][2][3]?[0][-][2]??????????*/
int main(){
  int n;
  long dp[98][4][4][4],ans=0;/*dp[i]=>n=i+3??????*/
  if(scanf("%d",&n)){
  for (int i=0;i<98;i++){
    for (int j=0;j<4;j++){
      for (int k=0;k<4;k++){
        for (int l=0;l<4;l++){/*???*/
          dp[i][j][k][l]=1;
        }
      }
    }
  }
  dp[0][0][2][3]=0;
  dp[0][2][0][3]=0;
  dp[0][0][3][2]=0;
  for (int i=0;i<n-3;i++){
    for (int j=0;j<4;j++){
      for (int k=0;k<4;k++){
        for (int l=0;l<4;l++){/*dp[i][j][k][l]???*/
          if (j==0 && k==2 && l==3) dp[i+1][j][k][l]=0;
          else if (j==2 && k==0 && l==3) dp[i+1][j][k][l]=0;
          else if (j==0 && k==3 && l==2) dp[i+1][j][k][l]=0;
          else if (j==2 && l==3) 
            dp[i+1][j][k][l]
            =(dp[i][1][j][k]+dp[i][2][j][k]+dp[i][3][j][k])%MOD;
          else if (k==2 && l==3) 
            dp[i+1][j][k][l]
            =(dp[i][1][j][k]+dp[i][2][j][k]+dp[i][3][j][k])%MOD;
          else dp[i+1][j][k][l]
            =(dp[i][0][j][k]+dp[i][1][j][k]+dp[i][2][j][k]+dp[i][3][j][k])%MOD;
        }
      }
    }
  }
  for (int j=0;j<4;j++){
    for (int k=0;k<4;k++){
      for (int l=0;l<4;l++){
        ans+=dp[n-3][j][k][l];
        ans%=MOD;
      }
    }
  }
  printf("%ld",ans);}
  return 0;
}