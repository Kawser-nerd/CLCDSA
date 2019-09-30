#include <iostream>
#include <cstdio>

using namespace std;

#define NUM_MINS 1600

int fromA[NUM_MINS];
int toA[NUM_MINS];
int fromB[NUM_MINS];
int toB[NUM_MINS];

int needA;
int needB;

void countTrains() {
	needA = 0;
	needB = 0;
	int cA = 0;
	int cB = 0;
	for (int i = 0; i < NUM_MINS; i++) {
		cA += toA[i];
		cB += toB[i];
		if (fromA[i] > cA) {
			needA += fromA[i] - cA;
			cA = fromA[i];
		}
		if (fromB[i] > cB) {
			needB += fromB[i] - cB;
			cB = fromB[i];
		}
		cA -= fromA[i];
		cB -= fromB[i];
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int T;
		int NA;
		int NB;
		cin >> T;
		cin >> NA;
		cin >> NB;
		for (int j = 0; j < NUM_MINS; j++) {
			fromA[j] = 0;
			toA[j] = 0;
			fromB[j] = 0;
			toB[j] = 0;
		}
		int h1, m1, h2, m2;
		char c1, c2;
		for (int j = 0; j < NA; j++) {
			cin >> h1 >> c1 >> m1 >> h2 >> c2 >> m2;
			fromA[h1 * 60 + m1]++;
			toB[h2 * 60 + m2 + T]++;
		}
		for (int j = 0; j < NB; j++) {
			cin >> h1 >> c1 >> m1 >> h2 >> c2 >> m2;
			fromB[h1 * 60 + m1]++;
			toA[h2 * 60 + m2 + T]++;
		}
		for (int j = 0; j < NUM_MINS; j++) {
#ifdef DEBUG
			if (fromA[j] > 0 || fromB[j] > 0 || toA[j] > 0 || toB[j] > 0) {
				printf("%5d %5d %5d %5d %5d\n", j, fromA[j], toA[j], fromB[j], toB[j]);
			}
#endif
		}
		countTrains();
		printf("Case #%d: %d %d\n", i, needA, needB);
	}
}


