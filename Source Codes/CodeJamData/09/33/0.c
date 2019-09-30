#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




int main()
{
	int v=0,V;

	int f[200][200];
	int a[200];
	int i,j,k,m,n,s,l;

	for(scanf("%d",&V);V;V--) {
		v++;
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++) scanf("%d",&a[i]);
		a[0]=0; a[m+1]=n+1;
		for(i=0;i<=m;i++) f[i][i+1]=0;
		for(l=3;l<=m+2;l++)
			for(i=0;i+l-1<=m+1;i++) {
				j=i+l-1;
				f[i][j]=1e9;
				for(k=i;k<=j;k++) {
					s=a[j]-a[i]-2+f[i][k]+f[k][j];
					if (s<f[i][j]) f[i][j]=s;
				}
			}
		printf("Case #%d: %d\n",v, f[0][m+1]);
	}
}
		
