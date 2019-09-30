#include <stdio.h>
#include <stdlib.h>

#define MODE 1000002013

typedef struct
{
	int p;
	int flag;
	int n;
}FLOW;

int cmp(const void *a, const void *b)
{
	FLOW *aa = (FLOW *)a, *bb = (FLOW *)b;
	if (aa->p == bb->p)
		return bb->flag - aa->flag;
	else
		return aa->p - bb->p;
}

int main()
{
	int cn, cc;
	freopen("l.in", "r", stdin);
	freopen("l.out", "w", stdout);

	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		int i,j;
		int n, m;
		FLOW arr[2000];
		__int64 sum = 0;
		__int64 count = 0;

		scanf("%d%d", &n, &m);

		for (i=0; i<m; i++)
		{
			int a, b, tn;
			scanf("%d%d%d", &a, &b, &tn);
			sum += ((__int64)( b-a )) * ( 2*((__int64)(n)) + 1 - (b-a) ) / 2 % MODE * tn % MODE;
			sum %= MODE;
			arr[2*i].flag = 1;
			arr[2*i].p = a;
			arr[2*i].n = tn;
			arr[2*i+1].flag = 0;
			arr[2*i+1].p = b;
			arr[2*i+1].n = tn;
		}

		qsort(arr, 2*m, sizeof(FLOW), cmp);

		for (i=0; i<2*m; i++) if (!arr[i].flag){
			for (j=i-1; j>=0; j--) if (arr[j].flag && arr[j].n)
			{
				int a, b, tn;
				a = arr[j].p;
				b = arr[i].p;
				tn = arr[j].n;
				if (tn > arr[i].n) tn = arr[i].n;
				arr[j].n -= tn;
				arr[i].n -= tn;
				sum += MODE - ( ((__int64)( b-a )) * ( 2*((__int64)(n)) + 1 - (b-a) ) / 2 % MODE * tn % MODE );
				sum %= MODE;
			}
		}

		printf("Case #%d: %I64d\n", cc, sum);
	}

	return 0;
}