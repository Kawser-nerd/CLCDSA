#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;

        a[p] = 30000 * p;
        b[p] = 30000 * (n - p) + i;
    }

    for(int i = 1; i < n; i++){
        cout << a[i] << " ";
    }
    cout << a[n] << endl;
    for(int i = 1; i < n; i++){
        cout << b[i] << " ";
    }
    cout << b[n] << endl;

    return 0;
}