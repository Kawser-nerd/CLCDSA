#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cmath>
#include <numeric>
#include <string>
#include <queue>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define rrep(i, a, b) for(int i = (a); i > (b); --i )
#define REP(i, a, b) for(int i = (a); i <= (b); ++i )
#define RREP(i, a, b) for(int i = (a); i >= (b); --i )
#define llrep(i, a, b) for(ll i = (a); i < (b); ++i )
#define llrrep(i, a, b) for(ll i = (a); i > (b); --i )
#define llREP(i, a, b) for(ll i = (a); i <= (b); ++i )
#define llRREP(i, a, b) for(ll i = (a); i >= (b); --i )
#define ullrep(i, a, b) for(ull i = (a); i < (b); ++i )
#define ullrrep(i, a, b) for(ull i = (a); i > (b); --i )
#define ullREP(i, a, b) for(ull i = (a); i <= (b); ++i )
#define ullRREP(i, a, b) for(ull i = (a); i >= (b); --i )

template<typename T=int>
class UnionFind {
public:
    explicit UnionFind(unsigned long long n) : rank_(n, 0), p_(n, 0) {
        for (T i = 0; i < n; i++) {
            MakeSet(i);
        }
    }

    void MakeSet(T x) {
        p_[x] = x;
        rank_[x] = 0;
    }

    bool Same(T x, T y) {
        return FindSet(x) == FindSet(y);
    }

    void Link(T x, T y) {
        if (rank_[x] > rank_[y]) {
            p_[y] = x;
        } else {
            p_[x] = y;
            if (rank_[x] == rank_[y]) {
                rank_[y]++;
            }
        }
    }

    void Unite(T x, T y) {
        Link(FindSet(x), FindSet(y));
    }

    T FindSet(T x) {
        if (x != p_[x]) {
            p_[x] = FindSet(p_[x]);
        }
        return p_[x];
    }

private:
    std::vector<T> rank_, p_;
};
template<typename NumT = ull, typename CostT = ull>
class Dijkstra {
public:
    Dijkstra(unsigned long long num, CostT max_cost) :
            num_(num),
            max_cost_(max_cost),
            v_(num, std::vector<CostT>(num, max_cost)),
            c_(num, 0),
            d_(num, max_cost),
            p_(num, 0) {
    };


    void ComputeWithQ(NumT start) {
        d_[start] = 0;
        p_[start] = start;
        priority_queue<std::pair<CostT, NumT>> pq;
        pq.push(make_pair(0, start));
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            auto ni = node.second;
            auto c = -node.first;
            c_[ni] = 1;
            if (d_[ni] < c) {
                continue;
            }
            d_[ni] = c;

            for (int i = 0; i < num_; i++) {
                if(v_[ni][i] == max_cost_) {
                    continue;
                }
                if ((c_[i] != 1) && (d_[i] > (v_[ni][i] + d_[ni]))) {
                    p_[i] = ni;
                    d_[i] = v_[ni][i] + d_[ni];
                    pq.push(make_pair(-d_[i], i));
                }
            }
        }
    }

    void Compute(int start) {
        d_[start] = 0;
        p_[start] = start;
        while (true) {
            int m = -1;
            int min_d = std::numeric_limits<int>::max();
            for (int i = 0; i < num_; i++) {
                if ((c_[i] == 0) && (min_d > d_[i])) {
                    min_d = d_[i];
                    m = i;
                }
            }
            if (m < 0) {
                break;
            }
            c_[m] = 1;
            for (int i = 0; i < num_; i++) {
                if ((c_[i] == 0) && (d_[i] > (d_[m] + v_[m][i])) ) {
                    d_[i] = d_[m] + v_[m][i];
                    p_[i] = m;
                }
            }
        }
    }

    void Set(NumT s, NumT d, CostT c) {
        v_[s][d] = c;
    }

    CostT Distance(NumT d) {
        return d_[d];
    }

