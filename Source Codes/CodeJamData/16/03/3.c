#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int total = 0;

long long power(a, b) {
	if (b == 0) {
		return 1;
	}
	return a * power(a, b - 1);
}

int choose(int num, int n, int mode, int * a, int * b, int * c) {
	int cycle;
	int bound;

	if (mode) {
		// Choose from larger number a
		bound = (n - 1) / 2;

		cycle = 0;
		while (cycle <= bound) {
			if (b[cycle] && c[cycle + num]) {
				return 0;
			}
			cycle ++;
		}
		
		cycle = 0;
		while (cycle <= bound) {
			if (b[cycle]) {
				c[cycle + num] = 1;
			}
			cycle ++;
		}

		a[num] = 1;
		return 1;
	}
	else {
		// Choose from smaller number b
		bound = n - 1;

		cycle = 0;
		while (cycle <= bound) {
			if (a[cycle] && c[cycle + num]) {
				return 0;
			}
			cycle ++;
		}
		
		cycle = 0;
		while (cycle <= bound) {
			if (a[cycle]) {
				c[cycle + num] = 1;
			}
			cycle ++;
		}

		b[num] = 1;
		return 1;
	}

	return 0;
}


void dhoose(int num, int n, int mode, int * a, int * b, int * c) {
	int cycle;
	int bound;

	if (mode) {
		// dhoose from larger number a
		bound = (n - 1) / 2;
		
		cycle = 0;
		while (cycle <= bound) {
			if (b[cycle] && c[cycle + num]) {
				c[cycle + num] = 0;
			}
			cycle ++;
		}
		a[num] = 0;
	}
	else {
		// dhoose from smaller number b
		bound = n - 1;
		
		cycle = 0;
		while (cycle <= bound) {
			if (a[cycle] && c[cycle + num]) {
				c[cycle + num] = 0;
			}
			cycle ++;
		}
		b[num] = 0;
	}

}

void print(int n, int * a, int * b, int * c) {

	/*
	int cycle = n - 1;
	while (cycle >= 0) {
		printf("%d", c[cycle]);
		cycle --;
	}

	printf(" = ");
	cycle = (n - 1) / 2;
	while (cycle >= 0) {
		printf("%d", b[cycle]);
		cycle --;
	}
	printf(" * ");
	cycle = n - 1;
	while (cycle >= 0) {
		printf("%d", a[cycle]);
		cycle --;
	}
	printf("\n");
	*/
	
	int cycle = n - 1;
	while (cycle >= 0) {
		printf("%d", c[cycle]);
		cycle --;
	}

	int bycle = 2;
	long long int sum;	
	while (bycle <= 10) {
		sum = 0;
		cycle = (n - 1) / 2;
		while (cycle >= 0) {
			sum = (sum * bycle) + b[cycle];
			cycle --;
		}
		printf(" %lld", sum);
		bycle ++;
	}

	printf("\n");

	total --;
	if (total == 0) {
		return;
	}
	
}

void work(int mina, int maxa, int mode, int n, int * a, int * b, int * c) {
	if (total == 0) {
		return;
	}
	print(n, a, b, c);
	if (total == 0) {
		return;
	}
	int cycle;

	if (mode) {
		cycle = mina;
		while (cycle < maxa) {
			if (choose(cycle, n, 1, a, b, c)) {
				work(cycle + 1, maxa, 1, n, a, b, c);

				if (total == 0) {
					return;
				}

				dhoose(cycle, n, 1, a, b, c);
			}
			cycle ++;
		}
	}
	
	cycle = 1;
	while (cycle < n - 1 - maxa) {
		if (choose(cycle, n, 0, a, b, c)) {
			work(mina, maxa, 0, n, a, b, c);

			if (total == 0) {
				return;
			}

			dhoose(cycle, n, 0, a, b, c);
		}
		cycle ++;
	}
}

int main() {
	
	int num;
	scanf("%d\n", &num);

	int count = 0;
	int n;
	int cycle;

	int * a;
	int * b;
	int * c;

	count = 0;
	while (count < num) {
		scanf("%d %d\n", &n, &total);
		count ++;
		printf("Case #%d:\n", count);

		a = (int *)malloc(n * sizeof(int));
		memset(a, 0, n * sizeof(int));

		b = (int *)malloc(((n + 1) / 2) * sizeof(int));
		memset(b, 0, ((n + 1) / 2) + 1 * sizeof(int));

		c = (int *)malloc(n * sizeof(int));
		memset(c, 0, n * sizeof(int));

		// choose(0, n, 0, a, b, c);
		// choose(0, n, 1, a, b, c);
		choose(0, n, 0, a, b, c);
		choose(0, n, 1, a, b, c);

		cycle = 1;
		while (cycle <= ((n / 2) - 1)) {
			choose(cycle, n, 0, a, b, c);
			choose(n - 1 - cycle, n, 1, a, b, c);

			work(1, n - 1 - cycle, 1, n, a, b, c);
			dhoose(cycle, n, 0, a, b, c);
			dhoose(n - 1 - cycle, n, 1, a, b, c);
			cycle ++;
		}
		
		dhoose(0, n, 0, a, b, c);
		dhoose(0, n, 1, a, b, c);

		free(a);
		free(b);
		free(c);
	}
}
