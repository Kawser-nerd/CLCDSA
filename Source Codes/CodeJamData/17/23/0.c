#include<stdio.h>
#include<string.h>

#define inf 1069999999

int a[128][128];
double d[128];
int v[128];
int b[128][2];
double r[128];
int n,m;

int main() {
	int N,cs=0,i,j,k,s,t,l;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++) scanf("%d %d",&b[i][0],&b[i][1]);
		for(i=0;i<n;i++) for(j=0;j<n;j++) {
			scanf("%d",&a[i][j]);
			if (i==j) a[i][j]=0;
			else if (a[i][j]==-1) a[i][j]=inf;
		}
		for(k=0;k<n;k++) for(i=0;i<n;i++) for(j=0;j<n;j++) {
			if (a[i][k]+a[k][j]<a[i][j]) a[i][j]=a[i][k]+a[k][j];
		}
		for(i=0;i<m;i++) {
			scanf("%d %d",&s,&t);
			s--,t--;
			for(j=0;j<n;j++) d[j]=1e100,v[j]=0;
			d[s]=0;
			for(j=0;j<n;j++) {
				for(k=0,l=-1;k<n;k++) if (!v[k]) {
					if (l<0 || d[k]<d[l]) l=k;
				}
				if (l==t) {
					r[i]=d[t];
					break;
				}
				v[l]=1;
				for(k=0;k<n;k++) if (a[l][k]<=b[l][0]) {
					double t=d[l]+(double)a[l][k]/b[l][1];
					if (t<d[k]) d[k]=t;
				}
			}
		}
		printf("Case #%d:",++cs);
		for(i=0;i<m;i++) printf(" %.10lf",r[i]);
		puts("");
	}
	return 0;
}