#include <stdio.h>

unsigned long long M[1000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++)
	{
		int N, B;
		scanf("%d %d", &B, &N);
		for (int i=0; i<B; i++)
			scanf("%lld", &M[i]);
		
		unsigned long long L = 0;
		unsigned long long H = (unsigned long long)N * (unsigned long long)100000;
		while (L+1 < H)
		{
			unsigned long long P = (H + L)/2;
			unsigned long long custs = 0;
			for (int i=0; i<B; i++)
				custs += 1 + P / M[i];
			if (custs < N)
				L = P+1;
			else
				H = P;
		}

		int frees = 0;
		for (int i=0; i<B; i++)
		{
			N -= L / M[i];
			if (L % M[i] == 0)
				frees++;
			else
				N--;
		}
		if (N > frees)
		{
			N -= frees;
			L++;
		}
		for (int i=0; i<B; i++)
		{
			if (L % M[i] == 0)
				N--;
			if (N == 0)
			{
				printf("Case #%d: %d\n", t, i+1);
				break;
			}
		}
	}
	return 0;
}

