#include <stdio.h>
#include <algorithm>
using namespace std;

double p[101010];

main(){
	int casenum,totcase;
	scanf("%d",&totcase);
	for(int casenum=1;casenum<=totcase;casenum++){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;i++)scanf("%lf",&p[i]);
		double ans=1+b+1;
		double prod=1;
		for(int i=0;i<=a;i++){
			ans=min(ans,(a-i+b-i+1)+(b+1)*(1-prod));
			if(i<a)prod*=p[i];
		}
		printf("Case #%d: %.12f\n",casenum,ans);
	}
}