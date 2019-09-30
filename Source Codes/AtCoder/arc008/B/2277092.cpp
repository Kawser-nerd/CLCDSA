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
    int n, m;
    cin >> n >> m;

    vector<int> name(100), kit(100);

    rep(i, n){
        char c;
        cin >> c;
        name[c]++;
    }
    rep(i, m){
        char c;
        cin >> c;
        kit[c]++;
    }

    int ans = 0;
    for(int i = 'A'; i <= 'Z'; i++){
        if(name[i] && !kit[i]){
            cout << -1 << endl;
            return 0;
        }
        if(!kit[i]){
            continue;
        }
        int tmp = name[i] / kit[i];
        tmp += name[i] % kit[i] == 0 ? 0 : 1;
        if(tmp > ans){
            ans = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}