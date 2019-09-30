#include<stdio.h>
int main() {
	int N, S;
	int zcnt = 0, sum = 0, min = 105, ans;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &S);
		sum += S;
		if (S < min && S % 10 != 0)
		{
			min = S;
		}
	}
	if (sum % 10 == 0 && min != 105)
	{
		ans = sum - min;
	}
	else if (sum % 10 == 0 && min == 105)
	{
		ans = 0;
	}
	else
	{
		ans = sum;
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &S);
   ^