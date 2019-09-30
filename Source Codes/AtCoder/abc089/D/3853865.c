#include <stdio.h>

int main() {
	int H, W, D;
	int A[350][350];
	int s[100050][2];
	int Q;
	int LR[100050][2];
	int turn[100000] = {};
	int i, j;
	int MP;

	for (i = 0; i < 330; i++)
	{
		for (j = 0; j < 330; j++)
		{
			A[i][j] = 0;
		}
	}

	for (i = 0; i < 100040; i++)
	{
		s[i][0] = 0;
		s[i][1] = 0;
		LR[i][0] = 0;
		LR[i][1] = 0;
	}

	scanf("%d%d%d", &H, &W, &D);

	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			scanf("%d", &A[i][j]);
			s[A[i][j]][0] = i;
			s[A[i][j]][1] = j;
		}
	}

	scanf("%d", &Q);


	for (i = 0; i < Q; i++)
	{
		scanf("%d", &LR[i][0]);//?????

		scanf("%d", &LR[i][1]);//?????
	}
	for (int i = D+1; i <= H*W; i++) {
		MP = 0;
		
		if (s[i][0] >= s[i-D][0])
		{
			MP = MP + s[i][0] - s[i-D][0];
		}
		else
		{
			MP = MP + s[i-D][0] - s[i][0];
		}

		if (s[i][1] >= s[i-D][1])
		{
			MP = MP + s[i][1] - s[i-D][1];
		}
		else
		{
			MP = MP + s[i-D][1] - s[i][1];
		}

		turn[i] = turn[i - D] + MP;
	}

	for (i = 0; i < Q; i++)//Q????
	{
		MP = turn[LR[i][1]]-turn[LR[i][0]];
		

		printf("%d\n", MP);

	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &H, &W, &D);
  ^
./Main.c:35:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &A[i][j]);
    ^
./Main.c:41:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &Q);
  ^
./Main.c:46:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &LR[i][0]);//?????
   ^
./Main.c:48:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &LR[i][1]);//?????
   ^