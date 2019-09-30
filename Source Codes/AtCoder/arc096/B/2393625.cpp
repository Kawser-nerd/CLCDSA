#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int N;
ll C;

ll x[100000];
ll v[100000];
ll rval[100001];
ll rd[100001];
ll lval[100001];
ll ld[100001];

void rot(ll val[], ll d[], bool left) {
    val[0] = 0;
    d[0] = 0;
    ll valsum = 0;
    for (int i = 0; i < N; ++i) {
        int ii = left ? N - i - 1 : i;
        ll dist = left ? C - x[ii] : x[ii];
        valsum += v[ii];
        if (val[i] < valsum - dist) {
            val[i + 1] = valsum - dist;
            d[i + 1] = dist;
        } else {
            val[i + 1] = val[i];
            d[i + 1] = d[i];
        }
    }
}

int main(){
    cin >> N >> C;

    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> v[i];
    }

    rot(rval, rd, false);
    rot(lval, ld, true);

    // cout << "right" << endl;
    // for (int i = 0; i <= N; ++ i) {
    //     cout << rval[i] << ", ";
    // }
    // cout << endl;

    // cout << "left "<< endl;
    // for (int i = 0; i <= N; ++ i) {
    //     cout << lval[i] << ", ";
    // }
    // cout << endl;

    ll ans = max(rval[N], lval[N]);

    for (int i = 1; i < N; ++i) {
        ll val = rval[i] + lval[N - i];
        val -= min(rd[i], ld[N - i]);
        ans = max(ans, val);
        // cout << i << "th -> right" << endl;
        // cout << rval[i] << "(" << rd[i] << ")" << endl;
        // cout << lval[i] << "(" << ld[i] << ")" << endl;
    }

    cout << ans << endl;
}