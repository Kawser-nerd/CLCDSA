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
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    vector<int> len(n+1);
    rep(i, n){
        len[p[i]] = len[p[i]-1]+1;
    }

    int max = *max_element(len.begin(), len.end());
    cout << n - max << endl;

    return 0;
}