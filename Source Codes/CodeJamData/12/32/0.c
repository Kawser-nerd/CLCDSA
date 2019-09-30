#include<stdio.h>
#include<math.h>

double a[2048][2];
int n,m;

int main() {
	int N,cs=0,i,j,k;
	double L,b,t,t1;
	for(scanf("%d",&N);N--;) {
		scanf("%lf %d %d",&L,&n,&m);
		for(i=0;i<n;i++) scanf("%lf %lf",&a[i][0],&a[i][1]);
		if (a[0][1]+1e-12>L) n=0;
		else {
			for(i=1;i<n;i++) if (a[i][1]+1e-12>L) {
				a[i][0]=a[i-1][0]+(L-a[i-1][1])/(a[i][1]-a[i-1][1])*(a[i][0]-a[i-1][0]);
				a[i][1]=L;
				n=i+1;
			}
		}
		printf("Case #%d:\n",++cs);
		for(i=0;i<m;i++) {
			scanf("%lf",&b);
			t=0;
			for(j=0;j<n;j++) {
				t1=a[j][0]-sqrt(a[j][1]*2/b);
				if (t1>t) t=t1;
			}
			printf("%lf\n",t+sqrt(L*2/b));
		}
	}
	return 0;
}
