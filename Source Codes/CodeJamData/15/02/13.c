#include <stdio.h>

int main()
{
	int t,T;
	scanf("%d", &T);

	int D, P[2000], maxP;
	int i,j,k,l;
	
	for(t=1;t<=T;t++)
	{
		scanf("%d", &D);
		maxP=0;
		for(i=0;i<D;i++) {
			scanf("%d", &P[i]);
			if (maxP<P[i]) maxP=P[i];
		}

		for(i=1;i<maxP;i++) {
			for(j=0;j<i;j++) {
				k=0;
				for(l=0;l<D;l++) {
					k+= (P[l]/(i-j)) - (P[l]%(i-j)?0:1);
					if(k>j) break;
				}
				if(l==D) break;
			}
			if(j<i) break;
		}

		printf("Case #%d: %d\n", t, i);
	}

	return 0;
}
