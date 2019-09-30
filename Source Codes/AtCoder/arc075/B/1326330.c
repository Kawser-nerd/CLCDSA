#include<stdio.h>
long long MAX(long long a,long long b){return a<b?b:a;}
int main(){
  long long n,a,b,d[100010],l,r,m,i,s;
  scanf("%lld %lld %lld",&n,&a,&b);
  for(i=l=0;i<n;i++)scanf("%lld",&d[i]);
  for(r=1e9+10;l-r;){//printf("%lld %lld\n",l,r);
    m=(l+r)/2;
    for(i=s=0;i<n;i++)s+=d[i]>m*b?((d[i]-m*b)-1)/(a-b)+1:0;
    //printf("%lld %lld %lld %lld\n",l,r,m,s);
    //if(s>m)l=m+1;
    //else   r=m;
    if(s<=m)r=m;
    else    l=m+1;
  }
  //printf("%d %d\n",((10-2*2)-1)/(5-2)+1,((4-2*2)-1)/(5-2)+1);
  printf("%lld\n",l);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld",&n,&a,&b);
   ^
./Main.c:6:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=l=0;i<n;i++)scanf("%lld",&d[i]);
                     ^