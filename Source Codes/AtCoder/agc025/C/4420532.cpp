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

bool comp(pair<P, int> a, pair<P, int> b){
    if(a.first.second != b.first.second){
        return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<P, int>> L, R;
    rep(i, n){
        int l, r;
        cin >> l >> r;
        L.emplace_back(make_pair(l, r), i);
        R.emplace_back(make_pair(l, r), i);
    }

    sort(ALL(L), comp);
    sort(R.rbegin(), R.rend());

    int ans = 0;

    int tmp = 0;
    vector<bool> used(n, false);
    int i = 0;
    int j = 0;
    int pos = 0;
    while(i < n && j < n){
        while(i < n && used[L[i].second]){
            i++;
        }
        if(i < n){
            used[L[i].second] = true;
            if(pos < L[i].first.first){
                tmp += L[i].first.first - pos;
                pos = L[i].first.first;
            }else if(L[i].first.second < pos){
                tmp += pos - L[i].first.second;
                pos = L[i].first.second;
            }
        }

        while(j < n && used[R[j].second]){
            j++;
        }
        if(j < n){
            used[R[j].second] = true;
            if(pos < R[j].first.first){
                tmp += R[j].first.first - pos;
                pos = R[j].first.first;
            }else if(R[j].first.second < pos){
                tmp += pos - R[j].first.second;
                pos = R[j].first.second;
            }
        }
    }
    tmp += abs(pos - 0);
    ans = max(ans, tmp);

    tmp = 0;
    used = vector<bool>(n, false);
    i = 0;
    j = 0;
    pos = 0;
    while(i < n && j < n){
        while(j < n && used[R[j].second]){
            j++;
        }
        if(j < n){
            used[R[j].second] = true;
            if(pos < R[j].first.first){
                tmp += R[j].first.first - pos;
                pos = R[j].first.first;
            }else if(R[j].first.second < pos){
                tmp += pos - R[j].first.second;
                pos = R[j].first.second;
            }
        }

        while(i < n && used[L[i].second]){
            i++;
        }
        if(i < n){
            used[L[i].second] = true;
            if(pos < L[i].first.first){
                tmp += L[i].first.first - pos;
                pos = L[i].first.first;
            }else if(L[i].first.second < pos){
                tmp += pos - L[i].first.second;
                pos = L[i].first.second;
            }
        }
    }
    tmp += abs(pos - 0);
    ans = max(ans, tmp);

    cout << ans << endl;

    return 0;
}