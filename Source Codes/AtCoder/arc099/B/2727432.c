#include <stdio.h>
#include <inttypes.h>
#include <string.h>

double notomamiko(uint64_t sinntasu) {
	uint64_t hayamin = sinntasu;
	uint64_t kugyu = 0;
	while (hayamin > 0) {
		kugyu += hayamin % 10;
		hayamin /= 10;
	}
	return (double)sinntasu / kugyu;
}

uint64_t get_next_9(uint64_t mimorinn) {
	char horieyui[99];
	size_t l;
	uint64_t delta = 10;
	snprintf(horieyui, sizeof(horieyui), "%"PRIu64, mimorinn);
	l = strlen(horieyui) - 1;
	while (l > 0 && horieyui[l] == '9') {
		l--;
		delta *= 10;
	}
	return mimorinn / delta * delta + (delta - 1);
}

int main(void) {
	uint64_t K, i;
	uint64_t inorinn = 1;
	uint64_t sikachann;
	if (scanf("%"SCNu64, &K) != 1) return 1;
	for (i = 0; i < K; i++) {
		printf("%"PRIu64"\n", inorinn);
		inorinn++;
		while (notomamiko(inorinn) > notomamiko(sikachann = get_next_9(inorinn))) {
			inorinn = sikachann;
		}
	}
	return 0;
}

/*
i????k????
???i=3
100 <= k <= 999
S(100)=1 <= S(k) <= S(999)=27

(10**(k-1))/(9*i) <= k/S(k) <= (10**k)-1

-----

?? : 1?or??????????9 ?? ????
????????

-----

???????????9????????????

*/

/* ??????? ? gnuplot */
#if 0
#include <stdio.h>

int S(int n) {
	int r = 0;
	while (n > 0) {
		r += n % 10;
		n /= 10;
	}
	return r;
}

int main(void) {
	int i;
	printf("i     S(i) i/S(i)\n");
	for (i = 1; i <= 10000; i++) {
		int si = S(i);
		printf("%5d %4d %9.3f\n", i, si, (double)i / si);
	}
	return 0;
}
#endif

/* ???????? */
#if 0
#include <stdio.h>

int S(int n) {
	int r = 0;
	while (n > 0) {
		r += n % 10;
		n /= 10;
	}
	return r;
}

int si[100001];
double isi[100001];
double min[100001];
int min_index[100001];

int main(void) {
	int i;
	for (i = 1; i <= 100000; i++) {
		si[i] = S(i);
		isi[i] = (double)i / si[i];
	}
	min[100000] = isi[100000];
	min_index[100000] = 100000;
	for (i = 99999; i >= 1; i--) {
		min[i] = min[i + 1];
		min_index[i] = min_index[i + 1];
		if (isi[i] < min[i]) {
			min[i] = isi[i];
			min_index[i] = i;
		}
	}
	printf("i      S(i) i/S(i) min      min_index maybe_sunuke\n");
	for (i = 1; i <= 100000; i++) {
		printf("%6d %4d %9.3f %9.3f %6d    %s\n",
			i, si[i], isi[i], min[i], min_index[i], isi[i] <= min[i] ? "YES!!!!!!!" : "NO");
	}
	return 0;
}
#endif