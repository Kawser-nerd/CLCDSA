#include<stdio.h>
int mbk(long long a,int n,int m){return n?(mbk((a*a)%m,n/2,m)*(n%2?a:1))%m:1;}
int inv(int a,int m){return mbk((long long)a,m-2,m);}
int aCb(int a,int b,int m){
  long long s=1,i;
	if(a<b)return 0;
  if(b>a-b)b=a-b;
  for(i=0;i<b;i++)s=(((s*(a-i))%m)*inv(i+1,m))%m; //printf("%dC%d=%d->",a,b,s); 
  return (int)s;
}
int x,y,a,b;
long long f(int i,int j){return aCb((x-i)*(y-j),a+b,1e9+7);}
int main(){
	int h,w,c;
	long long d=1,M=1e9+7;
	scanf("%d %d %d %d %d %d",&w,&h,&x,&y,&a,&b);
	c=(h-y+1LL)*(w-x+1LL)%M;
	if(x*y-a-b){
		d=f(0,0);
		d=(d+4*f(1,1)+M*4)%M;//printf("%lld\n",d);
		d=(d-2*f(1,0)+M*2)%M;//printf("%lld\n",d);
		d=(d-2*f(0,1)+M*2)%M;//printf("%lld\n",d);
		d=(d+f(2,0))%M;//printf("%lld\n",d);
		d=(d+f(0,2))%M;//printf("%lld\n",d);
		d=(d-2*f(2,1)+M*2)%M;//printf("%lld\n",d);
		d=(d-2*f(1,2)+M*2)%M;//printf("%lld\n",d);
		d=(d+f(2,2))%M;//printf("%lld\n",d);
	}//printf("%lld\n",d);
	d=d*aCb(a+b,a,M)%M;//printf("%lld %d\n",d,c);
	printf("%lld\n",c*d%M);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d %d %d",&w,&h,&x,&y,&a,&b);
  ^