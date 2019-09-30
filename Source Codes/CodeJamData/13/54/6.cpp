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

int N;
double res[1<<20];

double solve(int st)
{
    if (st == (1<<N) - 1) {
        return 0;
    }
    if (res[st] > -0.5) {
        return res[st];
    }

    double s = 0.0;
    for (int i = 0; i < N; ++i) {
        int w = 0, nst = st;
        for (int j = 0; j < N; ++j) {
            int k = (i-j+N) % N;
            if ((st & (1<<k)) == 0) {
                nst |= 1<<k;
                break;
            }
            ++w;
        }
        s += (solve(nst) + (N - w)) / N;
    }

    return res[st] = s;
}

int main()
{
    int T;
    cin >> T;
    cout << setprecision(20);
    
    for (int CN = 1; CN <= T; ++CN) {
        string S;
        cin >> S;

        int st = 0;
        N = S.size();
        for (int i = 0; i < S.size(); ++i) {
            st = st*2 + (S[i]=='X' ? 1 : 0);
        }

        for (int i = 0; i < 1<<N; ++i) {
            res[i] = -1.0;
        }

        cout << "Case #" << CN << ": " << solve(st) << endl;    
    }

    return 0;
}
