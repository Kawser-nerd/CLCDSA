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
    sort(ALL(a));

    if(a[n-1] - a[0] > 1){
        cout << "No" << endl;
        return 0;
    }

    if(a[0] == n - 1 && a[0] == a[n-1]){
        cout << "Yes" << endl;
        return 0;
    }

    int m = a[n-1];
    int cnt = 0;
    rep(i, n){
        if(a[i] != m){
            cnt++;
        }
    }

    int mini = 0;
    if(n / m == 1){
        mini = m - n % m;
    }
    int maxi = m - 1;

    if(mini <= cnt && cnt <= maxi){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}