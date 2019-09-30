#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int infl = 1e9;

int Hd, Ad, Hk, Ak, B, D;

void read() {
    cin >> Hd >> Ad >> Hk >> Ak >> B >> D;
}

void kill() {
    int ans = infl;
    for (int b = 0; b <= 100; ++b)
        for (int d = 0; d <= 100; ++d) {
            int hd = Hd, hk = Hk, ad = Ad, ak = Ak;
            int cur = 0;
            bool ok = true;

            for (int t = 0; t < d; ++t) {
                int nk = max(0, ak - D);
                if (hd <= nk) {
                    ++cur;
                    hd = Hd;
                    hd = max(0, hd - ak);
                }

                ak = nk;
                hd = max(0, hd - ak);
                if (hd == 0)
                    ok = false;
                ++cur;
            }

            for (int t = 0; t < b; ++t) {
                int nd = ad + B;
                if (hd <= ak) {
                    ++cur;
                    hd = Hd;
                    hd = max(0, hd - ak);
                }

                ad = nd;
                hd = max(0, hd - ak);
                if (hd == 0)
                    ok = false;
                ++cur;
            }

            while (true) {
                if (hk <= ad) {
                    ++cur;
                    break;
                }
                if (hd <= ak) {
                    ++cur;
                    hd = Hd;
                    hd = max(0, hd - ak);
                }
                
                hd = max(0, hd - ak);
                hk = max(0, hk - ad);
                if (hd == 0)
                    ok = false;
                ++cur;
            }

            if (ok) {
                ans = min(ans, cur);
            }
        }

    if (ans == infl) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans << "\n";
    }
}


int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    read();
    kill();
    cerr << "Case #" << i << " done.\n";
  }
  return 0;
}
