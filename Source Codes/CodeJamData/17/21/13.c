#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int start;
	int speed;
	double pos;
} horse_t;

int D, N;
horse_t H[10001]; 

int slowest() {
	int slow = 10000000, slowp = -1;
	for (int i = 0; i < N; ++i) {
		if (H[i].pos < D && H[i].speed < slow)
			slowp = i, slow = H[i].speed;
	}
	return slowp;
}

int main() {
	int t, x = 1;
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d %d\n", &D, &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d %d\n", &H[i].start, &H[i].speed);
			H[i].pos = H[i].start;
		}

		double mintime = 0;
		int k = slowest();
		while (k != -1) {
			double tta = (D - H[k].pos) / (double) H[k].speed;
			mintime += tta;
			for (int i = 0; i < N; ++i) {
				H[i].pos += H[i].speed * tta;
			}
			k = slowest();
		}

		printf("Case #%d: %lf\n", x++, D / mintime);
	}
}
