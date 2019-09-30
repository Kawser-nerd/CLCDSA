#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,m,i,j,k,d[110][110],a[1010],b[1010],c[1010];
  for(i=0;i<110*110;i++)d[i/110][i%110]=1e9;
  for(i=0;i<110;i++)d[i][i]=0;
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d %d %d",&a[i],&b[i],&c[i]);
    d[a[i]][b[i]]=d[b[i]][a[i]]=c[i];
  }
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      for(k=1;k<=n;k++)d[j][k]=MIN(d[j][k],d[j][i]+d[i][k]);
    }
  }
  for(i=j=0;i<m;i++){
    if(d[a[i]][b[i]]-c[i])j++;
  }
  printf("%d\n",j);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&a[i],&b[i],&c[i]);
     ^