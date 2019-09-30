#include <stdio.h>

int num[10000];

main()
{
	int TC, T = 0;
	int N, L, U;
	int i, j;
	scanf("%d", &TC);
	while (T++ < TC) {
		scanf("%d %d %d", &N, &L, &U);
		for (i = 0; i < N; i++)
			scanf("%d", &num[i]);
		for (i = L; i <= U; i++) {
			for (j = 0; j < N; j++)
				if (num[j]%i && i%num[j])
					break;
			if (j == N) {
				printf("Case #%d: %d\n", T, i);
				break;
			}
		}
		if (i > U)
			printf("Case #%d: NO\n", T);
	}
	return 0;
}

