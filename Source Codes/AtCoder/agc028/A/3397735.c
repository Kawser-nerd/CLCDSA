#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
char lowcmp[26]="abcdefghijklmnopqrstuvwxyz";
char upcmp[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
long long mod=1000000007;
int max(int a, int b){return a>b?a:b;}
int min(int a, int b){return a<b?a:b;}
int gcd(int a, int b){return min(a,b)==0?max(a,b):gcd(min(a,b),max(a,b)%min(a,b));}
long long llmax(long long a, long long b){return a>b?a:b;}
long long llmin(long long a, long long b){return a<b?a:b;}
long long llgcd(long long a, long long b){return min(a,b)==0 ?llmax(a,b):llgcd(llmin(a,b),llmax(a,b)%llmin(a,b));}

int main(void){
    long long n,m,ans;
    scanf("%lld%lld",&n,&m);
    ans=n*m/llgcd(n,m);
    char s[n+3],t[m+3];
    scanf("%s%s",s,t);
    for (long long i=0; i<llgcd(n,m); i++){
                                            //printf("%c %c\n",s[i*ans/m],t[i*ans/n]);
        if (s[i*ans/m]!=t[i*ans/n]){
            ans=-1;
            break;
        }
    }
    printf("%lld\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&m);
     ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s",s,t);
     ^