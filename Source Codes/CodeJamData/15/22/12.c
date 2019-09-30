
#include <stdio.h>
#include <stdlib.h>

int
score(char *b, int R, int C) 
{
	int unhappy = 0;
	
	for (int r = 0; r < R; r++)
	for (int c = 0; c < C; c++)
	{
		if (b[r*C+c]) {
			if (r+1 < R) unhappy += b[(r+1)*C+c];
			if (c+1 < C) unhappy += b[r*C+c+1];	
		}
	}


	return unhappy;
}

int try(int r, int c, int R, int C, char *b, int n, int N) 
{
	if (n == N) return score(b, R, C);
	if (c == C) return 1<<30;
	
	int next_r = (r+1)%R;
	int next_c = (c+(next_r == 0 ? 1 : 0));
	
	
	b[r*C+c] = 0;
	int aaa = try(next_r, next_c, R, C, b, n, N);
	
	b[r*C+c] = 1;
	int bbb = try(next_r, next_c, R, C, b, n+1, N);
	
	return aaa > bbb ? bbb : aaa;
}

int 
main(int argc, char **argv)
{


	int casesTotal;	
	scanf("%d", &casesTotal);

	int R, C, N;
	
	for(int caseNo = 1; caseNo <= casesTotal; caseNo++)
	{
		scanf("%d", &R);
		scanf("%d", &C);
		scanf("%d", &N);
	
		
	
		if (N * 2 <= R * C) {
			printf("Case #%d: %d\n", caseNo, 0);
			continue;
		
		}

		char b[R*C];
		for (int i = 0; i < R*C; i++) b[i] =0;
		printf("Case #%d: %d\n", caseNo, try(0, 0, R, C, b, 0, N));
	}
}