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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> cnt(n);
    int maxi = 0;
    rep(i, n){
        cnt[a[i]]++;
        maxi = max(maxi, a[i]);
    }

    if(maxi % 2){
        for(int i = maxi; i > 0; i--){
            if(i <= maxi / 2){
                if(cnt[i] > 0){
                    cout << "Impossible" << endl;
                    return 0;
                }
                continue;
            }
            if(i == (maxi + 1) / 2){
                if(cnt[i] != 2){
                    cout << "Impossible" << endl;
                    return 0;
                }
                continue;
            }
            if(cnt[i] < 2){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }else{
        for(int i = maxi; i > 0; i--){
            if(i < maxi / 2){
                if(cnt[i] > 0){
                    cout << "Impossible" << endl;
                    return 0;
                }
                continue;
            }
            if(i == maxi / 2){
                if(cnt[i] != 1){
                    cout << "Impossible" << endl;
                    return 0;
                }
                continue;
            }
            if(cnt[i] < 2){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;

    return 0;
}