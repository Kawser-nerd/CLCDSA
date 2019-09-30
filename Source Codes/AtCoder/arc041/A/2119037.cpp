#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

signed main(){
    int x, y, k;
    cin >> x >> y >> k;

    if(y > k){
        cout << x + k << endl;
        return 0;
    }
    cout << x + y - (k - y) << endl;

    return 0;
}