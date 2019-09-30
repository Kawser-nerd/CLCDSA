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

#define int long long int
#define let const auto

const int MOD = 1e9 + 7;
const int INF = 1e15 + 373;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define dump(x)                            \
    do {                                   \
        cerr << #x << ": " << (x) << endl; \
    } while (0)

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
    for (size_t i = 0; i < v.size(); i++) {
        if (i != 0) {
            os << ", ";
        }
        os << v[i];
    }
    os << "]";
    return os;
}

int next_int() {
    int e;
    cin >> e;
    return e;
}

string next_string() {
    string e;
    cin >> e;
    return e;
}

template <typename T>
void println(T e) {
    cout << e << endl;
}

class battle {
   public:
    vector<int> as;
    vector<int> bs;
    battle(const vector<int>& as, const vector<int>& bs) : as(as), bs(bs) {}
    battle() : as(0), bs(0) {}

    bool operator>(const battle& b) const {
        return (as.size() + bs.size()) > (b.as.size() + b.bs.size());
    }
};

bool solve(int h, int w, const vector<string>& c) {
    vector<battle> dat;

    rep(i, h) {
        int j = 0;
        while (j < w) {
            vector<int> as;
            vector<int> bs;

            while (j < w && c[i][j] != 'x') {
                if (c[i][j] == 'o') {
                    as.push_back(j);
                }
                j++;
            }

            while (j < w && c[i][j] != 'o') {
                if (c[i][j] == 'x') {
                    bs.push_back(j);
                }
                j++;
            }

            if (as.empty() && bs.empty()) {
                continue;
            }

            dat.push_back(battle(as, bs));
        }
    }

    int n = dat.size();

    int ad = INF;
    int bd = INF;
    rep(i, n) {
        const vector<int>& as = dat[i].as;
        const vector<int>& bs = dat[i].bs;
        if (as.empty()) {
            bd = min(bd, bs.front());
        }
        if (bs.empty()) {
            ad = min(ad, (w - 1) - as.back());
        }
    }

    if (ad != INF || bd != INF) {
        return ad <= bd;
    }

    bool turn = true;

    sort(dat.begin(), dat.end(), greater<battle>());

    rep(i, n) {
        int& ah = dat[i].as[dat[i].as.size() - 1];
        int& bh = dat[i].bs[0];

        let c = bh - ah - 2;
        if (c > 0) {
            ah += c / 2;
            bh -= c / 2;
        }

        while (bh - ah > 2) {
            if (turn) {
                ah++;
            } else {
                bh--;
            }
            turn = !turn;
        }
    }

    int ac = 0;
    rep(i, n) {
        const vector<int>& as = dat[i].as;

        int c = 0;
        for (int j = as.size() - 2; j >= 0; j--) {
            ac += (as.back() - 1 - c) - as[j];
            c++;
        }
    }

    int bc = 0;
    rep(i, n) {
        const vector<int>& bs = dat[i].bs;

        int c = 0;
        for (int j = 1; j < (int)bs.size(); j++) {
            bc += bs[j] - (bs[0] + 1 + c);
            c++;
        }
    }

    return turn ? ac > bc : ac >= bc;
}

signed main() {
    let h = next_int();
    let w = next_int();

    vector<string> c(h);
    rep(i, h) { c[i] = next_string(); }

    println(solve(h, w, c) ? "o" : "x");

    return 0;
}