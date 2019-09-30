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
#define chsort(s,n) qsort(s,n,sizeof(char),cmp)
#define chsort_r(s,n) qsort(s,n,sizeof(char),char_cmp_r);
#define TYPE long long
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
int char_cmp(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}
int char_cmp_r(const void *a,const void *b){
	return strcmp((char *)b,(char *)a);
}
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
long long gcd(long long x,long long y){
	return x%y?gcd(y,x%y):y;
}
long long lcm(long long x,long long y){
	return x/gcd(x,y)*y;
}

// konoshita kara kaku

int dp[45][401][401];

int main(void){
	int n=in(),ma=in(),mb=in(),a[40],b[40],c[40],i,j,k,ans=inf;
	rep(i,n){
		a[i]=in();
		b[i]=in();
		c[i]=in();
	}
	rep(i,41)rep(j,401)rep(k,401)dp[i][j][k]=inf;
	dp[0][0][0]=0;
	rep(i,n){
		rep(j,401){
			rep(k,401){
				if(dp[i][j][k]==inf)continue;
				dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
				dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
			}
		}
	}
	for(i=1;i<401;i++)
		for(j=1;j<401;j++)
			if(ma*j==i*mb)ans=min(ans,dp[n][i][j]);
	print(ans!=inf?ans:-1);
	return 0;
} ./Main.c: In function ‘in’:
./Main.c:21:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  int i;scanf("%d",&i);
        ^
./Main.c: In function ‘llin’:
./Main.c:25:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  long long i;scanf("%lld",&i);
              ^
./Main.c: In function ‘din’:
./Main.c:29:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  double i;scanf("%lf",&i);
           ^
./Main.c: In function ‘chin’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^