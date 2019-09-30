#include <stdlib.h>
#include <stdio.h>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

	int A,B;
	int ta[100], tb[100];
	long long ca[100], cb[100];

long long get_max(int posa, long long useda, int posb, long long usedb)
{
	long long a,b,c;
	
	if (posa==A) return 0;
	if (posb==B) return 0;

	if (useda==ca[posa]) {
		posa++;
		useda=0;
		if (posa==A) return 0;
	}

	if (usedb==cb[posb]) {
		posb++;
		usedb=0;
		if (posb==B) return 0;
	}

	if (ta[posa]==tb[posb]) {
		c=MIN(ca[posa]-useda,cb[posb]-usedb);
		return (c+get_max(posa, useda+c, posb, usedb+c));
	}
	a=get_max(posa+1, 0, posb, usedb);
	b=get_max(posa, useda, posb+1, 0);
	return MAX(a,b);
}


main()
{
	int T,t,x;
		
	scanf("%d", &T);
	for (t=1; t<=T; t++) {
		scanf("%d %d", &A, &B);
		for (x=0; x<A; x++) scanf("%lld %d", &ca[x], &ta[x]);
		for (x=0; x<B; x++) scanf("%lld %d", &cb[x], &tb[x]);

		printf ("Case #%d: %lld\n", t, get_max(0,0,0,0));
	}

}
