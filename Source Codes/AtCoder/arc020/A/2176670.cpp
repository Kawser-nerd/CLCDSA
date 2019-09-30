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

    a = abs(a);
    b = abs(b);
    if(a == b){
        cout << "Draw" << endl;
        return 0;
    }
    if(a > b){
        cout << "Bug" << endl;
        return 0;
    }
    cout << "Ant" << endl;

    return 0;
}