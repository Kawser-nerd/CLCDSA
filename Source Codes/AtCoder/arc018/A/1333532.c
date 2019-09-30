#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>	
#define inf INT_MAX
#define INF 9223372036854775807
#define sq(n) ((n)*(n))
#define rep(i,n) for(i=0;i<n;i++)

int in(void){
	int i;scanf("%d",&i);
	return i;
}
long long llin(void){
	long long i;scanf("%lld",&i);
	return i;
}
double din(void){
	double i;scanf("%lf",&i);
	return i;
}
void chin(char s[]){
	scanf("%s",s);
}
void print(int a){
	printf("%d\n",a);
}
void llprint(long long a){
	printf("%lld\n",a);
}
void dprint(double a){
	printf("%.10f\n",a);
}
void print2(int a,int b){
	printf("%d %d\n",a,b);
}
long long max(long long a,long long b){
	return a>b?a:b;
}
long long min(long long a,long long b){
	return a<b?a:b;
}
double dmax(double a,double b){
	return a>b?a:b;
}

int main(void){
	double h=din(),b=din();
	h/=100;
	dprint(h*h*b);
	return 0;
} ./Main.c: In function ‘in’:
./Main.c:12:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  int i;scanf("%d",&i);
        ^
./Main.c: In function ‘llin’:
./Main.c:16:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  long long i;scanf("%lld",&i);
              ^
./Main.c: In function ‘din’:
./Main.c:20:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  double i;scanf("%lf",&i);
           ^
./Main.c: In function ‘chin’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^