#include <stdio.h>
#include <stdlib.h>

long long arr[1000];

int count (int n) {
	int i = 0,j = n-1;
	int c = 0;
	while (i < j) {
		int mini = i, k;
		for (k = i; k <= j; k++)
			if (arr[k] < arr[mini])
				mini = k;
		if (mini - i < j - mini) {
			c += mini - i;
			long long tmp = arr[mini];
			for (k = mini; k > i; k--)
				arr[k] = arr[k - 1];
			arr[i] = tmp;
			i++;
		} else {
			c += j - mini;
			long long tmp = arr[mini];
			for (k = mini; k < j; k++)
				arr[k] = arr[k + 1];
			arr[j] = tmp;
			j--;
		}
	}
	return c;
}

int main () {
	int T;
	scanf("%d", &T);
	int t;
	for (t = 1; t <= T; t++) {
		int n;
		scanf("%d", &n);
		int i;
		for (i = 0; i < n; i++)
			scanf("%lld", arr + i);
		printf("Case #%d: %d\n", t, count(n));
	}
	return 0;
}
