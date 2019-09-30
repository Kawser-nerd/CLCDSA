#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    string s, t;
    int q;
    cin >> s >> t >> q;

    vector<int> ss(s.length()+1);
    vector<int> tt(t.length()+1);
    rep(i, (int)s.length()){
        ss[i+1] = ss[i] + (s[i] == 'A' ? 1 : 2);
    }
    rep(i, (int)t.length()){
        tt[i+1] = tt[i] + (t[i] == 'A' ? 1 : 2);
    }

    rep(i, q){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x = ss[b] - ss[a-1];
        int y = tt[d] - tt[c-1];

        if(x % 3 == y % 3){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}