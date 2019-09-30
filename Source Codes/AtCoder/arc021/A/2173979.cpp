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
    vector<vector<int>> a(4, vector<int>(4));
    rep(i, 4){
        rep(j, 4){
            cin >> a[i][j];
        }
    }

    rep(i, 3){
        if(a[i][0] == a[i+1][0] || a[i][1] == a[i+1][1] || a[i][2] == a[i+1][2] || a[i][3] == a[i+1][3]){
            cout << "CONTINUE" << endl;
            return 0;
        }

        if(a[0][i] == a[0][i+1] || a[1][i] == a[1][i+1] || a[2][i] == a[2][i+1] || a[3][i] == a[3][i+1]){
            cout << "CONTINUE" << endl;
            return 0;
        }
    }
    cout << "GAMEOVER" << endl;

    return 0;
}