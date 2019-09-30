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
    cin >> n;
    vector<int> a(1);
    cin >> a[0];
    rep(i, n-1){
        int x;
        cin >> x;
        if(a[a.size()-1] == x){
            continue;
        }
        a.push_back(x);
    }


    int ans = 1;
    for(int i = 1; i < (int)a.size()-1; i++){
        int x = a[i-1] - a[i];
        int y = a[i] - a[i+1];

        if(x > 0 && y < 0 || x < 0 && y > 0){
            ans++;
            i++;
        }
    }

    cout << ans << endl;

    return 0;
} ./Main.cpp:46:18: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if(x > 0 && y < 0 || x < 0 && y > 0){
           ~~~~~~^~~~~~~~ ~~
./Main.cpp:46:18: note: place parentheses around the '&&' expression to silence this warning
        if(x > 0 && y < 0 || x < 0 && y > 0){
                 ^
           (             )
./Main.cpp:46:36: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if(x > 0 && y < 0 || x < 0 && y > 0){
                          ~~ ~~~~~~^~~~~~~~
./Main.cpp:46:36: note: place parentheses around the '&&' expression to silence this warning
        if(x > 0 && y < 0 || x < 0 && y > 0){
                                   ^
                             (             )
2 warnings generated.