#include <stdio.h>
#include <stdlib.h>

typedef struct _Numbers {
	int size;
	int *s;
}Numbers;

int main(void) {
	int n, m, sw;
	Numbers Num;
	scanf("%d", &n);
	Num.s = (int *)malloc(sizeof(int)*n);
	scanf("%d", Num.s);
	Num.size = 1;
	for (int i = 1; i < n; i++) {
		sw = 1;
		scanf("%d", &m);
		for (int j = 0; j < Num.size; j++) {
			if (m == Num.s[j]) {
				sw = 0;
				break;
			}
		}
		if (sw) {
			Num.s[Num.size] = m;
			Num.size++;
		}
	}
	printf("%d\n", Num.size);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", Num.s);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &m);
   ^