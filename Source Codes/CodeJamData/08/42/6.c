#include <stdio.h>
int n,c,C,i,m,a,j,i2,j2;
int main() {
	scanf("%d",&C);
	for(c=1;c<=C;c++) {
		scanf("%d%d%d",&n,&m,&a);
		for(i=0;i<=n;i++) for(j=0;j<=m;j++)
		for(i2=0;i2<=n;i2++) for(j2=0;j2<=m;j2++) {
			int a1 = i*j2 - j*i2;
			if(a1 == a || a1 == -a) goto ex;
		}
		printf("Case #%d: IMPOSSIBLE\n",c);
		continue;
ex:
//		fprintf(stderr,"\r%d/%d",c,C); fflush(stderr);
		printf("Case #%d: 0 0 %d %d %d %d\n",c,i,j,i2,j2);
	}
//	fprintf(stderr,"\n");
	return 0;
}
