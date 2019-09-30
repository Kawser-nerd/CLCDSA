#include <stdio.h>
#include <string.h>

int sw[1002][102];
int n,s,q;
char b[5000];
char ss[102][105];

int min(int a, int b) { return a<b?a:b; }

int main() {
	int i,j,k,mi,fk,pfk;
	gets(b);
	sscanf(b,"%d",&n);
	for (i=0; i<n; ++i) {
		gets(b);
		sscanf(b,"%d",&s);
		for (j=0; j<s; ++j) {
			gets(ss[j]);
			sw[0][j]=0;
		}
		gets(b);
		sscanf(b,"%d",&q);
		pfk=-1;
		for (j=0; j<q; ++j) {
			gets(b);
			mi=0x7ffffff0;
			for (k=0; k<s; ++k) {
				if (!strcmp(b,ss[k])) {
					sw[j+1][k]=-1;
					fk=k;
				} else {
					sw[j+1][k]=sw[j][k];
				}
				if (sw[j][k]!=-1) {
					mi=min(mi,sw[j][k]);
				}
			}
			if (pfk>=0) sw[j+1][pfk]=mi+1;
			pfk=fk;
//			for (k=0; k<s; ++k) printf("%d ",sw[j+1][k]);
//			printf("\n");
		}
		mi=0x7fffffff;
		for (j=0; j<s; ++j) if (sw[q][j]!=-1) mi=min(mi,sw[q][j]);
		printf("Case #%d: %d\n",i+1,mi);
	}
	return 0;
}
