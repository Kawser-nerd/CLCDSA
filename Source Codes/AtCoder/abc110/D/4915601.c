#include<stdio.h>

#define mod 1000000007
struct yak{
		long long a;
		int c;
};

long long ka(long long x,long long a){
//		printf("%lld\n",a);
		if(a==1)return x;
		if(a%2==0){
				long long b;
				b=ka(x,a/2);
				return (b*b)%mod;
		}
		return (x*ka(x,a-1))%mod;
}

long long div(long long x,long long y){
		return (x*ka(y,mod-2))%mod;
}

long long ncm(long long n,long long m){
		long long r=1,i,rr=1,rrr=1;
		for(i=2;i<=n;i++)r=(r*i)%mod;
		for(i=2;i<=m;i++)rr=(i*rr)%mod;
		for(i=2;i<=n-m;i++)rrr=(rrr*i)%mod;
		return (div(div(r,rr),rrr))%mod;
}
int main(){
		int n,i,c=0;
		long long m,j,ans=1;
		struct yak yaku[1000];
		scanf("%d%lld",&n,&m);
		if(n==1||m==1){
				puts("1");
				return 0;
		}
		for(i=0;i<1000;i++)yaku[i].c=0;
		for(j=2;j*j<=m;j++){
				if(m%j==0){
						int f=0;
						for(i=0;i<c;i++){
								if(yaku[i].a==j){
										yaku[i].c+=1;
										f=1;
										break;
								}
						}
						if(f==0){
								yaku[c].a=j;
								yaku[c].c=1;
								c++;
						}
						m/=j;
						j=1;
				}
										//printf("%lld\n",yaku[0].c);
		}
		if(c==0){
				printf("%d\n",n);
				return 0;
		}
		if(m!=1){
				int f=0;
				for(i=0;i<c;i++){
						if(yaku[i].a==m){
								yaku[i].c++;
								f=1;
								break;
						}
				}
				if(f==0){
						yaku[c].a=m;
						yaku[c].c=1;
						c++;
				}
		}
		for(i=0;i<c;i++){
//				printf("%lld\n",ncm(n+yaku[i].c-1,n-1));
				ans=(ans*ncm(n+yaku[i].c-1,n-1))%mod;
		}
		printf("%lld\n",ans%mod);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lld",&n,&m);
   ^