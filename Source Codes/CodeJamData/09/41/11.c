#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int a[100],i,j,k,n,x,ans;

int main()
{
	int v=0,V;

	for(scanf("%d",&V);V;V--) {
		v++;
		printf("Case #%d: ",v);

		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++) {
			a[i]=0;
			for(j=1;j<=n;j++) {
				scanf("%1d",&x);
				if (x==1) a[i]=j;
			}
		}

		for(i=1;i<=n;i++) {
			if (a[i]<=i) continue;
			else {
				j=i;
				while(a[j]>i) j++;
				for (k=j;k>i;k--) {
					a[k]=a[k-1];
					ans++;
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
		
