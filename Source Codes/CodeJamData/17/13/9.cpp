#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define INF 1000000007

int hd, ad, hk, ak, b, d;

int ff(int nd, int nb) {
	int S = 0;
	int ch = hd;
	for (int i = 0; i < nd; i ++) {
		int cak = max(ak - i*d, 0);
		int nak = max(ak - (i+1)*d, 0);
		if (nak >= ch) {
			S++;
			ch = hd;
			ch -= cak;
		}
		if (nak >= ch) return INF;
		S++;
		ch -= nak;
	}
	int cak = max(ak - nd*d, 0);
	for (int i = 0; i < nb; i ++) {
		if (cak >= ch) {
			S++;
			ch = hd;
			ch -= cak;
		}
		if (cak >= ch) return INF;
		S++;
		ch -= cak;
	}
	int atk = (hk-1)/(ad+b*nb)+1;
	for (int i = 0; i < atk; i ++) {
		if (i == atk-1) {
			S++;
			break;
		}
		if (cak >= ch) {
			S++;
			ch = hd;
			ch -= cak;
		}
		if (cak >= ch) return INF;
		S++;
		ch -= cak;
	}
	return S;
}

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> hd >> ad >> hk >> ak >> b >> d;
		int S = INF;
		for (int nd = 0; nd <= 100; nd ++) {
			for (int nb = 0; nb <= 100; nb ++)
				S = min(S, ff(nd, nb));
		}
		printf ("Case #%d: ", __);
		if (S == INF) puts ("IMPOSSIBLE");
		else printf ("%d\n", S);
	}
	return 0;
}