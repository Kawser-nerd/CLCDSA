#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int T, N, M;
	char A[25][25], mark[25];

	scanf("%d\n", &T);

	for(int i=0; i<T; i++)
	{
		scanf("%d %d\n",&N, &M);

		for(int k = 0; k<N; k++,scanf("\n"))
		{
			mark[k]=0;
			char c = '?';
			for(int j = 0; j < M; j++)
			{
				scanf("%c",&A[k][j]);
				if(A[k][j]=='?')
					A[k][j]=c;
				else 
					c = A[k][j];
			}
		}

		for(int j = 0; j < N; j++)
		{
			int k=0;
			while(k<M && A[j][k]=='?')
				k++;
			if(k==M)
				mark[j]=1;
			else
			{
				for(int k1 = 0; k1 < k; k1++)
					A[j][k1]=A[j][k];
			}
		}
		int m=0;
		for(int j=0; j<N; j++)
		{
			if(mark[j]==1)
			{
				if(m==1)
					for(int k = 0; k<M; k++)
						A[j][k]=A[j-1][k];
			}
			else
			{
				if(m==0)
				{
					for(int j1=0; j1<j; j1++)
					{
						for(int k = 0; k<M; k++)
							A[j1][k]=A[j][k];
					}
				}
				m=1;
			}
		}


		printf("Case #%d:\n",i+1);
		for (int j = 0; j < N; j++,printf("\n"))
			for(int k=0; k<M; k++)
				printf("%c", A[j][k]);
	}

}
