#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n;
    cin >> n;
    int sn = (n + 1) * n / 2;

    vector<int> a(n);
    int s = 0;
    rep(i, n){
        cin >> a[i];
        s += a[i];
    }

    if(s % sn != 0){
        cout << "NO" << endl;
        return 0;
    }
    int k = s / sn;

    rep(i, n){
        int d = a[(i + 1 + n) % n] - a[i] - k;
        if(abs(d) % n != 0 || d > 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}