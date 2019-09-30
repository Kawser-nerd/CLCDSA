#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

typedef struct {
	int E, S;
} horse_t;

int N, Q;
horse_t H[128];
int D[128][128];
int Qs[128][2];

double ride_time(int horse, double dist) {
	if (H[horse].E < dist)
		return DBL_MAX;
	return dist / H[horse].S;
}

double best_ride(int current_city, int current_horse) {
	if (current_city == N)
		return 0;

	int dist = D[current_city][current_city + 1];

	double t1 = ride_time(current_horse, dist);
	if (t1 < DBL_MAX) { 
		H[current_horse].E -= dist;
		t1 += best_ride(current_city + 1, current_horse);
		H[current_horse].E += dist;
	}

	double t2 = ride_time(current_city, dist);
	if (t2 < DBL_MAX) { 
		H[current_city].E -= dist;
		t2 += best_ride(current_city + 1, current_city);
		H[current_city].E += dist;
	}

	return t1 < t2 ? t1 : t2;
}

int main() {
	int t, x = 1;
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d %d\n", &N, &Q);
		for (int i = 1; i <= N; ++i) {
			scanf("%d %d\n", &H[i].E, &H[i].S);
		}
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				scanf("%d ", &D[i][j]);
			}
		}
		for (int i = 0; i < Q; ++i) {
			scanf("%d %d\n", &Qs[i][0], &Qs[i][1]);
		}
		printf("Case #%d: %lf\n", x++, best_ride(1, 1));
	}
	return 0;
}
