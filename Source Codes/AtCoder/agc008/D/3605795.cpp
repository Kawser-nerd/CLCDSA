#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> ans(n*n+1, 0);
    priority_queue<P, vector<P>, greater<P>> pq;
    queue<int> q;

    rep(i, n){
        int x;
        cin >> x;

        ans[x] = i+1;
        rep(j, i){
            pq.emplace(x - 1, i + 1);
        }
    }

    for(int i = 1; i <= n * n; i++){

        if(ans[i] != 0){
            rep(j, n - ans[i]){
                q.push(ans[i]);
            }

            continue;
        }

        if(not pq.empty() && pq.top().first < i){
            cout << "No" << endl;
            return 0;
        }

        if(not pq.empty()){
            ans[i] = pq.top().second;
            pq.pop();
            continue;
        }

        if(not q.empty()){
            ans[i] = q.front();
            q.pop();
            continue;
        }

        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for(int i = 1; i < n * n; i++){
        cout << ans[i] << " ";
    }
    cout << ans[n*n] << endl;

    return 0;
}