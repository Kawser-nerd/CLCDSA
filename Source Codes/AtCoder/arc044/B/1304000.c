#include<stdio.h>
int mbk(long long a,int n,int m){return n?(mbk((a*a)%m,n/2,m)*(n%2?a:1))%m:1;}
int main(){
	int n,m=1e9+7,max=0,i,d[100010]={};
	long long s=0,a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		d[a]++;
		if(max<a)max=a;
		if(i==0&&a==0)s=1;
	}
	for(i=1;i<=max;i++){
		a=(mbk(2LL,d[i-1],m)-1+m)%m;//printf("%3d ",a);
		s=(mbk(2LL,((d[i]-1LL)*d[i]/2)%(m-1),m)*s)%m;
		s=(mbk(a  ,d[i]                 ,m)*s)%m;
	}
	printf("%lld\n",d[0]-1?0:s);
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
   scanf("%d",&a);
         ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^