#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#include <set>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

void solve(){

}

template <typename T>
void warshallFloyd(T& d){
    for (int i = 0; i < d.size(); i++) d[i][i] = 0;

    for (int k = 0; k < d.size(); k++){
		for (int i = 0; i < d.size(); i++){
	    	for (int j = 0; j < d.size(); j++){
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
	    	}
		}
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<ll>> d(N, vector<ll> (N,LINF));
    vector<ll> one_d(N,LINF);

    for (int i = 0; i < M; i++) {
        int u,v,l;
        cin >> u >> v >> l;
        u--;
        v--;
        if (u != 0 && v != 0) {
            d[u][v] = d[v][u] = l;
        } else {
            one_d[v] = l;
        }
    }

    warshallFloyd(d);
    ll ans = LINF;
    for (int i = 1; i < N; i++) {
        for (int k = i+1; k < N; k++) {
            ans = min(ans, one_d[i] + d[i][k] + one_d[k]);
        }
    }

    if (ans >= LINF) ans = -1;
    cout << ans << endl;
    return 0;
}