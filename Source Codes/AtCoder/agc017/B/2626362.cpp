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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    int diff = b - a;
    for(int i = 0; i <= n-1; i++){
        int min = c * i - d * (n - 1 - i);
        int max = d * i - c * (n - 1 - i);

        if(min <= diff && diff <= max){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}