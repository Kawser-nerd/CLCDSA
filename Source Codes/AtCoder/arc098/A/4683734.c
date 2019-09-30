#include<stdio.h>
char S[1000002];
int e[1000002];
int w[1000002];
int main() {
	int N;
	int  min = 1000002;
	int tmp = 0;
	int ans;
	scanf("%d", &N);
	scanf("%s", &S);
	for (int i = 0; i < N; i++)
	{
		if (S[i] == 'E')
		{
			e[i]++;
		}
		else if (S[i] == 'W')
		{
			w[i]++;
		}
		if (i > 0)
		{
			e[i] = e[i - 1] + e[i];
			w[i] = w[i - 1] + w[i];
		}
	}


	for (int i = 0; i < N; i++)
	{
		if (i == 0) {
			tmp = e[N - 1] - e[i];
		}
		else if (i == N - 1) {
			tmp = w[i - 1];
		}
		else {
			tmp = w[i - 1] + (e[N - 1] - e[i]);
		}

		if (tmp < min)
		{
			min = tmp;
		}
	}
	ans = min;
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[1000002]’ [-Wformat=]
  scanf("%s", &S);
        ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &S);
  ^