#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

int cmp(const void* a, const void* b)
{
	return *((int*)a) - *((int*)b);
}

int main()
{
	int T, t;
	int N, ans, i;
	int index[128];
	int counter[128];
	char str[128][128];
	char now;
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%d", &N);
		for(i = 0; i < N; i++)
			scanf("%s", str[i]);
		memset(index, 0, sizeof(index));
		ans = 0;
		now = str[0][0];
		do{
			memset(counter, 0, sizeof(counter));
			for(i = 0; i < N; i++) {
				if(str[i][ index[i] ] != now) {
					ans = -1;
					goto end;
				}
				while(str[i][ index[i] ] == now) {
					index[i]++;
					counter[i]++;
				}
			}
			qsort(counter, N, sizeof(int), cmp);
			for(i = 0; i < N; i++) {
				ans += abs(counter[i] - counter[N/2]);
			}
			now = str[0][ index[0] ];
		}while(now);
		for(i = 1; i < N; i++)
			if(str[i][ index[i] ]) {
				ans = -1;
				break;
			}
end:
		if(ans < 0)
			printf("Case #%d: Fegla Won\n", t);
		else
			printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
