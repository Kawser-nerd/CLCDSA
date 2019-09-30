#include<stdio.h>
int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}
int main(){
	int t;
	scanf("%d",&t);
	int pp;
	for(pp=1;pp<=t;pp++){
		int pd,pg,n;
		long long n2;
		scanf("%lld%d%d",&n2,&pd,&pg);
		if(n2>100)n=101;
		else n=n2;
		if(pd==0){
			if(pg!=100)
				printf("Case #%d: Possible\n",pp);
			else
				printf("Case #%d: Broken\n",pp);
			continue;
		}
		int D=(100/gcd(100,pd));
		if(D>n){
			printf("Case #%d: Broken\n",pp);
			continue;
		}
		if(pg==100 && pd<100){
			printf("Case #%d: Broken\n",pp);
			continue;
		}
		if(pg==0 && pd>0){
			printf("Case #%d: Broken\n",pp);
			continue;
		}
		printf("Case #%d: Possible\n",pp);
	}
	return 0;
}
