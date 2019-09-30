#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 2000;

int N;
double L[MAXN];
double R[MAXN];

void precomp() {
	sort(L, L + N);
	sort(R, R + N);
}

int numCheat() {
	int pts = 0;
	for(int i = 0, j = 0; i < N && j < N; ) {
		if(R[j] < L[i]) i++, j++, pts++;
		else i++;
	}
	return pts;
}

int numLegit() {
	int pts = 0;
	for(int i = 0, j = 0; i < N && j < N; ) {
		if(R[j] < L[i]) pts++, j++;
		else i++, j++;
	}
	return pts;
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> N;
		for(int i = 0; i < N; i++) cin >> L[i];
		for(int i = 0; i < N; i++) cin >> R[i];
		precomp();
		int a = numCheat(), b = numLegit();
		cout << "Case #" << t << ": " << a << ' ' << b << '\n';
	}
}
