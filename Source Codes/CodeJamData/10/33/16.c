#include <stdlib.h>
#include <stdio.h>

unsigned m, n;
unsigned bord[512][512];
unsigned sizes[512][512];

unsigned min(unsigned a, unsigned b, unsigned c) {
	unsigned res = a;
	if (b < res) { res = b; }
	if (c < res) { res = c; }
	return res;
}

void calc () {
	int i, j;
	for (i = 0; i < m; i++) {
		sizes[i][n-1] = (bord[i][n-1] > 0) ? 1 : 0;
	}
	for (j = 0; j < n; j++) {
		sizes[m-1][j] = (bord[m-1][j] > 0) ? 1 : 0;
	}
	for (i = m-2; i >= 0; i--) {
		for (j = n-2; j >= 0; j--) {
			if (bord[i][j] == 0) {
				sizes[i][j] = 0;
			} else if ((bord[i][j] == 2 && bord[i+1][j] == 1 && bord[i][j+1] == 1 && bord[i+1][j+1] == 2) ||
			           (bord[i][j] == 1 && bord[i+1][j] == 2 && bord[i][j+1] == 2 && bord[i+1][j+1] == 1)) {
				sizes[i][j] = min(sizes[i][j+1], sizes[i+1][j], sizes[i+1][j+1]) + 1;
			} else {
				sizes[i][j] = 1;
			}
		}
	}
}

void input () {
	unsigned i, j;
	char c;
	unsigned b;
	
	scanf ("%u%u ", &m, &n);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j+=4) {
			scanf ("%c", &c);
			if (c >= '0' && c <= '9') {
				b = c - '0';
			} else {
				b = (c - 'A')+10;
			}
			bord[i][j] = (b & (1 << 3)) ? 2 : 1;
			bord[i][j+1] = (b & (1 << 2)) ? 2 : 1;
			bord[i][j+2] = (b & (1 << 1)) ? 2 : 1;
			bord[i][j+3] = (b & (1 << 0)) ? 2 : 1;
		}
		scanf (" ");
	}
}

void dump () {
	unsigned i, j;
	printf ("---\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf ("%u", bord[i][j]);
		}
		printf (" ");
		for (j = 0; j < n; j++) {
			printf ("%2u", sizes[i][j]);
		}
		printf ("\n");
	}
}

void doit () {
	unsigned i, j, max, k, l;
	unsigned count[513];
	unsigned int diff;
	int check;
	
	input ();
	
	for (i = 1; i < 513; i++) {
		count[i] = 0;
	}
	
	do {
		calc ();
		/*dump ();*/
		max = 1;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (sizes[i][j] > max) {
					max = sizes[i][j];
				}
			}
		}
		if (max > 1) {
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					if (sizes[i][j] == max) {
						check = 1;
						for (k = 0; k < max && check; k++) {
							for (l = 0; l < max && check; l++) {
								if (bord[i+k][j+l] == 0) {
									check = 0;
								}
							}
						}
						if (check) {
							count[max]++;
							for (k = 0; k < max; k++) {
								for (l = 0; l < max; l++) {
									bord[i+k][j+l] = 0;
									sizes[i+k][j+l] = 0;
								}
							}
						}
					}
				}
			}
		}
	} while (max > 1);
	
	count[1] = m*n;
	diff = 0;
	for (i = 2; i < 513; i++) {
		count[1] -= i*i*count[i];
		if (count[i] > 0) {
			diff++;
		}
	}
	if (count[1] > 0) {
		diff++;
	}
	
	printf ("%u\n", diff);
	for (i = 512; i > 0; i--) {
		if (count[i] > 0) {
			printf ("%u %u\n", i, count[i]);
		}
	}
}

int main () {
	unsigned i, t;
	
	scanf ("%u ", &t);
	for (i = 1; i <= t; i++) {
		printf ("Case #%u: ", i);
		doit ();
	}
	
	return 0;
}
