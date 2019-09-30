#include<stdio.h>

int main(void)
{
  int n,m,i,j,k,count=0;
  int a[46]={0},b[46]={0};
  int dp[11][11]={0};

  scanf("%d%d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d %d",&a[i],&b[i]);
    a[i]--;
    b[i]--;
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      dp[i][j]=10;
    }
  }
   for(i=0;i<n;i++){
     dp[i][i]=0;
   }
  

  for(i=0;i<m;i++){
    dp[a[i]][b[i]]=1;
    dp[b[i]][a[i]]=1;
  }  
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	dp[i][j]=(dp[i][j]>dp[i][k]+dp[k][j])?dp[i][k]+dp[k][j]:dp[i][j];
      }
    }
    }

  
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	if(dp[i][j]==2){
	  count++;
	}
      }
      printf("%d\n",count);
      count=0;
    }

   return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a[i],&b[i]);
     ^