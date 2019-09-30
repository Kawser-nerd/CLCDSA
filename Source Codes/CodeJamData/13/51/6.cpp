#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <iomanip>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

Int B, N;

double getExpected(Int X[], Int Y[], Int already_used)
{
    Int rem = B - already_used;
    double ret = 0.0;
    Int mY[40];
    memcpy(mY, Y, sizeof(mY));

    int kfrom = 36;
    for (int i = 0; i < 36; ++i) {
        if (Y[i] < Y[i + 1]) {
            kfrom = i;
            break;
        }
    }

    for (int k = kfrom; k >= 0; --k) {
        Int sel = *min_element(Y, Y + 37);
        Int res = 0;
        int cnt = 0;
        for (int i = 0; i <= 36; ++i) {
            if (Y[i] == sel) {
                res += (Y[i] - X[i]) * 36;
                ++cnt;
            }
        }
        chmax(ret, double(res) / cnt - already_used);
        if (rem == 0) break;
        Y[k]++;
        already_used++;
        rem--;
    }

    memcpy(Y, mY, sizeof(mY));
    return ret;
}

int main()
{
    int T;
    cin >> T;

    cout << setprecision(20);

    for (int CN = 1; CN <= T; ++CN) {
        cin >> B >> N;

        Int X[40];
        for (int i = 0; i < N; ++i) {
            cin >> X[i];
        }
        for (int i = N; i <= 36; ++i) {
            X[i] = 0;
        }
        sort(X, X + 37);

        double res = 0.0;
        for (int i = 0; i <= 36; ) {
            int j = i;
            while (j <= 36 && X[i] == X[j]) ++j;

            Int next = j == 37 ? INFLL : X[j];
            Int remB = B;
            Int Y[40];
            memcpy(Y, X, sizeof(X));
            for (int k = 0; k < j; ++k) {
                remB -= (X[i] - X[k]);
                Y[k] = X[i];
            }
            if (remB < 0) {
                break;
            }

            chmax(res, getExpected(X, Y, B - remB));
            if (j != 37 && ((next - 1) - X[i]) * j <= remB) {
                Int used = B - remB;
                for (int k = 0; k < j; ++k) {
                    used += (next - 1) - Y[k];
                    Y[k] = next - 1;
                }
                chmax(res, getExpected(X, Y, used));
            }
            if (j != 37 && ((next - 2) - X[i]) * j <= remB && next - 2 >= X[i]) {
                Int used = B - remB;
                for (int k = 0; k < j; ++k) {
                    used += (next - 2) - X[i];
                    Y[k] = next - 2;
                }
                chmax(res, getExpected(X, Y, used));
            }
            if (remB / j + X[i] < next) {
                Int used = B - remB, to = remB / j;
                for (int k = 0; k < j; ++k) {
                    used += to;
                    Y[k] = X[i] + to;
                }
                chmax(res, getExpected(X, Y, used));
            }
            if (remB / j - 1 + X[i] < next && remB / j - 1 >= 0) {
                Int used = B - remB, to = remB / j - 1;
                for (int k = 0; k < j; ++k) {
                    used += to;
                    Y[k] = X[i] + to;
                }
                chmax(res, getExpected(X, Y, used));
            }

            i = j;
        }

        cout << "Case #" << CN << ": " << res << endl;
    }

    return 0;
}
