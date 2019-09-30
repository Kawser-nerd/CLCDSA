#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define rep(i,n) for(int i=0;i<(n);i++) 

ll n,m;

bool G[1000][1000];
bool Gc[1000][1000];

int color[1000];

P cou;
vector<P> p;

bool dfs(ll i) {
    bool ret = true;
    rep(j,n) {
        if(Gc[i][j]) {
            if(color[j] == 0) {
                color[j] = -1 * color[i];
                if(color[j] == 1)cou.first++;
                else cou.second++;
                ret &= dfs(j);
            }else {
                if(color[i] == color[j])return false;
            }
        }
    }
    return ret;
}

ll dp[1000][10000];

ll c2(ll n) {
    if(n < 2)return 0;
    return n * (n - 1) / 2;
}

int main() {
    cin >> n >> m;
    rep(i,m) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a][b] = G[b][a] = 1;
    }

    rep(i,n) {
        rep(j,n) {
            if(i == j)continue;

            Gc[i][j] = !G[i][j];
        }
    }

    rep(i,n) {
        if(color[i] == 0) {
            color[i] = 1;
            cou.first = 1;
            cou.second = 0;
            if(!dfs(i)) {
                cout << -1 << endl;
                return 0;
            }
            p.push_back(cou);

        }
    }

    dp[0][0] = 1;

    for(int i = 0;i < p.size();i++) {
        auto a = p[i];
        for(int j = 0;j <= n;j++) {
            dp[i + 1][j + a.first] |= dp[i][j];
            dp[i + 1][j + a.second] |= dp[i][j];
        }
    }

    ll ans = 1e18;

    for(int i = 0;i <= n;i++) {
        if(dp[p.size()][i]) {
            ans = min(ans,c2(i) + c2(n - i));
        }
    }

    cout << ans << endl;

    return 0;
}