#include<stdio.h>
#include<stdlib.h>

int n,m;
int a[1024][2];

int cmp(const void *a,const void *b) {
	return *(int *)a-*(int *)b;
}

int main() {
	int N,cs=0,i,j;
	double ret,t,t1;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d",&m,&n);
		for(i=0;i<n;i++) scanf("%d %d",&a[i][0],&a[i][1]);
		qsort(a,n,sizeof(a[0]),cmp);
		ret=0;
		for(i=0;i<n;i++) {
			t=(double)(m-a[i][0])/a[i][1];
			for(j=j+1;j<n;j++) if (a[i][1]>a[j][1]) {
				t1=(double)(a[j][0]-a[i][0])/(a[i][1]-a[j][1]);
				if (t1<t) break;
			}
			if (j>=n && t>ret) ret=t;
		}
		printf("Case #%d: %.10lf\n",++cs,m/ret);
	}
	return 0;
}