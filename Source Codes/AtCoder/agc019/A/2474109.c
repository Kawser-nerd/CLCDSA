#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

unsigned long long int price[4];
unsigned long long int n;

int main() {
	for(int i = 0; i < 4; i++) {
		scanf("%llu", &price[i]);
	}
	scanf("%llu", &n);
	if(n == 1) {
		price[0] *= 4;
		price[1] *= 2;

		unsigned long long int min = 1844674407370955161;
		for (int i = 0; i < 3; i++) {
			if(min > price[i]) {
				min = price[i];
			}
		}
		printf("%llu\n", min);
	}
	else {
		price[0] *= 8;
		price[1] *= 4;
		price[2] *= 2;

		unsigned long long int min = 1844674407370955161;
		for(int i = 0; i < 4; i++) {
			if(min > price[i]) {
				min = price[i];
			}
		}

		if(n % 2 == 0) {
			//??0
			printf("%llu\n", n / 2 * min);
		}
		else {
			unsigned long long int min_new = 1844674407370955161;
			for (int i = 0; i < 3; i++) {
				if(min_new > price[i]) {
					min_new = price[i];
				}
			}
			printf("%llu\n", n / 2 * min + min_new / 2);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu", &price[i]);
   ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &n);
  ^