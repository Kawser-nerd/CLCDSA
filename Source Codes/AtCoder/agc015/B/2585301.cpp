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
    int n = (int)s.length();

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'U'){
            ans += n - i - 1;
            ans += i * 2;
        }else{
            ans += (n - i - 1) * 2;
            ans += i;
        }
    }
    cout << ans << endl;

    return 0;
}