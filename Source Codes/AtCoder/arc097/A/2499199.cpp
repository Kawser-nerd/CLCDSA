#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
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
    string s;
    int k;
    cin >> s >> k;

    set<string> v;
    rep(i, (int)s.length()){
        for(int j = 1; j <= 5; j++){
            v.insert(s.substr(i, j));
        }
    }
    auto it = v.begin();
    for(int i = 0; i < k-1; i++){
        it++;
    }
    cout << *it << endl;
    return 0;
}