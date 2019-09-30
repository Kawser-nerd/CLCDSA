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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> initVec2(size_t n0, size_t n1, T e = T()){
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> initVec3(size_t n0, size_t n1, size_t n2, T e = T()){
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

int n, c;
vector<int> id, ans, cnt;

void construct(int d){
    if(d == n){
        return;
    }

    construct(d + 1);

    ans.push_back(ans.back() ^ (1 << id[d]));
    cnt[d]++;
    if(cnt[d] == (1 << d) && d % 2 == 0 && d <= c - 3){
        swap(id[d+1], id[d+2]);
    }

    construct(d + 1);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> n >> a >> b;

    int x = a ^ b;
    c = 0;
    deque<int> d;
    rep(i, n){
        if((x >> i) % 2){
            c++;
            d.push_front(i);
        }else{
            d.push_back(i);
        }
    }
    if(c % 2 == 0){
        cout << "NO" << endl;
        return 0;
    }

    id = vector<int>(n);
    rep(i, n){
        id[i] = d.front();
        d.pop_front();
    }

    ans.push_back(a);
    cnt = vector<int>(n);

    construct(0);

    cout << "YES" << endl;
    rep(i, SZ(ans)){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}