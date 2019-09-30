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
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int n, k;

bool judge(int m, const vector<int>& a, const vector<int>& b){
    int lo, hi;

    int count = 0;
    rep(i, (int)a.size()){
        lo = -1;
        hi = n;
        while(hi - lo > 1){
            int mid = (hi + lo) / 2;

            if(a[i] * b[mid] <= m){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        count += lo + 1;
    }

    return k <= count;
}

signed main(){
    cin >> n >> k;

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int lo = 1;
    int hi = 1e18;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;

        if(judge(mid, a, b)){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    cout << hi << endl;

    return 0;
}