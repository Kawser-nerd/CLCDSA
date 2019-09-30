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
    string s;
    cin >> n >> s;

    vector<int> east(n), west(n);
    for(int i = 0; i < n-1; i++){
        east[i+1] = east[i];
        if(s[i] == 'W'){
            east[i+1]++;
        }
    }
    for(int i = n-1; i >= 1; i--){
        west[i-1] = west[i];
        if(s[i] == 'E'){
            west[i-1]++;
        }
    }

    int ans = INF;
    rep(i, n){
        int tmp = east[i] + west[i];
        if(tmp < ans){
            ans = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}