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
    int n, l;
    cin >> n >> l;
    string s;
    getline(cin, s);

    vector<string> t;
    for(int i = 0; i <= l; i++){
        string s;
        getline(cin, s);
        t.push_back(s);
    }

    int pos;
    for(int i = 0; i < (int)t[l].size(); i++){
        if(t[l][i] == 'o'){
            pos = i;
        }
    }

    for(int i = l-1; i >= 0; i--){
        if(t[i][pos-1] == '-'){
            pos -= 2;
            continue;
        }
        if(t[i][pos+1] == '-'){
            pos += 2;
            continue;
        }
    }
    cout << pos / 2 + 1 << endl;

    return 0;
}