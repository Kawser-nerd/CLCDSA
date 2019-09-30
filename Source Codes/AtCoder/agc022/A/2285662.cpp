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

    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }

    vector<bool> a(150, false);
    rep(i, (int)s.size()){
        a[s[i]] = true;
    }

    int c = -1;
    for(int i = 'a'; i <= 'z'; i++){
        if(!a[i]){
            c = i;
            break;
        }
    }

    if(c != -1){
        cout << s << (char)c << endl;
        return 0;
    }

    for(int i = (int)s.size()-1; i >= 0; i--){
        a[s[i]] = false;
        string t = s.substr(0, i);
        char cc = '\0';
        for(int j = 'a'; j <= 'z'; j++){
            if(a[j]){
                continue;
            }
            cc = j;
            t.push_back(cc);
            if(s.compare(t) < 0){
                cout << t << endl;
                return 0;
            }
            t.pop_back();
        }
    }

    return 0;
}