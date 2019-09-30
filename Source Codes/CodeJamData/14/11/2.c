#include <stdio.h>

int N, L;


long long strsC[200];
long long strsD[200];

long long zArr[200];
long long oArr[200];

void sort(long long *arr, int s) {
	int i, j;
	for (i = 0; i < s; i++) {
		for (j = i + 1; j < s; j++) {
			if (arr[i] > arr[j]) {
				long long temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int flipBit(int bit, long long mask, long long use) {
	int i;
	int am0 = 0;
	int am1 = 0;
	for (i = 0; i < N; i++) {
		long long a = strsC[i];
		a &= use;
		a ^= mask;
		if (a & (1ll << bit)) {
			oArr[am1++] = a;
		}
	}
	for (i = 0; i < N; i++) {
		long long a = strsD[i];
		a &= use;
		if (a & (1ll << bit)) {
			zArr[am0++] = a;
		}
	}
	sort(zArr, am0);
	sort(oArr, am1);
	for (i = 0; i < am0 && i < am1; i++) {
		if (zArr[i] != oArr[i]) {
			return 1;
		}
	}
	return am0 != am1;
}

int different(long long *arr, int bit, long long use) {
	int i;
	int am0 = 0;
	int am1 = 0;
	for (i = 0; i < N; i++) {
		long long a = arr[i];
		a &= use;
		if (a & (1ll << bit)) {
			oArr[am1++] = a;
		} else {
			zArr[am0++] = a;
		}
	}
	sort(zArr, am0);
	sort(oArr, am1);
	for (i = 0; i < am0 && i < am1; i++) {
		if (zArr[i] != oArr[i]) {
			return 1;
		}
	}
	return am0 != am1;
}

void handle() {
	scanf ("%d %d ", &N, &L);
	int i, j;
	char st[50];
	for (i = 0; i < N; i++) {
		scanf ("%s ", &st[0]);
		long long c  = 0ll;
		for (j = 0; j < L; j++) {
			c *= 2ll;
			c += st[j] - '0';
		}
		strsC[i] = c;
	}
	for (i = 0; i < N; i++) {
		scanf ("%s ", &st[0]);
		long long c  = 0ll;
		for (j = 0; j < L; j++) {
			c *= 2ll;
			c += st[j] - '0';
		}
		strsD[i] = c;
	}
	int minAm = 100000;
	for (j = 0; j < N; j++) {
		long long mask = strsC[j] ^ strsD[0];
		for (i = 0; i < N; i++) {
			oArr[i] = strsC[i] ^ mask;
		}
		for (i = 0; i < N; i++) {
			zArr[i] = strsD[i];
		}
		sort(oArr, N);
		sort(zArr, N);
		int works = 1;
		for (i = 0; i < N && works; i++) {
			if (oArr[i] != zArr[i]) {
				works = 0;
			}
		}
		if (works) {
			int count = 0;
			for (i = 0; i < L; i++) {
				if (mask & (1ll << i)) {
					count++;
				}
			}
			if (count < minAm) {
				minAm = count;
			}
		}
	}
	
	if (minAm > L) {
		printf ("NOT POSSIBLE\n");
	} else {
		printf ("%d\n", minAm);
	}
}

int main() {
	int t;
	scanf ("%d ", &t);
	int i;
	for (i = 0; i < t; i++) {
		printf ("Case #%d: ", i + 1);
		handle();
	}
	return 0;
}