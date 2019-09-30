#include <iostream>
#include <string>
#include <vector>

using namespace std;


const int mod = 10009;

int n, k, v[100][4], d[11][16];

int get_d (int cnt, int msk) {
	int & my = d[cnt][msk];
	if (my != -1)  return my;

	if (msk == 0) {
		my = 1;
		for (int i=0; i<cnt; ++i) {
			my *= n;
			my %= mod;
		}
		return my;
	}
	if (cnt == 0)  return my = 0;

	my = 0;
	if (cnt)
		for (int pos=0; pos<n; ++pos)
			for (int msk2=0; msk2<=msk; ++msk2)
				if ((msk & msk2) == msk2) {
					int mult = 1;
					for (int i=0; i<4; ++i)
						if ((msk & (1<<i)) && !(msk2 & (1<<i))) {
							mult *= v[pos][i];
							mult %= mod;
						}
					my += get_d (cnt-1, msk2) * mult;
					my %= mod;
				}

	return my;
}

int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int ts;
	cin >> ts;
	for (int tt=0; tt<ts; ++tt) {

		string p;
		cin >> p >> k >> n;
		vector<string> a (n);
		char s[100];
		gets (s);
		for (int i=0; i<n; ++i) {
			gets (s);
			a[i] = s;
		}

		p += '+';
		printf ("Case #%d:", tt+1);
		for (int kk=1; kk<=k; ++kk) {
			int ans = 0;
			for (size_t i=0; i<p.length(); ++i) {
				string w;
				while (p[i] != '+')
					w += p[i++];

				memset (v, 0, sizeof v);
				for (int j=0; j<n; ++j)
					for (size_t l=0; l<a[j].length(); ++l)
						for (size_t m=0; m<w.length(); ++m)
							if (a[j][l] == w[m])
								++v[j][m];
				memset (d, -1, sizeof d);
				ans += get_d (kk, (1<<w.length())-1);
			}
			printf (" %d", ans % mod);
		}
		puts("");

	}

}

