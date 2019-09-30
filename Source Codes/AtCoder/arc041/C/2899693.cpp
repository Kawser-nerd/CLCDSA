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
    int n, l;
    cin >> n >> l;
    vector<int> x(n);
    vector<char> d(n);
    rep(i, n){
        cin >> x[i] >> d[i];
    }

    vector<P> range;
    int start = -1;
    rep(i, n){
        if(start == -1 && d[i] == 'R'){
            start = i;
        }

        if(d[i] == 'L' && (i == n-1 || d[i+1] == 'R')){
            range.emplace_back(start, i);
            start = -1;
        }

        if(i == n-1 && d[i] == 'R'){
            range.emplace_back(start, n);
        }
    }

    int ans = 0;
    rep(i, (int)range.size()){
        vector<int> L, R;
        for(int j = range[i].first; j <= range[i].second; j++){
            if(j == -1 || j == n){
                continue;
            }
            if(d[j] == 'L'){
                L.push_back(x[j]);
                continue;
            }
            R.push_back(x[j]);
        }

        int Rn = R.size();
        int Ln = L.size();
        if(Rn == 0){
            rep(j, Ln){
                ans += L[j] - (j + 1);
            }
            continue;
        }

        if(Ln == 0){
            rep(j, Rn){
                ans += l - R[j] - (Rn - j - 1);
            }
            continue;
        }

        if(Rn < Ln){
            int limit = R[Rn-1];
            rep(j, Rn-1){
                ans += limit - R[j] - (Rn - j - 1);
            }
            rep(j, Ln){
                ans += L[j] - limit - (j + 1);
            }
        }else{
            int limit = L[0];
            rep(j, Rn){
                ans += limit - R[j] - (Rn - j);
            }
            rep(j, Ln-1){
                ans += L[j+1] - limit - (j + 1);
            }
        }
    }
    cout << ans << endl;

    return 0;
}