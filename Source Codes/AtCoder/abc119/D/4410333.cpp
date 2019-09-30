#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define MOD7 1000000007
#define MOD9 1000000009

#define rep(i, n) for (int i = 0; i < (n); i++)
#define itrep(i, a) for (auto i = (a).begin(); i != (a).end(); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define mp(a, b) make_pair((a), (b))

using namespace std;

const int INF = 1e15;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

template<class T> void inputVector(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}

int getNext(const vector<int> &a, int x) {
    auto it = lower_bound(all(a), x);
    if (it == a.end()) return INF;
    return *it;
}

int getPrev(const vector<int> &a, int x) {
    auto it = upper_bound(all(a), x);
    if (it == a.begin()) return INF;
    it--;
    return *it;
}

int f(const vector<int> &a, const vector<int> &b, int x) {
    int ret = 0;
    int next = getNext(a, x);
    ret += abs(x - next);
    int nnext = getNext(b, next);
    int nprev = getPrev(b, next);
    ret += min(abs(next - nnext), abs(next - nprev));
    return ret;
}

int g(const vector<int> &a, const vector<int> &b, int x) {
    int ret = 0;
    int next = getPrev(a, x);
    ret += abs(x - next);
    int nnext = getNext(b, next);
    int nprev = getPrev(b, next);
    ret += min(abs(next - nnext), abs(next - nprev));
    return ret;
}

signed main() {
    int A, B, Q;
    cin >> A >> B >> Q;

    vector<int> s, t;
    inputVector(s, A);
    inputVector(t, B);

    rep(_, Q) {
        int x;
        cin >> x;

        int ret = LLONG_MAX;
        ret = min(ret, f(s, t, x));
        ret = min(ret, f(t, s, x));
        ret = min(ret, g(s, t, x));
        ret = min(ret, g(t, s, x));

        cout << ret << endl;
    }

    return 0;
}