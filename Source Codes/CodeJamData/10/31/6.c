#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int t, T;
	int a[1500];
	int b[1500];
	int n, N;
	int result;
	int i;

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &N);
		result = 0;
		for (n = 0; n < N; n++) {
			scanf("%d%d",&a[n],&b[n]);
			if (n > 0)
				for (i = 0; i < n; i++)
					if ((a[n] - a[i]) * (b[n] - b[i]) < 0)
						result++;
		//code
		}
		


		printf("Case #%d: ",t);
		printf("%d", result);
	//result
	
		printf("\n");
	}

	return 0;
}
