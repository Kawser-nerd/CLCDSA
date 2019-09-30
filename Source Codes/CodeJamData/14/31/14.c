#include<stdio.h>
long long gcd(long long a,long long b){
	long long tmp;
	while(a%b!=0){
		tmp=b;
		b=a%b;
		a=tmp;
	}
	return b;
}
int main(){
	int T,I;
	scanf("%d",&T);
	for(I=0;I<T;I++){
		long long p,q,g;
		scanf("%lld/%lld",&p,&q);
		g=gcd(p,q);
		p/=g;
		q/=g;
		long long t=q;
		while(t%2==0){
			t/=2;
		}
		printf("Case #%d: ",I+1);
		if(t!=1)printf("impossible\n");
		else{
			int ans=1;
			while(p<q/2){
				q/=2;
				ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}