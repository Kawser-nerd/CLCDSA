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
#include <functional>
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

    rep(i, n){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if(a < b || b > d){
            cout << "No" << endl;
            continue;
        }
        if(b <= c){
            cout << "Yes" << endl;
            continue;
        }

        a %= b;
        int g = gcd(b, d);
        a = b - g + a % g;
        if(a > c){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }

    return 0;
}