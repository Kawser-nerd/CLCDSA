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

    map<char, int> m;
    for(char c: s){
        if(m.find(c) == m.end()){
            m[c] = 1;
            continue;
        }
        m[c]++;
    }

    int ans = s.length();
    ans = ans * (ans - 1) / 2 + 1;
    for(int i = 'a'; i <= 'z'; i++){
        int x = m[(char)i];
        ans -= x * (x - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}