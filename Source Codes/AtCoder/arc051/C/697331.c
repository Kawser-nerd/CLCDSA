#include<stdio.h>
#define M 1000000007
int MAX(int a,int b){return a<b?b:a;}
int mbk(long long a,int n,int m){return n?(mbk((a*a)%m,n/2,m)*(n%2?a:1))%m:1;}
int main(){
  int n,i,j,a,b,mi;
  long long c,d[60],max=0,t;
  scanf("%d %d %d",&n,&a,&b);
  for(i=0;i<n;i++){
    scanf("%lld",&d[i]);
    max=MAX(max,d[i]);
  }
  if(a==1){
    for(i=0;i<n;i++){
      for(j=i;j;j--){
	if(d[j-1]>d[j]){
	  t=d[j-1];
	  d[j-1]=d[j];
	  d[j]=t;
	}
      }
    }
    for(i=0;i<n;i++)printf("%lld\n",d[i]);
    return 0;
  }
  while(b--){
    mi=0;
    for(j=1;j<n;j++){
      if(d[mi]>d[j])mi=j;
    }
    d[mi]=d[mi]*a;
    if(d[mi]>max)break;
  }
  for(i=0;i<n;i++){
    for(j=i;j;j--){
      if(d[j-1]>d[j]){
	t=d[j-1];
	d[j-1]=d[j];
	d[j]=t;
      }
    }
  }
  for(i=0;i<n;i++)d[i]=d[i]%M;
  if(b==-1){
    for(i=0;i<n;i++)printf("%lld\n",d[i]);
    return 0;
  }
  //printf("%d\n",b);
  for(i=b%n;i<n  ;i++)printf("%lld\n",(d[i]*mbk(a,b/n  ,M))%M);//printf("\n");
  for(i=0  ;i<b%n;i++)printf("%lld\n",(d[i]*mbk(a,b/n+1,M))%M);
  //printf("%d %d %d\n",a,b,mbk(a,(b/n)+1,M));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&a,&b);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&d[i]);
     ^