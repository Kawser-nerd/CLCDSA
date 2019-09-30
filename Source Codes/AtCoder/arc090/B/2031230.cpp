#include <iostream>
#include <vector>

using namespace std;
using P = pair<int, int>;
using ll = long long;

const int NMAX = 100000;
const long long DMMAX = 200000 * 10000;
const long long UNKNOWN = DMMAX * 2;

vector<ll> pos;
vector<vector<P>> conds;
int N, M;

ll minx = 0;
ll maxx = 0;

int dfs(int i) {
    //cout << "on node " << i << endl;
    ll x = pos[i];
    for (P p : conds[i]) {
        int j = p.first;
        int d = p.second;
        //cout << "cond " << i << " -> " << j << " d = " << d << endl;

        if (pos[j] == UNKNOWN) {
            pos[j] = x + d;

            if (dfs(j) == -1) {
                return -1;
            }
        } else if (pos[j] != x + d){
            return -1;
        }
    }
    return 0;
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        pos.push_back(UNKNOWN);
        conds.push_back(vector<P>());
    }

    for (int i = 0; i < M; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;
        if (l > r) {
            int tmp = l; l = r; r = tmp;
            d *= -1;
        }

        conds[l].push_back(make_pair(r, d));
        conds[r].push_back(make_pair(l, -d));
    }
    bool ok = true;
    for (int i = 0; i < N; ++i) {
        if (pos[i] == UNKNOWN) {
            pos[i] = 0;

            if (dfs(i) == -1) {
                ok = false;
            }
        }
        if (!ok) break;
    }

    // for (ll pi : pos) {
        // cout << pi << " ";
    // }
    // cout << endl;
    cout << (ok ? "Yes" : "No") << endl;
}