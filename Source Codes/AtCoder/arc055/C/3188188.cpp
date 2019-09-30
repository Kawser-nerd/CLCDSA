#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

vector<int> z_algorithm(string s){
    vector<int> z(s.size());
    z[0] = s.size();

    int i = 1, j = 0;
    while(i < (int)s.size()){
        while(i + j < (int)s.size() && s[j] == s[i+j]){
            j++;
        }
        z[i] = j;

        if(j == 0){
            i++;
            continue;
        }

        int k = 1;
        while(i + k < (int)s.size() && k + z[k] < j){
            z[i+k] = z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return z;
}

signed main(){
    string s;
    cin >> s;
    int n = s.length();

    vector<int> za = z_algorithm(s);
    reverse(s.begin(), s.end());
    vector<int> zc = z_algorithm(s);
    reverse(zc.begin(), zc.end());

    int ans = 0;
    rep(i, n-2){
        if(i + 1 <= n - i - 1){
            continue;
        }

        int la = min(n - i - 2, za[i+1]);
        int lc = min(n - i - 2, zc[i]);

        ans += max(0LL, la + lc - n + i + 2);
    }
    cout << ans << endl;

    return 0;
}