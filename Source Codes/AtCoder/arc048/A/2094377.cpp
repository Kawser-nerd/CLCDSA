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
    int a, b;
    cin >> a >> b;

    if(a < 0 && b > 0){
        cout << b - a - 1 << endl;
        return 0;
    }
    cout << b - a << endl;

    return 0;
}