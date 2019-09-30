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

int solve(const string& s, string l, string r){
    vector<int> len((int)s.size()+1);

    len[0] = 0;
    len[1] = 1;

    for(int i = 2; i <= (int)s.size(); i++){
        if(s[i-2] == l[0] && s[i-1] == l[1] || s[i-2] == r[0] && s[i-1] == r[1]){
            len[i] = min(len[i-2] + 1, len[i-1] + 1);
        }else{
            len[i] = len[i-1] + 1;
        }
    }

    return len[(int)s.size()];
}

signed main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<string> cmd = {"AA", "AB", "AX", "AY", "BA", "BB", "BX", "BY",
        "XA", "XB", "XX", "XY", "YA", "YB", "YX", "YY"};

    int ans = INF;
    rep(i, (int)cmd.size()){
        for(int j = i+1; j < (int)cmd.size(); j++){
            int tmp = solve(s, cmd[i], cmd[j]);
            if(tmp < ans){
                ans = tmp;
            }
        }
    }
    cout << ans << endl;

    return 0;
} ./Main.cpp:28:27: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if(s[i-2] == l[0] && s[i-1] == l[1] || s[i-2] == r[0] && s[i-1] == r[1]){
           ~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~ ~~
./Main.cpp:28:27: note: place parentheses around the '&&' expression to silence this warning
        if(s[i-2] == l[0] && s[i-1] == l[1] || s[i-2] == r[0] && s[i-1] == r[1]){
                          ^
           (                               )
./Main.cpp:28:63: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if(s[i-2] == l[0] && s[i-1] == l[1] || s[i-2] == r[0] && s[i-1] == r[1]){
                                            ~~ ~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~
./Main.cpp:28:63: note: place parentheses around the '&&' expression to silence this warning
        if(s[i-2] == l[0] && s[i-1] == l[1] || s[i-2] == r[0] && s[i-1] == r[1]){
                                                              ^
                                               (                               )
2 warnings generated.