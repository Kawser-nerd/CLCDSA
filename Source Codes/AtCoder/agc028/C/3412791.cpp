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

    vector<tuple<int, int, int>> x(n * 2);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        x[i*2] = make_tuple(a, i, 0);
        x[i*2+1] = make_tuple(b, i, 1);
    }
    sort(x.begin(), x.end());

    bool a, b;
    a = b = false;
    int ans1 = 0;
    rep(i, n){
        int type = get<2>(x[i]);
        if(type){
            b = true;
        }else{
            a = true;
        }
        ans1 += get<0>(x[i]);
    }

    if(a && b){
        ans1 = INF;
    }

    int ans2 = 0;
    bool dup = false;
    set<int> s;
    rep(i, n-1){
        int id = get<1>(x[i]);
        if(s.find(id) != s.end()){
            dup = true;
        }
        s.insert(id);
        ans2 += get<0>(x[i]);
    }

    if(dup || s.find(get<1>(x[n-1])) != s.end()){
        ans2 += get<0>(x[n-1]);
        cout << min(ans1, ans2) << endl;
        return 0;
    }

    if(dup || s.find(get<1>(x[n])) != s.end()){
        ans2 += get<0>(x[n]);
        cout << min(ans1, ans2) << endl;
        return 0;
    }

    ans2 = 0;
    rep(i, n-2){
        ans2 += get<0>(x[i]);
    }

    ans2 = min(ans2 + get<0>(x[n-2]) + get<0>(x[n+1]), ans2 + get<0>(x[n-1]) + get<0>(x[n]));
    cout << min(ans1, ans2) << endl;

    return 0;
}