#include<stdio.h>

int main()
{
	int C, t, R, T, W;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%d %d %d", &R, &C, &W);
		printf("Case #%d: %d\n", t, R * ((C / W) + ((C % W) ? 1 : 0)) + R * (W - 1));
	}
	return 0;
}