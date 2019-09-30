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

    int maxi = 0;
    rep(i, n){
        if(a[maxi] < a[i]){
            maxi = i;
        }
    }

    if(a[maxi] <= 0){
        cout << a[maxi] << endl;
        cout << n - 1 << endl;
        for(int i = n; i > maxi + 1; i--){
            cout << i << endl;
        }
        rep(i, maxi){
            cout << 1 << endl;
        }
        return 0;
    }

    int odd = 0, even = 0;
    rep(i, n){
        if(i % 2 == 0){
            if(a[i] > 0){
                even += a[i];
            }
        }else{
            if(a[i] > 0){
                odd += a[i];
            }
        }
    }

    vector<bool> need(n, false);
    for(int i = even > odd ? 0 : 1; i < n; i += 2){
        if(a[i] > 0){
            need[i] = true;
        }
    }

    vector<int> ans;
    int last = n-1;
    while(last >= 0 && not need[last]){
        ans.push_back(last+1);
        last--;
    }

    int head = 0;
    while(head < n && not need[head]){
        ans.push_back(1);
        head++;
    }

    int idx = 2;
    for(int i = head + 2; i <= last; i += 2){
        if(need[i]){
            ans.push_back(idx);
            continue;
        }
        ans.push_back(idx + 1);
    }

    cout << max(even, odd) << endl;
    cout << SZ(ans) << endl;
    for(int x : ans){
        cout << x << endl;
    }

    return 0;
}