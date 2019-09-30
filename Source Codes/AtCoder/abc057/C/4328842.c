#include<stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int ket(long long a){
		int r=0;
		while(a>0){
				a=a/10;
				r++;
		}
		return r;
}

int main(){
		int c=0,ans=20000000;
		long long n,i,ncpy;
		long long yks[10000][2];
		scanf("%lld",&n);
		ncpy=n;
		yks[c][0]=1;
		yks[c][1]=n;
		c++;
		for(i=2;i*i<=n;i++){
				if(n%i==0){
						yks[c][0]=i;
						yks[c][1]=n/i;
						c++;
						//n=n/i;
						//i=2;
				}
		}
		for(i=0;i<c;i++)ans=min(ans,max(yks[i][0],yks[i][1]));
		printf("%d\n",max(ket(yks[c-1][0]),ket(yks[c-1][1])));
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^