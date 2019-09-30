#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>


using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

int main(void)
{
    cin.sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    vector<int> As(N);
    ll sum = 0;
    REP(n,N) {
        cin >> As[n];
        if (As[n] > 0) sum += As[n];
    }

    ll ans = 0;
    ll ans_w = sum;
    ll ans_b = sum;
    REP(i, N-K+1) {
        if (i == 0) {
            REP(j, K) {
                if (As[j] > 0) ans_w -= As[j];
                if (As[j] < 0) ans_b += As[j];
            }
        }
        else {
            if (As[i-1] > 0) ans_w += As[i-1];
            if (As[i-1] < 0) ans_b -= As[i-1];
            if (As[i+K-1] > 0) ans_w -= As[i+K-1];
            if (As[i+K-1] < 0) ans_b += As[i+K-1];
        }

        ans = max(ans, max(ans_w, ans_b));
    }
    cout << ans << endl;

    return 0;
}