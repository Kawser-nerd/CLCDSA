#include<stdio.h>
#include<string.h>

int n,a[3];
int r[16][3];
char str[16][5000];
char ss[]="RSP";
char t[5000];

int main() {
	int i,j,k,N,cs=0;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d %d %d",&n,&a[0],&a[2],&a[1]);
		for(i=0;i<3;i++) r[0][i]=a[i];
		for(i=0;i<n;i++) {
			for(j=0;j<3;j++) {
				if (r[i][j]>(1<<(n-i-1))) break;
				r[i+1][(j+1)%3]=(1<<(n-i-1))-r[i][j];
			}
			if (j<3) break;
		}
		if (i<n) {
			printf("Case #%d: IMPOSSIBLE\n",++cs);
			continue;
		}
		memset(str,0,sizeof(str));
		for(j=0;j<3;j++) if (r[n][j]) str[n][0]=ss[j];
		for(i=n;i>0;i--) {
			for(j=0;j<(1<<(n-i));j++) {
				for(k=0;k<3;k++) if (str[i][j]==ss[k]) {
					str[i-1][j*2]=ss[k];
					str[i-1][j*2+1]=ss[(k+1)%3];
				}
			}
		}
		for(i=0;i<n;i++) {
			for(j=0;j<(1<<(n-i-1));j++) {
				if (strncmp(str[0]+(j<<(i+1)),str[0]+(j<<(i+1))+(1<<i),(1<<i))>0) {
					strncpy(t,str[0]+(j<<(i+1)),1<<i);
					strncpy(str[0]+(j<<(i+1)),str[0]+(j<<(i+1))+(1<<i),(1<<i));
					strncpy(str[0]+(j<<(i+1))+(1<<i),t,(1<<i));
				}
			}
		}
		printf("Case #%d: %s\n",++cs,str[0]);
	}
	return 0;
}
