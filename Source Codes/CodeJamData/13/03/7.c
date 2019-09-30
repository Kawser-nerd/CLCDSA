#include <stdio.h>
#include <string.h>

int main()
{
	int is[1024], count[1024];
	int cas_n, cas, i, A, B;
	memset(is, sizeof(is), 0);
	memset(count, sizeof(count), 0);
	is[1] = 1;
	is[4] = 1;
	is[9] = 1;
	is[121] = 1;
	is[484] = 1;
	for(i=1; i<1024; i++)
		count[i] = count[i-1] + is[i];
	scanf("%d", &cas_n);
	for(cas=1; cas <= cas_n; cas++) {
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d\n", cas, count[B] - count[A - 1]);
	}
	return 0;
}
