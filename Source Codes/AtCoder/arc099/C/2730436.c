#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,m,i,j,k,d[710][710],c[710]={};
  int q[710],t,r,e[710][2]={};
  int dp[710][710]={1}; 
  scanf("%d %d",&n,&m);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      if(i==j)continue;
      d[i][j]=1;
    }
  }
  while(m--){
    scanf("%d %d",&i,&j);
    d[i][j]=d[j][i]=0;
  }
  m=0;
  for(i=1;i<=n;i++){
    if(c[i])continue;
    q[t=0]=i;
    c[q[t]]=1;
    for(r=1;r-t;t++){//printf("!!%d %d\n",q[t],c[q[t]]);
      e[m][c[q[t]]-1]++;
      for(j=1;j<=n;j++){
	if(d[q[t]][j]==0)continue;//printf("j:%d %d\n",j,c[j]);
	if(c[j]&&c[j]==c[q[t]])goto END;
	if(c[j])continue;
	c[j]=3-c[q[t]];
	q[r++]=j;
      }
    }
    m++;
  }
  //for(i=0;i<n;i++)printf("%d\n",c[i+1]);printf("%d\n",m);
  for(i=0;i<m;i++){//printf("%d %d\n",e[i][0],e[i][1]);
    for(j=n;j>=0;j--){
      for(k=n;k>=0;k--){
	if(dp[j][k]==0)continue;//printf("!!!%d %d\n",j,k);
	if(j+e[i][0]<=n&&k+e[i][1]<=n)dp[j+e[i][0]][k+e[i][1]]=1;
	if(j+e[i][1]<=n&&k+e[i][0]<=n)dp[j+e[i][1]][k+e[i][0]]=1;
      }
    }
  }
  /*for(i=0;i<=n;i++){
    for(j=0;j<=n;j++)printf("%d ",dp[i][j]);printf("\n");
    }//*/
  j=1e9;
  for(i=0;i<=n;i++){
    if(dp[i][n-i]==0)continue;
    j=MIN(j,(i*(i-1))/2+((n-i)*(n-i-1)/2));
  }
  if(j>1e8)goto END;
  printf("%d\n",j);
  return 0;
 END:;
  printf("-1\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&i,&j);
     ^