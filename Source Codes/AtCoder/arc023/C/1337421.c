#include<stdio.h>
int mbk(long long a,int n,int m){return n?(mbk((a*a)%m,n/2,m)*(n%2?a:1))%m:1;}
int inv(int a,int m){return mbk((long long)a,m-2,m);}
int aCb(int a,int b,int m){
  long long s=1,i;
  if(b>a-b)b=a-b;
  for(i=0;i<b;i++)s=(((s*(a-i))%m)*inv(i+1,m))%m;  
  return (int)s;
}
int main(){
	int n,a,b=0,c=0,M=1e9+7;
	long long s=1;
	scanf("%d %d",&n,&b);//printf("a\n");
	while(--n){
		scanf("%d",&a);
		if(a+1){
			s=(s*aCb(a-b+c,c,M))%M;
			b=a;
			c=0;
		}
		else c++;//printf("%d\n",s);//*/
	}
	printf("%lld\n",s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&b);//printf("a\n");
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^