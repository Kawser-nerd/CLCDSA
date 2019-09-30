#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>	
#define inf (INT_MAX-1)
#define INF 9223372036854775807
#define sq(n) ((n)*(n))
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define sort(a,n) qsort(a,n,sizeof(TYPE),cmp)
#define sort_r(a,n) qsort(a,n,sizeof(TYPE),cmp_r);
#define TYPE int
#define MEMSET(a) memset(a,0,sizeof(a))
const int mod=(int)1e09+7;

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
long long llabs(long long a){
	return a>0?a:-a;
}
double dmax(double a,double b){
	return a>b?a:b;
}
int cmp(const void *a,const void *b){
	return *(TYPE *)a-*(TYPE *)b;
}
int cmp_r(const void *a,const void *b){
	return *(TYPE *)b-*(TYPE *)a;
}

int main(void){
	int n=in(),a[100005],i,j;
	long long c=n;
	rep(i,n)a[i]=in();
	rep(i,n){
		if(a[i]<a[i+1]){
			for(j=i;a[j]<a[j+1];j++){
				c+=1+j-i;
			}
			i=j;
		}
	}
	llprint(c);
	return 0;
} ./Main.c: In function ‘in’:
./Main.c:19:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  int i;scanf("%d",&i);
        ^
./Main.c: In function ‘llin’:
./Main.c:23:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  long long i;scanf("%lld",&i);
              ^
./Main.c: In function ‘din’:
./Main.c:27:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  double i;scanf("%lf",&i);
           ^
./Main.c: In function ‘chin’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^