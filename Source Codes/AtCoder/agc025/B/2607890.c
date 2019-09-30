//set many funcs template
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 998244353
#define pi 3.1415926535897932384

void shuffledget(int x[],int n){
    srand(time(0));
    int i,b[524288],p,c;
    for(i=0;i<n;i++){
        b[i]=i;
    }
    for(i=n;i>=1;i--){
        p=rand()%i;
        c=b[i-1];b[i-1]=b[p];b[p]=c;
    }
    for(i=0;i<n;i++){
        scanf("%d",&x[b[i]]);
    }
}

long long factorial[524288];

void cfact(){
    long long i;
    factorial[0]=1;
    factorial[1]=1;
    for(i=2;i<524288;i++){
        factorial[i]=factorial[i-1]*i;
        factorial[i]%=mod;
    }
}

long long power(long long a, long long b){
	long long x = 1, y = a;
	while (b > 0){
		if(b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}	
 
long long modular_inverse(long long n){
	return power(n, mod-2);
}

long long calcnCr(long long n,long long k){
	return (factorial[n]*(modular_inverse(factorial[k])*modular_inverse(factorial[n-k])%mod))%mod;
}

int main(void){
    cfact();
    long long i,j,n,m,k,a,b,c,w,r=0,l,t;
    double d;
    char s[524288];
    scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
    //l=strlen(s);
    for(i=0;i<=n;i++){
        w=k-(a*i);
        if(w%b!=0){continue;}
        w=w/b;
        if(w<0 || n<w){continue;}
        t=1;
        t*=calcnCr(n,i);t%=mod;
        t*=calcnCr(n,w);t%=mod;
        r+=t;r%=mod;
    }
    //shuffledget(a,n);
    //qsort(a,n,sizeof(int),sortfncsj);
    printf("%lld\n",r);
    return 0;
} ./Main.c: In function ‘shuffledget’:
./Main.c:23:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x[b[i]]);
         ^
./Main.c: In function ‘main’:
./Main.c:64:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
     ^