#include <stdio.h>

void solveCase()
{
	char res[100][100];
	double WP[100];
	int tc[100];
	double OWP[100];
	double OOWP[100];
	int N;
	int i, j;
	int count,sum;
	double s;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			scanf(" %c", &res[i][j]);
		}
	}
	
	for (i=0; i<N; i++)
	{
		count = sum = 0;
		for (j=0; j<N; j++)
		{
			if (res[i][j] == '.')
				continue;
			count++;
			sum += res[i][j] -'0';
		}
		tc[i] = count;
		WP[i] = ((double)sum)/((double)count);
	}
	
	for (i=0; i<N; i++)
	{
		s = 0;
		for (j=0; j<N; j++)
		{
			if (res[i][j] == '.')
				continue;
			if (res[i][j] == '0')
				s += (WP[j]-1/((double)tc[j])) * ((double)tc[j])/((double)(tc[j]-1));
			else
				s += WP[j] * ((double)tc[j])/((double)(tc[j]-1));
		}
		OWP[i] = s/((double)tc[i]);
	}
	
	for (i=0; i<N; i++)
	{
		s =0;
		for (j=0; j<N; j++)
		{
			if (res[i][j] == '.')
				continue;
			s += OWP[j];
		}
		
		OOWP[i] = s/((double)tc[i]);
	}
	
	for (i=0; i<N; i++)
	{
		printf("%.8f\n", 0.25*WP[i] + 0.5*OWP[i] + 0.25*OOWP[i]);
	}
}

int main()
{
	int i, T;
	
	scanf("%d", &T);
	
	for (i=0; i<T; i++)
	{
		printf("Case #%d:\n", i+1);
		solveCase();
	}
	
	return 0;
}
