
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
double K[2000], S[2000];
double D;
int N;
const double ep = 1.0e-9;
bool canGo(double V) {
	for (int i = 0; i < N; i++) {
		double dV = V - S[i];
		if (dV <= ep) continue;

		double time = K[i] / (V - S[i]);
		double hello = time * V;
		if (hello < D) return false;
	}
	return true;
}
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%lf %d", &D, &N);
		for (int i = 0; i < N; i++) {
			scanf("%lf %lf", &K[i], &S[i]);
		}
		static int cs = 1;
	
		double s = 0.0, e = 1.0;
		while (canGo(e)) e *= 2.0;
		for (int i=0;i<10000;i++) {
			double m = (s + e) / 2;
			if (canGo(m)) s = m;
			else e = m;
		}
		printf("Case #%d: %.9lf\n", cs++, e);
	}
	return 0;
}