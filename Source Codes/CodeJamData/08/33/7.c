#include <stdio.h>
#include <stdlib.h>

int n; /* Length of sequence */
int m; /* Length of generating array */
long long X;
long long Y;
int Z;

int G[101];
int A[600000];
int res[600000];

int solve()
{
	int i=n-1;
	int j;
	unsigned int v;
	int b;

	for (i=n-1; i>=0; i--)
	{
		res[i]=1;
		b=0;
		for (j=i+1; j<n; j++)
		{
			if (A[i]<A[j])
			{
			res[i]+=res[j];
			while (res[i]>=1000000007)
				res[i]-=1000000007;
			}
		}
	}

	/* for (i=0; i<n; i++)
	{
		printf ("%d ", res[i]);
	}
	printf ("\n"); */

	v=res[0];

	for (i=1; i<n; i++)
	{
		v+=res[i];
			while (v>=1000000007)
					v-=1000000007;
	}

	return v; 

}

int main(void)
{
	int N;
	int tc;
	int i,j;
	int v;
	int Y2;

	scanf ("%d", &N);


	for (tc=1; tc<=N; tc++)
	{
		scanf ("%d %d %d %d %d", &n, &m, &X, &Y, &Z);

		for (i=0; i<m; i++)
			scanf ("%d", G+i);

		/* printf (":"); */
		Y2=0;
		for (i=0,j=0; i<n; i++, j++)
		{
			Y2=(Y2+Y)%Z;
			if (j==m) j=0;
			A[i]=G[j];
			/* printf ("%d ", A[i]); */
			G[j]=(X*G[j]+Y2)%Z;
		}
		/* printf ("\n");*/

		v=solve();
			printf ("Case #%d: %d\n", tc, v);
	}


}