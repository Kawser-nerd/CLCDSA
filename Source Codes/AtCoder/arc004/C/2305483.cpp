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
    string s;
    cin >> s;

    int x, y;
    x = y = 0;
    int i = 0;
    while(s[i] != '/'){
        x *= 10;
        x += s[i++] - '0';
    }
    for(i++; i < (int)s.size(); i++){
        y *= 10;
        y += s[i] - '0';
    }

    vector<P> ans;
    for(int i = max(x / y * 2 - 5, 1LL); i <= x / y * 2 + 5; i++){
        int a = i * ((i+1) * y - 2 * x);
        int b = 2 * y;

        if(a % b != 0){
            continue;
        }

        int m = a / b;
        if(1 <= m && m <= i){
            ans.push_back(make_pair(i, m));
        }
    }

    if(ans.size() == 0){
        cout << "Impossible" << endl;
        return 0;
    }

    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}