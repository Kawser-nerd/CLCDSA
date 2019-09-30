#include <stdio.h>

int main()
{
	int y, m, d;
	int ans;
	scanf("%d%d%d", &y, &m, &d);
	if (m == 1 || m == 2) {
		y = y - 1;
		m += 12;
		ans = (365*y) + (y/4) - (y/100) + (y/400) + (306*(m+1)/10) + d - 429;
		printf("%d\n", (735369-ans));
	} else {
		ans = (365*y) + (y/4) - (y/100) + (y/400) + (306*(m+1)/10) + d - 429
    ;
	printf("%d\n", (735369-ans));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &y, &m, &d);
  ^