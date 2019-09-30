#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using ll  = long long;
#define rep(i, j) for (int i = 0; i < (int)(j); i++)
#define repeat(i, j, k) for (int i = (j); i < (int)(k); i++)
#define all(v) v.begin(), v.end()
#define debug(x) cerr << #x << " : " << x << endl

template <class T>
bool set_min(T &a, const T &b) {
    return a > b ? a = b, true : false;
}
template <class T>
bool set_max(T &a, const T &b) {
    return a < b ? a = b, true : false;
}
// vector
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &a : v) is >> a;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const T &t : v) os << "\t" << t;
    return os << endl;
}
// pair
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &v) {
    return os << "<" << v.first << ", " << v.second << ">";
}

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

class Solver {
  public:
    bool solve() {
        int H, W;
        cin >> H >> W;

        vector<string> S(H);
        cin >> S;

        auto is_symmetric = [](int i, int j, vector<string> &s) {
            bool ok = true;
            rep(k, s.size()) ok &= s[k][i] == s[s.size() - k - 1][j];
            return ok;
        };
        auto check = [&](vector<pii> &pairs) {
            vector<string> arranged_s(H);
            {
                int i = 0;
                for (auto p : pairs) {
                    if (p.first == p.second) {
                        arranged_s[H / 2] = S[p.first];
                    } else {
                        arranged_s[i]         = S[p.first];
                        arranged_s[H - i - 1] = S[p.second];
                        i++;
                    }
                }
                assert(i == H / 2);
            }
            vector<int> used(W);
            bool used_center = W % 2 == 0;
            rep(i, W) if (not used[i]) {
                repeat(j, i + 1, W) if (not used[j]) {
                    if (is_symmetric(i, j, arranged_s)) {
                        used[i] = used[j] = true;
                        break;
                    }
                }
                if (not used[i]) {
                    if (used_center or not is_symmetric(i, i, arranged_s))
                        return false;
                    used_center = true;
                    used[i]     = true;
                }
            }
            return true;
        };

        function<bool(vector<int> &, vector<pii> &, bool)> search =
            [&](vector<int> &used, vector<pii> &pairs, bool center_used) {
                int first = -1;
                rep(i, used.size()) if (not used[i]) {
                    if (first < 0) {
                        first   = i;
                        used[i] = true;

                        if (not center_used) {
                            pairs.emplace_back(first, first);
                            if (search(used, pairs, true)) return true;
                            pairs.pop_back();
                        }
                    } else {
                        used[i] = true;
                        pairs.emplace_back(first, i);
                        if (search(used, pairs, center_used)) return true;
                        pairs.pop_back();
                        used[i] = false;
                    }
                }
                if (first < 0) {
                    return check(pairs);
                } else {
                    used[first] = false;
                    return false;
                }
            };
        vector<int> used(H);
        vector<pii> pairs;
        cout << (search(used, pairs, H % 2 == 0) ? "YES" : "NO") << endl;

        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}