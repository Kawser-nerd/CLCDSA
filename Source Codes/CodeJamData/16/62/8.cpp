#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, k;
long long pps[11000000];
long long pp[11000000];
long long r[11000000];
const long long m = 1000000007;

void read() {
	scanf("%d %d", &n, &k);
}

void solve() {
	pp[1] = 0;
	pp[2] = 1;
	pps[2] = 1;

	for (int i = 3; i <= n; i++) {
		pp[i] = (r[i-1] + pps[i-2] * r[i-1]) % m;
		pps[i] = (pps[i-1] + pp[i]) % m;
	}

	int l = k;
	int r = n-k+1;

	//printf("pp3 = %lld %lld\n", pp[3], (1-pp[3]+m)%m);

	long long ans = ((1 - pp[l]) * (1 - pp[r])) % m;
	ans = (1 - ans) % m;
	while (ans < 0) ans += m;
	printf("%lld\n", ans);
}


























int myMod = 0;
int howMany = 1;

int main(int argc, char** argv) {
	r[1] = 1; for (int i=2; i<=10000000; ++i) r[i] = (m - (m/i) * r[m%i] % m) % m;

	if (argc > 1) {
		stringstream ss; ss << argv[1]; ss >> myMod;
		ss.str(""); ss.clear();
		ss << argv[2]; ss >> howMany;
	}

	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		read();
		if (i % howMany == myMod) {
			fprintf(stderr, ">%d<\n", i+1);
			printf("Case #%d: ", i+1);
			solve();
		}
	}
}