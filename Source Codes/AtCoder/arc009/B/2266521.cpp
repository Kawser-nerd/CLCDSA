#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
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
    vector<int> to(10), from(10);
    rep(i, 10){
        cin >> to[i];
        from[to[i]] = i;
    }

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n){
        string s;
        cin >> s;

        rep(j, (int)s.size()){
            s[j] = from[s[j] - '0'] + '0';
        }
        a[i] = stoi(s);
    }

    sort(a.begin(), a.end());

    rep(i, n){
        string s = to_string(a[i]);

        rep(j, (int)s.size()){
            s[j] = to[s[j] - '0'] + '0';
        }
        cout << s << endl;
    }

    return 0;
}