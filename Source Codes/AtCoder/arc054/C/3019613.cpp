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

    vector<vector<int>> s(n, vector<int>(n, 0));
    rep(i, n){
        rep(j, n){
            char c;
            cin >> c;
            if(c == '1'){
                s[i][j] = 1;
            }
        }
    }

    rep(i, n){
        if(s[i][i] == 0){
            int j = i + 1;
            for(; j < n; j++){
                if(s[j][i] != 0){
                    s[i].swap(s[j]);
                    break;
                }
            }
            if(j == n){
                cout << "Even" << endl;
                return 0;
            }
        }

        for(int j = i+1; j < n; j++){
            for(int k = i+1; k < n; k++){
                s[j][k] ^= s[j][i] * s[i][k];
            }
        }
    }

    int ans = 1;
    rep(i, n){
        ans *= s[i][i];
    }
    if(ans % 2 == 0){
        cout << "Even" << endl;
    }else{
        cout << "Odd" << endl;
    }

    return 0;
}