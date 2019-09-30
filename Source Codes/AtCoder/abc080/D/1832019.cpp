#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
#include <ctype.h>
using namespace std;

#define PI acos(-1.0)
#define EPS 1e-8
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
    return os << "(" << P.fi << "," << P.se << ")";
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
    os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}

struct Matrix {
    vvi data;
    int r, c;
    Matrix(int row, int col, bool identity = false) : r(row), c(col) {
        data.assign(row, vector<int>(col, 0));
        if (identity) {
            for (int i = 0; i < r; ++i) {
                data[i][i] = 1;
            }
        }
    }
    Matrix operator * (Matrix& other) {
        int m = r, n = c, p = other.c;
        Matrix res(m, p);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                for (int k = 0; k < n; ++k) {
                    res.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return res;
    }
};

// ???????? res[1] * a + res[2] * b = res[0] = gcd(a, b)
vector<int> extendGcd(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    } else {
        vector<int> tmp = extendGcd(b, a % b);
        return {tmp[0], tmp[2], tmp[1] - (a / b) * tmp[2]};
    }
}

// ?????
Matrix matrix_power(Matrix base, ll exp) {
    int n = base.r;
    Matrix res(n, n, true);
    while (exp) {
        if (exp & 1) {
            res = res * base;
        }
        base = base * base;
        exp >>= 1;
    }
    return res;
}

// ?????
template <typename T>
T power_mod(T base, int exp, int mod = MOD) {
    T res = 1;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// ???
template <typename T>
T power(T base, int exp) {
    T res = 1;
    while (exp) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

// ???
ll inv(ll a) {
    return power_mod(a, MOD - 2);
}

/******************************** template ********************************/
#define N 100050
int n, c;

struct show {
    int s;
    int t;
    int cc;
}shows[N];

bool cmp(show a, show b) {
    return a.s < b.s;
}

// end time, channel
vector<pii> res;

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &shows[i].s, &shows[i].t, &shows[i].cc);
    }

    sort(shows, shows + n, cmp);

    for (int i = 0; i < n; ++i) {
        int earliest = INT_MAX;
        int index = -1;

        for (int j = 0; j < res.size(); ++j) {
            if (res[j].second == shows[i].cc) {
                if (res[j].first <= earliest) {
                    earliest = res[j].first;
                    index = j;
                }
            } else {
                if (res[j].first < earliest) {
                    earliest = res[j].first;
                    index = j;
                }
            }
        }

        if (index == -1 || earliest > shows[i].s || (earliest == shows[i].s && res[index].second != shows[i].cc)) {
            res.push_back({shows[i].t, shows[i].cc});
        } else {
            res[index] = {shows[i].t, shows[i].cc};
        }
    }

    cout << res.size();

    return 0;
}