#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <ctime>
#define LL long long int
#define eps (1e-6)
#define N 10005
using namespace std;

int n,TC,ok,cnt[N*100],x,f;
LL L,H,y,a[N],LCM[N],GCD[N],p,q,AC=-1,LOWER,W,prime[N*100],TL;

double aa,bb,cc;

LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}

void TRY(int p,LL q){
	if (p==x+1){
		if (q>=LOWER){
			if ((double)(q)*(double)(TL) > (double)(H) + eps){}
			else if (q*TL <= H && q*TL>= L && (AC==-1 || AC>q*TL))
				AC=q*TL;
		}
	}
	else {
		LL k=1;
		for (int i=0;i<=cnt[p];i++){
			if ((double)(q)*(double)(k) > (double)(H) + eps){}
			else {
				TRY(p+1,q*k);
				if (i!=cnt[p]) k*=prime[p];
			}
		}
	}
}

int main(){
	scanf("%d",&TC);
	
	for (int C=1;C<=TC;C++){
		scanf("%d%lld%lld",&n,&L,&H);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		
		
		sort(a+1,a+n+1);
		memset(LCM,-1,sizeof(LCM));
		memset(GCD,-1,sizeof(GCD));
		
		AC=-1;
		LCM[0]=1;
		
		for (int i=1;i<=n;i++){
			
			q = gcd(LCM[i-1],a[i]);
			
			if ((double)(LCM[i-1])*(double)(a[i])/(double)(q) > (double)(H) + eps)
				break;
			
			LCM[i] = LCM[i-1]/q;
			LCM[i] = LCM[i]*a[i];
			
			//printf(" LCM %d -> %lld\n",i,LCM[i]);
			
		}
		
		GCD[n]=a[n];
		for (int i=n-1;i>=1;i--){
			
			q = gcd(GCD[i+1],a[i]);
			
			GCD[i] = q;
			
			//printf(" GCD %d -> %lld\n",i,GCD[i]);
		}
		
		if (L<=1) AC=1;
		
		for (int i=0;i<=n;i++){
			
			if (i!=n){			
			
				if (LCM[i]==-1 || GCD[i+1]%LCM[i]!=0) continue;
			
				TL = LCM[i];			
				LOWER = (L+LCM[i]-1)/LCM[i];
				W = GCD[i+1]/LCM[i];
				
				y=2;
				x=0;
				
				while (y*y<=W){
					f = 0;
					while (W%y==0){
						if (!f){
							prime[++x]=y;
							cnt[x]=1;
							f=1;
						}
						else cnt[x]++;
						W/=y;
					}
					y++;
				}
				if (W!=1) prime[++x]=W,cnt[x]=1;
				
				TRY(1,1);
				
			}
			else {
				
				LOWER = (L+LCM[i]-1)/LCM[i];
				
				if ((double)(LOWER)*(double)(LCM[i]) > (double)(H) + eps){}				
				else if (LCM[i]*LOWER>=L && LCM[i]*LOWER<=H){
					if (AC==-1 || LCM[i]*LOWER<AC) AC = LCM[i]*LOWER;
				}
			}
		}
		
		
		if (AC!=-1)
			printf("Case #%d: %lld\n",C,AC);
		else printf("Case #%d: NO\n",C);
	}
	scanf("\n");
	return 0;
}
