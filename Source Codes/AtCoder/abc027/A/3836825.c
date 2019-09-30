#include <stdio.h>

int main()
{
	int l1, l2, l3;
	scanf("%d%d%d", &l1, &l2, &l3);
	int count = l1;
	if (l2 == count) {
		count = 2;
	} else if (count == l3) {
		count = 3;
	} else {
		count = 1;
	}
	if (count == 2) {
		printf("%d\n", l3);
	} else if (count == 3) {
		printf("%d\n", l2);
	} else if (count == 1) {
		printf("%d\n", l1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &l1, &l2, &l3);
  ^