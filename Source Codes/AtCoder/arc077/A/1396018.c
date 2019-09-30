#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, n, k;
	int *a, *b;

	a = (int *)malloc(200001 * sizeof(int));
	b = (int *)malloc(200001 * sizeof(int));

	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	
	if(n == 1) {
		printf("%d", a[1]/10);
	}

	else if(n % 2 == 0){
		i = 1;
		while(n - 2 * (i - 1) != 2) {
			b[i] = a[n - 2 * (i - 1)];
			i++;
		}

		b[i] = a[2];
		i++;
		k = 0;

		while(2 * k + 1 != n - 1) {
			b[i] = a[2 * k + 1];
			i++;
			k++;
		}
		b[i] = a[n - 1];

	}

	else if(n % 2 == 1 && n != 1){
		i = 1;
		while(n - 2 * (i - 1) != 1) {
			b[i] = a[n - 2 * (i - 1)];
			i++;
		}

		b[i] = a[1];
		i++;
		k = 1;

		while(2 * k != n - 1) {
			b[i] = a[2 * k];
			i++;
			k++;
		}
		b[i] = a[n - 1];

	}

	for(i = 1; i <= n; i++) {
		printf("%d ", b[i]);
	}
	free(a);
	free(b);   
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^