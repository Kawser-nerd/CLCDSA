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

vector<int> prime(int n){
    vector<int> t;
    vector<bool> x(n+1, true);
    t.push_back(2);

    int i;
    for(i = 3; i * i <= n; i += 2){
        if(!x[i]){
            continue;
        }
        t.push_back(i);
        for(int j = i; j <= n; j += i){
            x[j] = false;
        }
    }
    for(; i <= n; i += 2){
        if(x[i]){
            t.push_back(i);
        }
    }
    return t;
}

signed main(){
    int a, b;
    cin >> a >> b;
    vector<int> p = prime(1e5);

    map<int, int> m;
    for(int i = b+1; i <= a; i++){
        int n = i;
        rep(j, (int)p.size()){
            while(n % p[j] == 0){
                if(m.find(p[j]) == m.end()){
                    m.emplace(p[j], 0);
                }
                m[p[j]]++;
                n /= p[j];
            }
        }
        if(n == 1){
            continue;
        }
        if(m.find(n) == m.end()){
            m.emplace(n, 0);
        }
        m[n]++;
    }

    int ans = 1;
    for(auto it = m.begin(); it != m.end(); it++){
        ans = ans * ((*it).second + 1) % MOD;
    }
    cout << ans << endl;

    return 0;
}