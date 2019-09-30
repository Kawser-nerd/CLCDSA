#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

#include <stdlib.h>
#include <time.h>

using namespace std;

int N = 1000;
int dat[1024];
void sw(int &a, int &b) {
	int t = a; a = b; b = t;
}
void generateBAD() {
	for (int i = 0; i < N; i++) dat[i] = i;
	for (int i = 0; i < N; i++) {
		int v = rand() % N;
		sw(dat[i], dat[v]);
	}
}
void generateGOOD() {
	for (int i = 0; i < N; i++) dat[i] = i;
	for (int i = 0; i < N; i++) {
		int v = rand() % (N-i);
		sw(dat[i], dat[i+v]);
	}
}
bool chk[1024];
int main() {
	srand(clock());
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	/*
	double pup = 1;
	for (int i = 1; i <= 1000; i++) {
		pup += log((double)1000.0 / i) / log(10.0);
	}
	return 0;
	*/
	/*
	for (int t = 0; t<1000; t++) {
		generateGOOD();
		int maxc = -1, maxi = -1;
		double cc = 0;
		for (int i = 0; i<N; i++) chk[i] = false;
		for (int i = 0; i<N; i++) {
			int dif = dat[i] - i;
			if (dif < 0) dif = -dif;
			else dif = 0;
			if (dif > 2) {
				cc += log(dif-1);
			}
		}
		printf("%.1lf\n", cc);
	}
	*/
	//return 0;
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &dat[i]);
		}
		
		double cc = 0;
		for (int i = 0; i<N; i++) {
			int dif = dat[i] - i;
			if (dif < 0) dif = -dif;
			else dif = 0;
			if (dif > 2) {
				cc += log(dif - 1);
			}
		}
		static int cs = 1;
		printf("Case #%d: %s\n", cs++, cc>2628.0 ? "GOOD":"BAD");
	}
	return 0;
}