public:
    NumT num_;
    CostT max_cost_;
    std::vector<std::vector<CostT>> v_;
    std::vector<int> c_;
    std::vector<int> d_;
    std::vector<NumT> p_;
};
int nibutan(int *ary, int ok, int ng) {
    bool is_valid;
    while ( std::abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        // is_valid = check(mid);
        if (is_valid) {
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}

template<typename NumT = int, typename CostT = unsigned long long>
class DijkstraQ {
public:
    DijkstraQ(unsigned long long num, CostT max_cost):
    adj_(num, std::vector<std::pair<NumT, CostT>>()),
    c_(num, 0),  d_(num, max_cost)
    {}

    void Compute(NumT start) {
        std::priority_queue<std::pair<CostT, NumT>> q;
        d_[start] = 0;
        q.push(std::make_pair(0, start));

        while(!q.empty()) {
            std::pair<CostT, NumT> node = q.top();
            q.pop();
            auto n = node.second;
            auto c = -node.first;
            c_[n] = 1;
            if (c > d_[n]) {
                continue;
            }
            d_[n] = c;

            for (NumT i = 0; i < adj_[n].size(); i++) {
                auto nn = adj_[n][i].first;
                auto nc = adj_[n][i].second;
                if (c_[nn] > 0) {
                    continue;
                }
                if (d_[nn] > (c + nc)) {
                    d_[nn] = c + nc;
                    q.push(std::make_pair(-d_[nn], nn));
                }
            }
        }
    }

    void Set(NumT s, NumT d, CostT c) {
        adj_[s].push_back(std::make_pair(d, c));
    }

    CostT Distance(NumT d) {
        return d_[d];
    }

    std::vector<CostT> d_;
    std::vector<int> c_;
    std::vector<std::vector<std::pair<NumT, CostT>>> adj_;
};

// x >= y
template <typename T>
inline T gcd(T x, T y) {return y?gcd(y, x%y): x;}

template <typename T>
inline T lcm(T x, T y) {return (x / gcd(x, y)) * y;}


// return gcd(a, b)
// x, y satisfy ax + by = gcd(a, b)
ll xgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = xgcd(b, a % b, y, x);
    y -= a / b  * x;
    return d;
}

bool check(int *A, int i) {
    return A[i] < 39;
}
int nibutan(int *A) {
    int ok = 0;
    int ng = 100;
    while (ng - ok > 1) {
        cout << ng << ", " << ok << endl;
        if (check(A, (ng + ok) / 2)) {
            ok = (ng + ok) / 2;
        }else{
            ng = (ng + ok) / 2;
        }
    }
    return ok;
}


ll MOD = 1000000007;
string S;
ll NUM[100010][4];

void add(ll &a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    cin >> S;
    rep(i, 0, S.size()) {
        rep(j, 0, 4) {
            NUM[i+1][j] = NUM[i][j];
            if (S[i] == "ABC?"[j]) {
                NUM[i+1][j]++;
            }
        }
    }
    ll sum = 0;

    ll BUF[150000];
    BUF[0] = 1;
    rep(i, 0, 150000) {
        BUF[i+1] = BUF[i] * 3 % MOD;
    }

    rep(i, 0, S.size()) {
        if (S[i] != 'B' && S[i] != '?') {
            continue;
        }
        //left A
        ll LAN = NUM[i][0];
        ll RCN = NUM[S.size()][2] - NUM[i+1][2];
        ll LQN = NUM[i][3];
        ll RQN = NUM[S.size()][3] - NUM[i+1][3];
        sum += ((LAN * RCN % MOD) * ((BUF[LQN+RQN]) % MOD)) % MOD;
        sum %= MOD;
        sum += ((LAN * RQN % MOD) * ((BUF[LQN+RQN-1]) % MOD)) % MOD;
        sum %= MOD;
        sum += ((LQN * RCN % MOD) * ((BUF[LQN+RQN-1]) % MOD)) % MOD;
        sum %= MOD;
        sum += ((LQN * RQN % MOD) * ((BUF[LQN+RQN-2]) % MOD)) % MOD;
        sum %= MOD;
    }
    cout << sum << endl;
}