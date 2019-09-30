#include<stdio.h>
int main(){
  int n,i,j,d[100010],a;
  long long ans=1e18,s,c;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&d[i]);
  for(j=0;j<2;j++){
    s=c=0;
    for(i=0;i<n;i++){
      s+=d[i];
      if((i+j)%2==0&&s<=0){
	c+=1-s;
	s=1;
      }
      if((i+j)%2==1&&s>=0){
	c+=s+1;
	s=-1;
      }
    }
    if(ans>c)ans=c;
  }
  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&d[i]);
                   ^