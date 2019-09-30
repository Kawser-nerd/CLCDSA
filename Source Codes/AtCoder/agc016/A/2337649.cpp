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

int solve(string s, char c){
    int n = s.size();
    bool ok = false;

    ok = true;
    for(int i = 0; i < n; i++){
        if(s[i] != c){
            ok = false;
        }
    }
    if(ok){
        return 0;
    }

    while(not ok){
        n--;
        for(int i = 0; i < n; i++){
            if(s[i+1] == c){
                s[i] = c;
            }
        }
        ok = true;
        for(int i = 0; i < n; i++){
            if(s[i] != c){
                ok = false;
            }
        }
    }
    return (int)s.size() - n;
}

signed main(){
    string s;
    cin >> s;

    int ans = INF;
    for(int i = 'a'; i <= 'z'; i++){
        int tmp = solve(s, i);
        if(tmp < ans){
            ans = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}