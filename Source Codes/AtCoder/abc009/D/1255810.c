#include<stdio.h>
int main(){
  unsigned int n,m,d[110],e[110][110],i,j,k,a[110],c[110][110]={};
  scanf("%u %u",&n,&m);
  for(i=0;i<n;i++)scanf("%u",&a[n-i-1]);
  for(i=0;i<n;i++)scanf("%u",&c[0][i]);
  for(i=1;i<n;i++)c[i][i-1]=-1;
  if(m<n){
    printf("%u\n",a[n-m]);
    return 0;
  }
  for(m-=n;m;m/=2){//printf("%d\n",m);
    if(m%2){
      for(i=0;i<n;i++){
	for(j=d[i]=0;j<n;j++)d[i]^=c[i][j]&a[j];
      }
      for(i=0;i<n;i++)a[i]=d[i];
    }
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	for(k=e[i][j]=0;k<n;k++)e[i][j]^=c[i][k]&c[k][j];
      }
    }
    for(i=0;i<n;i++){
      for(j=0;j<n;j++)c[i][j]=e[i][j];
    }
    //for(i=0;i<n;i++)printf("%d ",a[i]);printf("\n");
  }
  printf("%u\n",a[0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%u %u",&n,&m);
   ^
./Main.c:5:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%u",&a[n-i-1]);
                   ^
./Main.c:6:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%u",&c[0][i]);
                   ^