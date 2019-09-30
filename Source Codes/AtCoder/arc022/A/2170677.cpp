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
    string s;
    cin >> s;

    bool i, c, t;
    i = c = t = false;
    int j = 0;
    for(; j < s.length(); j++){
        if(s[j] == 'i' || s[j] == 'I'){
            i = true;
            break;
        }
    }
    for(; j < s.length(); j++){
        if(s[j] == 'c' || s[j] == 'C'){
            c = true;
            break;
        }
    }
    for(; j < s.length(); j++){
        if(s[j] == 't' || s[j] == 'T'){
            t = true;
            break;
        }
    }
    if(i && c && t){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;

    return 0;
}