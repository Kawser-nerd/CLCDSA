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

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

signed main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int max = *max_element(a.begin(), a.end());
    int g = a[0];
    for(int i = 1; i < (int)a.size(); i++){
        g = gcd(g, a[i]);
    }

    if(k <= max && k % g == 0){
        cout << "POSSIBLE" << endl;
        return 0;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}