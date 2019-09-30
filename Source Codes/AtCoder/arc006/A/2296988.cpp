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
    vector<int> e(10), l(10);

    rep(i, 6){
        int n;
        cin >> n;
        e[n] = 1;
    }
    int b;
    cin >> b;
    e[b] = 2;

    rep(i, 6){
        int n;
        cin >> n;
        l[n] = 1;
    }

    int hit = 0;
    bool bonus = false;
    rep(i, 10){
        if(e[i] == l[i] && l[i] == 1){
            hit++;
        }
        if(e[i] == 2 && l[i] == 1){
            bonus = true;
        }
    }

    switch(hit){
        case 6:
            cout << 1 << endl;
            break;
        case 5:
            if(bonus){
                cout << 2 << endl;
                break;
            }
            cout << 3 << endl;
            break;
        case 4:
            cout << 4 << endl;
            break;
        case 3:
            cout << 5 << endl;
            break;
        default:
            cout << 0 << endl;
            break;
    }
    return 0;
}