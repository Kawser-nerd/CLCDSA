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
    string st;
    cin >> st;

    bool s, e, n, w;
    s = e = n = w = false;
    for(char c: st){
        switch(c){
            case 'S': s = true;
                      break;
            case 'E': e = true;
                      break;
            case 'N': n = true;
                      break;
            case 'W': w = true;
                      break;
            default:  break;
        }
    }
    if(s == n && e == w){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;

    return 0;
}