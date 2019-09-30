#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

inline int readInt() {
	int n, c;
	while ((c = getchar()) < '0');
	n = c - '0';
	while ((c = getchar()) >= '0') {
		n = n * 10 + c - '0';
	}
	return n;
}

const int N = 5000;
const int M = 200;

struct Stack {
	short dat[N + 1];
	short sp;

	void push(short v) {
		dat[sp++] = v;
	}

	void pop() {
		sp--;
	}

	short fst() {
		return dat[sp - 1];
	}

	short snd() {
		return dat[sp - 2];
	}
};

int n, m;
Stack mono[M];
int b[N + 1][M];
long long a[N];

struct Tuple {
	long long val, imos;
};
Tuple tup[N + 1];

int main() {
	n = readInt();
	m = readInt();
	for (int i = 1; i < n; i++) {
		a[i] = readInt() + a[i - 1];
		tup[i].val -= a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = readInt();
		}
	}
	for (int i = 0; i < m; i++) {
		b[n][i] = 2e9;
		mono[i].push(n);
	}

	long long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			while (b[mono[j].fst()][j] <= b[i][j]) {
				int l = mono[j].fst();
				int r = mono[j].snd();
				int v = b[l][j];
				mono[j].pop();
				tup[l].imos -= v;
				tup[r].imos += v;
			}
		}
		long long sum = 0;
		for (int j = 0; j < m; j++) {
			tup[mono[j].fst()].imos -= b[i][j];
			mono[j].push(i);
			sum += b[i][j];
		}
		long long u = -1e18;
		for (int j = i; j < n; j++) {
			sum += tup[j].imos;
			tup[j].imos = 0;
			tup[j].val += sum;
			u = max(u, tup[j].val);
		}
		ans = max(ans, u + a[i]);
	}
	cout << ans << endl;
}