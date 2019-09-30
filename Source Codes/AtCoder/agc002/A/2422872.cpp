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
    int a, b;
    cin >> a >> b;

    if(a > 0){
        cout << "Positive" << endl;
        return 0;
    }

    if(a <= 0 && b >= 0){
        cout << "Zero" << endl;
        return 0;
    }

    if((b - a) % 2 == 0){
        cout << "Negative" << endl;
        return 0;
    }
    cout << "Positive" << endl;

    return 0;
}