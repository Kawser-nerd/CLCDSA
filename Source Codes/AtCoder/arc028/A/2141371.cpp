#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
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
    int n, a, b;
    cin >> n >> a >> b;

    while(true){
        if(n - a <= 0){
            cout << "Ant" << endl;
            return 0;
        }
        n -= a;

        if(n - b <= 0){
            cout << "Bug" << endl;
            return 0;
        }
        n -= b;
    }

    return 0;
}