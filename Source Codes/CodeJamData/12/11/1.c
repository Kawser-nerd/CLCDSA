#include <stdio.h>

double p[100001];
int a,b;

int main() {
	int T,i,caseno=1;
	double best,cur;
	double q;
	int press;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&a,&b);
		for(i=0;i<a;i++) scanf("%lf",&p[i]);
		/*	press enter right away */
		best=b+2;
		q=1;
		for(i=0;i<=a;i++) {
			/*	press backspace a-i times, then type */
			press=a-i+b-i+1;
			cur=q*press+(1-q)*(press+1+b);
			if(best>cur) best=cur;
			q*=p[i];
		}
		printf("Case #%d: %.16f\n",caseno++,best);
	}
	return 0;
}
