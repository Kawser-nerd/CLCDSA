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

int powM(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return powM(x * x % MOD, n / 2);
    }
    return powM(x, n-1) * x % MOD;
}

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

signed main(){
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    sort(l.begin(), l.end());

    int min = l[0];
    if(n == 1){
        cout << powM(2, min) << endl;
        return 0;
    }

    int g = l[n-1] - min;
    for(int i = 1; i < n - 1; i++){
        if(l[i] - min == 0){
            continue;
        }
        g = gcd(g, l[i]-min);
    }
    g = (g + 1) / 2;

    cout << powM(2, min + g) << endl;

    return 0;
}