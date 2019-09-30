#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>	
#define inf (INT_MAX-1)
#define INF 9223372036854775807
#define EPS 1e-10
#define sq(n) ((n)*(n))
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define sort(a,n) qsort(a,n,sizeof(TYPE),cmp)
#define sort_r(a,n) qsort(a,n,sizeof(TYPE),cmp_r);
#define chsort(s,n) qsort(s,n,sizeof(char),cmp)
#define chsort_r(s,n) qsort(s,n,sizeof(char),char_cmp_r);
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
typedef struct{int a,b;}pair;
char a[3][3];
int b[2][3],c[3][2];

pair solve(int turn){
	int i,j;
	pair ans,t;
	ans.a=ans.b=0;
	if(!turn){
		rep(i,2){
			rep(j,3){
				if(a[i][j]==a[i+1][j])ans.a+=b[i][j];
				else ans.b+=b[i][j];
			}
		}
		rep(i,3){
			rep(j,2){
				if(a[i][j]==a[i][j+1])ans.a+=c[i][j];
				else ans.b+=c[i][j];
			}
		}
	}
	else if(turn%2){
		rep(i,3){
			rep(j,3){
				if(a[i][j]=='-'){
					a[i][j]='o';
					t=solve(turn-1);
					if(t.a>=ans.a)ans=t;
					a[i][j]='-';
				}
			}
		}
	}
	else{
		rep(i,3){
			rep(j,3){
				if(a[i][j]=='-'){
					a[i][j]='x';
					t=solve(turn-1);
					if(t.b>=ans.b)ans=t;
					a[i][j]='-';
				}
			}
		}
	}
	return ans;
}

int main(void){
	int i,j;
	pair ans;
	rep(i,3)rep(j,3)a[i][j]='-';
	rep(i,2)rep(j,3)b[i][j]=in();
	rep(i,3)rep(j,2)c[i][j]=in();
	ans=solve(9);
	print(ans.a);
	print(ans.b);
	return 0;
} ./Main.c: In function ‘in’:
./Main.c:23:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  int i;scanf("%d",&i);
        ^
./Main.c: In function ‘llin’:
./Main.c:27:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  long long i;scanf("%lld",&i);
              ^
./Main.c: In function ‘din’:
./Main.c:31:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  double i;scanf("%lf",&i);
           ^
./Main.c: In function ‘chin’:
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^