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

    int len = s.length();
    int hLen = len / 2;
    string front = s.substr(0, hLen);
    reverse(s.begin(), s.end());
    string back = s.substr(0, hLen);
    set<string> ss;
    int diff = 0;
    for(int i = 0; i < hLen; i++){
        if(front[i] == back[i]){
            continue;
        }
        diff++;
    }

    if(diff == 0){
        cout << 25 * hLen * 2 << endl;
        return 0;
    }

    if(diff == 1){
        if(len % 2 == 0){
            cout << 24 * 2 + 25 * (hLen * 2 - 2) << endl;
            return 0;
        }else{
            cout << 24 * 2 + 25 * (hLen * 2 - 1) << endl;
            return 0;
        }
    }

    cout << 25 * len << endl;
    return 0;
}