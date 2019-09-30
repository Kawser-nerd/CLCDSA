#include <stdio.h>

int main(int argc, char* argv[]) {

	int n, prev, curr;
	int count = 0;
	scanf("%d", &n);
	prev = n % 10;
	n = n / 10;
	count++;
	while(n != 0) {
		curr = n % 10;
		if(prev == curr) {
			count++;
			prev = curr;
		} else {
			count = 1;
			prev = curr;
		}
		if(count == 3) {
			printf("Yes");
			return 0;
		}
		n = n / 10;
	}

	printf("No");

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^