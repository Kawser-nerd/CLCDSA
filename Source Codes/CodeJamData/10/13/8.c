#include<stdio.h>
#define G (1.6180339887)
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((b)>(a)?(b):(a))
int main(){
	int T;
	scanf("%d",&T);
	int l;
	for(l=1;l<=T;l++){
		printf("Case #%d: ",l);
		int a1,a2,b1,b2;
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		unsigned long long ans=0;
		//a<b
		int i;
		for(i=a1;i<=a2;i++){
			int k=(int)((i+0.0)*G)+1;
			k=max(k,b1);
			if(k>b2)break;
			ans+=b2-k+1;
		}
		//b<a
		for(i=b1;i<=b2;i++){
			int k=(int)((i+0.0)*G)+1;
			k=max(k,a1);
			if(k>a2)break;
			ans+=a2-k+1;
		}
		printf("%llu\n",ans);
	}
	return 0;
}
