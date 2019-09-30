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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int w, h, q;
    cin >> w >> h >> q;

    vector<vector<int>> vt(100001, vector<int>());
    vector<vector<int>> ht(100001, vector<int>());
    rep(i, q){
        int t, d, x;
        cin >> t >> d >> x;
        if(d == 0){
            ht[t].push_back(x);
        }else{
            vt[t].push_back(x);
        }
    }

    vector<int> ve(h+1, 0);
    vector<int> ho(w+1, 0);
    rep(i, 100001){
        if(vt[i].size() == 0){
            continue;
        }

        sort(vt[i].begin(), vt[i].end());
        for(int x: vt[i]){
            if(x >= h){
                continue;
            }
            ve[x+1] = min(ve[x+1], ve[x] + 1);
        }
        reverse(vt[i].begin(), vt[i].end());
        for(int x: vt[i]){
            if(x <= 1){
                continue;
            }
            ve[x-1] = min(ve[x-1], ve[x] + 1);
        }
        for(int x: vt[i]){
            ve[x] = INF;
        }
    }

    rep(i, 100001){
        if(ht[i].size() == 0){
            continue;
        }

        sort(ht[i].begin(), ht[i].end());
        for(int x: ht[i]){
            if(x >= w){
                continue;
            }
            ho[x+1] = min(ho[x+1], ho[x] + 1);
        }
        reverse(ht[i].begin(), ht[i].end());
        for(int x: ht[i]){
            if(x <= 1){
                continue;
            }
            ho[x-1] = min(ho[x-1], ho[x] + 1);
        }
        for(int x: ht[i]){
            ho[x] = INF;
        }
    }

    int xx = *min_element(ho.begin()+1, ho.end());
    int yy = *min_element(ve.begin()+1, ve.end());

    if(xx == INF || yy == INF){
        cout << -1 << endl;
        return 0;
    }

    cout << xx + yy << endl;

    return 0;
}