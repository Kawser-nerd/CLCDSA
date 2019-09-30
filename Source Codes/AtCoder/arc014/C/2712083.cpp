#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int r = 0;
    int g = 0;
    int b = 0;

    rep(i, (int)s.length()){
        if(s[i] == 'R') r++;
        if(s[i] == 'G') g++;
        if(s[i] == 'B') b++;
    }
    cout << (r % 2) + (g % 2) + (b % 2) << endl;

    return 0;
}