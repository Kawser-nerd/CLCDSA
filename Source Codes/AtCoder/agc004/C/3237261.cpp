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

    vector<string> input(h);
    rep(i, h) cin >> input[i];

    vector<string> r, b;
    r = input;
    b = input;
    rep(i, h){
        for(int j = 1; j < w - 1; j++){
            if(i % 2 == 0){
                r[i][j] = '#';
            }else{
                b[i][j] = '#';
            }
        }
    }

    rep(i, h - 1){
        r[i][w-1] = '#';
        b[i+1][0] = '#';
    }

    rep(i, h){
        cout << r[i] << endl;
    }
    cout << endl;
    rep(i, h){
        cout << b[i] << endl;
    }

    return 0;
}