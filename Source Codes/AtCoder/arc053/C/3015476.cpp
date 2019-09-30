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

signed main(){
    int n;
    cin >> n;

    vector<P> v, u;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        if(a < b){
            v.emplace_back(a, b);
        }else{
            u.emplace_back(b, a);
        }
    }
    sort(v.begin(), v.end());
    sort(u.begin(), u.end(), greater<P>());

    int x = 0;
    int max = 0;
    rep(i, (int)v.size()){
        x += v[i].first;
        if(max < x){
            max = x;
        }
        x -= v[i].second;
    }
    rep(i, (int)u.size()){
        x += u[i].second;
        if(max < x){
            max = x;
        }
        x -= u[i].first;
    }
    cout << max << endl;

    return 0;
}