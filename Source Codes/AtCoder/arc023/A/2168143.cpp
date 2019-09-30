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

int day(int y, int m, int d){
    return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;
}

signed main(){
    int y, m, d;
    cin >> y >> m >> d;
    if(m <= 2){
        m += 12;
        y -= 1;
    }

    cout << day(2014, 5, 17) - day(y, m, d) << endl;

    return 0;
}