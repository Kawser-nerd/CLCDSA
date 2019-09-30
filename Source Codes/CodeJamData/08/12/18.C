#include <stdio.h>

int c,n,m,na[200],a[200][300][2];
char s[1000];

int isok(int j) {
	int i,l,k,cc,ok,jj=j;
	for (i=0; i<m; ++i) {
		ok=0;
		for (k=0; k<na[i]; ++k) {
			j=jj;
			for (l=0; l<n; ++l) {
				cc=j%2;
				j/=2;
				if (a[i][k][0]==n-l && a[i][k][1]==cc) {
					ok=1;
					break;
				}
			}
			if (ok) break;
		}
		if (!ok) return 0;
	}
	return 1;
}
int nummalted(int j) {
	int i,c=0;
	for (i=0; i<n; ++i) {
		c+=j%2;
		j/=2;
	}
	return c;
}

int main() {
	int i,j,k,upto;
	scanf("%d",&c);
	for (i=0; i<c; ++i) {
		scanf("%d",&n);
		scanf("%d",&m);
		for (j=0; j<m; ++j) {
			scanf("%d",&na[j]);
			for (k=0; k<na[j]; ++k) {
				scanf("%d %d",&a[j][k][0],&a[j][k][1]);
			}
		}
		upto=1<<n;
		j=0;
		int mm=n+1,g=0;
		while (j<upto) {
			int anm=nummalted(j);
			if (isok(j) && anm<mm) {
				mm=anm;
				g=j;
			}
			++j;
		}
		for (j=0; j<n; ++j) {
			s[n-j-1]=g%2;
			g/=2;
		}
		s[n]=0;
		printf("Case #%d:",i+1);
		if (mm==n+1) printf(" IMPOSSIBLE\n");
		else {
			for (j=0; j<n; ++j) printf(" %d",s[j]);
			printf("\n");
		}
	}
	return 0;
}
