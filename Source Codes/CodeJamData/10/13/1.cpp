#include<stdio.h>
#include<math.h>
const double phi=(1+sqrt(5))/2;
inline long long MAX(long long a,long long b){
	return a>b?a:b;
}
int main(){
	int t,cas=1;
	scanf("%d",&t);
	int q,w,e,r;
	while(t--){
		long long ans=0;
		scanf("%d%d%d%d",&q,&w,&e,&r);
		while(q<=w){
			double ee=q/phi,rr=q*phi;
			//printf("ee=%.3lf rr=%.3lf\n",ee,rr);
			long long eee=(long long)floor(ee)+1,rrr=(long long)floor(rr);
			//printf("eee=%I64d rrr=%I64d\n",eee,rrr);
			if(eee<e)eee=e;
			if(rrr>r)rrr=r;
			ans+=r-e+1-MAX(0,rrr-eee+1);
			q++;
		}
		printf("Case #%d: %I64d\n",cas++,ans);
	}
}
