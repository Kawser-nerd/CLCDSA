#include <stdio.h>
long long llmax(long long a, long long b){return a>b?a:b;}
long long llmin(long long a, long long b){return a<b?a:b;}
long long llgcd(long long a, long long b){return llmin(a,b)==0?llmax(a,b):llgcd(llmin(a,b),llmax(a,b)%llmin(a,b));}
int main(void){
    long long n,m;
    scanf("%lld%lld",&n,&m);
    char s[n+1],t[m+1];
    scanf("%s%s",s,t);
    for (long long i=0; i<llgcd(n,m); i++){
        if (s[i*n*m/llgcd(n,m)/m]!=t[i*n*m/llgcd(n,m)/n]){
            printf("-1\n");
            return 0;
        }
    }
    printf("%lld\n",n*m/llgcd(n,m));
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&m);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s",s,t);
     ^