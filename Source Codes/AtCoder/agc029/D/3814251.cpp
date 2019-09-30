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

    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<int>> d(w+1, vector<int>{0, h+1});
    rep(i, n){
        int x, y;
        cin >> x >> y;
        d[y].push_back(x);
    }

    int ans = h;
    int head = 0;
    int tail = h;
    for(int i = 1; i <= w; i++){
        sort(ALL(d[i]));
        head++;

        int begin = head;
        rep(j, SZ(d[i])){
            if(begin > d[i][j]){
                continue;
            }

            if(begin < d[i][j]){
                break;
            }
            begin++;
        }
        auto end = upper_bound(ALL(d[i]), begin);

        int diff = tail - begin;
        if(diff <= 0){
            break;
        }

        ans = min(ans, *end- 1);
        head = max(head, begin);
        tail = *end - 1;
    }
    cout << ans << endl;

    return 0;
}