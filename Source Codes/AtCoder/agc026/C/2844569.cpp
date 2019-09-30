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
    int n;
    string st;
    cin >> n >> st;

    map<pair<int, string>, int> m;
    rep(s, (1 << n)){
        string a = "";
        string b = "";
        int len = 0;
        rep(i, n){
            if((s >> i) % 2 == 1){
                a.push_back(st[i]);
                len++;
            }else{
                b.push_back(st[i]);
            }
        }
        reverse(b.begin(), b.end());
        a.append(b);

        pair<int, string> p = make_pair(len, a);
        if(m.find(p) == m.end()){
            m.emplace(p, 0);
        }
        m[p]++;
    }

    int ans = 0;
    rep(s, (1 << n)){
        string a = "";
        string b = "";
        int len = 0;
        rep(i, n){
            if((s >> i) % 2 == 0){
                a.push_back(st[n+i]);
                len++;
            }else{
                b.push_back(st[n+i]);
            }
        }
        reverse(a.begin(), a.end());
        a.append(b);

        pair<int, string> p = make_pair(len, a);
        if(m.find(p) != m.end()){
            ans += m[p];
        }
    }
    cout << ans << endl;

    return 0;
}