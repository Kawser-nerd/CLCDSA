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

int powM(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return powM(x * x % MOD, n / 2);
    }
    return powM(x, n-1) * x % MOD;
}

signed main(){
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> s(n);
    rep(i, n) cin >> s[i];
    sort(s.begin(), s.end());

    if(a == 1){
        rep(i, n){
            cout << s[i] << endl;
        }
        return 0;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    int max = s[n-1];
    rep(i, n){
        pq.push(s[i]);
    }

    while(pq.top() * a < max && b > 0){
        pq.push(pq.top() * a);
        pq.pop();
        b--;
    }

    rep(i, n){
        s[i] = pq.top();
        pq.pop();
    }

    int t = b % n;
    int i = t;
    rep(j, n){
        int k = b / n;
        if(i < t){
            k++;
        }
        cout << s[i] * powM(a, k) % MOD << endl;

        i = (i + 1) % n;
    }
    return 0;
}