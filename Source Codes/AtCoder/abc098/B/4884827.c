#include <stdio.h>

int main()
{
	int NUM[100];
	int BOOLEANS[100];
	for(int i = 0; i < 100; i++)
	{
		NUM[i] = 0;
		BOOLEANS[i] = 0;
	}
	int N = 0;
	scanf("%d", &N);
	char S[100];
	scanf("%s", S);
	
	for(int i = 0; i < N; i++)
	{
		if(BOOLEANS[i] == 0)
		{
			BOOLEANS[i] = 1;
			int tem = 0;
			for(int j = i + 1; j < N; j++)
			{
				if(S[i] == S[j])
				{
					//printf("%c %d\n", S[j], j);
					BOOLEANS[j] = 1;
					tem = j;
				}
			}
			for(int j = i; j < tem; j++)
			{
				//printf("%d ", j);
				NUM[j]++;
			}
		}
	}
	int max = 0;
	for(int i = 0; i < N; i++)
	{
		if(max < NUM[i]) max = NUM[i];
	}
	printf("%d\n", max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^