#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

long long pow_10[18];
int dig[20];

int main () {
//  ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

    int tc;
    cin >> tc;

    pow_10[0] = 1;
    for (int i = 1; i < 18; ++i) {
        pow_10[i] = 10 * pow_10[i - 1];
    }

    for (int ti = 0; ti < tc; ++ti) {
        long long n;
        cin >> n;

        long long ans = 0;
        while (n > 0) {
            if (n % 10 == 0) {
                n--;
                ans++;
                continue;
            }

            int num_dig = 0;
            while (pow_10[num_dig] <= n) {
                num_dig++;
            }

            if (num_dig == 1) {
                ans += n;
                n = 0;
                continue;
            }

            for (int i = 0; i < num_dig; ++i) {
                dig[i] = (n / pow_10[i]) % 10;
            }
            bool rev = false;

            for (int i = 0; i < num_dig; ++i) {
                if (i != 0 && i != num_dig - 1) {
                    if (num_dig - 1 - i < i) {
                        if (dig[i] > 0) {
                            rev = true;
                        }
                        ans += pow_10[num_dig - 1 - i] * dig[i];
                        n -= dig[i] * pow_10[i];
                    } else {
                        ans += pow_10[i] * dig[i];
                        n -= dig[i] * pow_10[i];
                    }
                } else if (i == 0) {
                    ans += dig[0] - 1;
                    n -= dig[0] - 1;
                } else {
                    if (dig[i] > 1) {
                        rev = true;
                    }
                    ans += dig[i] - 1;
                    n -= (dig[i] - 1) * pow_10[i];
                }
            }

            if (rev) {
                ans++;
            }

            n -= 2;
            ans += 2;
        }

        cout << "Case #" << ti + 1 << ": " << ans << "\n";
    }

	return 0;
}
