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
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    rep(i, h) cin >> a[i];

    if(a[0][0] != '#'){
        cout << "Impossible" << endl;
        return 0;
    }

    vector<vector<bool>> mark(h, vector<bool>(w, false));
    int x = 0;
    int y = 0;
    mark[x][y] = true;
    while(x < h && y < w){
        if(x + 1 < h && a[x+1][y] == '#'){
            mark[x+1][y] = true;
            x++;
            continue;
        }
        if(y + 1 < w && a[x][y+1] == '#'){
            mark[x][y+1] = true;
            y++;
            continue;
        }
        if(x != h-1 && y != w-1){
            cout << "Impossible" << endl;
            return 0;
        }
        break;
    }

    rep(i, h){
        rep(j, w){
            if(not mark[i][j] && a[i][j] == '#'){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;

    return 0;
}