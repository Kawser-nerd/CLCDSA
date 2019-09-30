#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int T, N, D, K, S;
	double t, maxt;

	scanf("%d\n", &T);

	for(int i=0; i<T; i++)
	{
		scanf("%d %d\n",&D, &N);
		maxt = 0;
		for(int k = 0; k<N; k++)
		{
			scanf("%d %d", &K, &S);
			t = (D-K)/(float)S;
			if(t>maxt)
				maxt=t;
		}

		printf("Case #%d: %lf\n",i+1,D/maxt);
		/*
		for (int j = 0; j < N; j++,printf("\n"))
			for(int k=0; k<M; k++)
				printf("%c", A[j][k]);
				*/
	}

}
