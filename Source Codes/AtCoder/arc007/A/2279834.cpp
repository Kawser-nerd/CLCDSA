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
    string x, s;
    cin >> x >> s;

    rep(i, (int)s.size()){
        bool b = false;
        rep(j, (int)x.size()){
            if(s[i] == x[j]){
                b = true;
            }
        }
        if(b){
            continue;
        }
        cout << s[i];
    }
    cout << endl;

    return 0;
}