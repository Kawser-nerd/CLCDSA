#include<stdio.h>

char a[128][128];
double sum[128];
int cnt[128];
double WP[128];
double OWP[128];
double OOWP[128];
int n;

int main() {
	int i,j,N,cs=0;
	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%s",a[i]);
		for(i=0;i<n;i++) {
			sum[i]=cnt[i]=0;
			for(j=0;j<n;j++) if (a[i][j]!='.') {
				cnt[i]++;
				if (a[i][j]=='1') sum[i]+=1;
			}
			WP[i]=sum[i]/cnt[i];
		}
		for(i=0;i<n;i++) {
			sum[i]=cnt[i]=0;
			for(j=0;j<n;j++) if (a[i][j]!='.') {
				cnt[i]++;
				sum[i]+=WP[j];
			}
			OWP[i]=sum[i]/cnt[i];
		}
		for(i=0;i<n;i++) {
			sum[i]=cnt[i]=0;
			for(j=0;j<n;j++) if (a[i][j]!='.') {
				cnt[i]++;
				sum[i]+=OWP[j];
			}
			OOWP[i]=sum[i]/cnt[i];
		}
		printf("Case #%d:\n",++cs);
		for(i=0;i<n;i++) printf("%.10lf\n",0.25*WP[i]+0.5*OWP[i]+0.25*OOWP[i]);
	}
	return 0;
}
