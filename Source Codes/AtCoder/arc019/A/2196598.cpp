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

    rep(i, (int)s.length()){
        if(s[i] == 'O' || s[i] == 'D'){
            s[i] = '0';
        }
        if(s[i] == 'I'){
            s[i] = '1';
        }
        if(s[i] == 'Z'){
            s[i] = '2';
        }
        if(s[i] == 'S'){
            s[i] = '5';
        }
        if(s[i] == 'B'){
            s[i] = '8';
        }
    }
    cout << s << endl;
    return 0;
}