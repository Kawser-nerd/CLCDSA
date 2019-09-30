#include <algorithm>
#include <cmath>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
#define int ll

const int MOD = 1e9 + 7;
const int INF = 1e15 + 373;

#define rep(i, n) for (int i = 0; i < (n); ++i)

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> init_vector2(size_t n0, size_t n1, T e = T()) {
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> init_vector3(size_t n0, size_t n1, size_t n2, T e = T()) {
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (T e : v) {
        os << e << ", ";
    }
    os << "]";
    return os;
}

int solve(const string& s, char x){
    if(count(s.begin(), s.end(), x) == 0){
        return INF;
    }
    string t = s;
    while((size_t)count(t.begin(), t.end(), x) != t.length()){
        string tt;
        tt.resize(t.length() - 1);

        for(size_t i = 0; i < tt.length(); i++){
            tt[i] = t[i];
            if(t[i+1] == x){
                tt[i] = x;
            }
        }
        t = tt;
    }
    return s.length() - t.length();
}

signed main() {
    string s;
    cin >> s;

    int ans = s.length();
    for(char c = 'a'; c <= 'z'; c++){
        ans = min(ans, solve(s, c));
    }
    cout << ans << endl;

    return 0;
}