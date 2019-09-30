#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	if(a > b) return(a);
	return(b);
}

int min(int a, int b)
{
	if(a < b) return(a);
	return(b);
}

int N;
char S[100][101];

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)  {
		scanf("%s", S[i]);
	}
	int ret = 0;
	for(int i = 0; i < N; i++) {
		int j = N - 1;
		while(j >= 0 && S[i][j] == 'o') --j;
		if(j == -1) continue;
		++ret;
		for(int k = j; k >= 0; k--) S[i][k] = 'o';
		if(i!=N-1) for(int k = j; k < N; k++) S[i + 1][k] = 'o';
	}

	printf("%d\n", ret);
	
	
	return(0);
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S[i]);
   ^