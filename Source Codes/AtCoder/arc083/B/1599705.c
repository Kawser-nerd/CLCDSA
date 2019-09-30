#include<stdio.h>
long long MIN(long long a,long long b){return a<b?a:b;}
int main(){
  long long n,d[500][500],i,j,k,min,s=0;
  scanf("%lld",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)scanf("%lld",&d[i][j]);
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i==j)continue;
      min=1e18;
      for(k=0;k<n;k++){
	if(i==k||j==k)continue;
	min=MIN(min,d[i][k]+d[k][j]);
      }
      if(min<d[i][j])goto END;
      if(min>d[i][j])s+=d[i][j];
      //printf("%lld %lld %lld\n",i,j,s);
    }
  }
  printf("%lld\n",s/2);
  return 0;
 END:;
  printf("-1\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:7:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(j=0;j<n;j++)scanf("%lld",&d[i][j]);
                     ^