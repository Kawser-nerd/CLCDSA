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

int h(const vector<int>& a){
    int x = 0;
    rep(i, 26){
        x += a[i] * pow(3, i);
    }
    return x;
}

signed main(){
    int n, k;
    string s;
    cin >> n >> k >> s;

    map<int, int> ss;
    vector<int> alpha(26);
    rep(i, k){
        alpha[s[i]-'a']++;
    }
    ss.emplace(h(alpha), k-1);
    for(int i = k; i < n; i++){
        alpha[s[i-k]-'a']--;
        alpha[s[i]-'a']++;

        int x = h(alpha);
        if(ss.find(x) != ss.end() && ss[x] + k <= i){
            cout << "YES" << endl;
            return 0;
        }
        ss.emplace(x, i);
    }
    cout << "NO" << endl;

    return 0;
}