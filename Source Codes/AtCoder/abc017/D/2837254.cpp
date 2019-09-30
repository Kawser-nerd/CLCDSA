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
class Dijkstra {
public:
    Dijkstra(unsigned long long num, int max_cost) :
            num_(num),
            max_cost_(max_cost),
            v_(num, std::vector<int>(num, max_cost)),
            c_(num, 0),
            d_(num, max_cost),
            p_(num, 0) {
    };

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

public:
    int num_;
    int max_cost_;
    std::vector<std::vector<int>> v_;
    std::vector<int> c_;
    std::vector<int> d_;
    std::vector<int> p_;
};
class DijkstraQueue {
public:
    DijkstraQueue(unsigned long long num, int max_cost):
            num_(num),
            adj_(num),
            c_(num, 0),
            d_(num, max_cost),
            p_(num, 0)
    {}

    void Compute(int start) {
        std::priority_queue<std::pair<int, int>> pq;
        d_[start] = 0;
        pq.push(std::make_pair(0, start));
        while (!pq.empty()) {
            auto f = pq.top();// cost, i
            pq.pop();
            int u = f.second;
            c_[u] = 1;
            if (d_[u] < f.first * (-1)) {
                continue;
            }

            for(int j = 0; j < adj_[u].size(); j++) {
                int v = adj_[u][j].first;
                if (c_[v] == 1) continue;
                if (d_[v] > d_[u] + adj_[u][j].second) {
                    d_[v] = d_[u] + adj_[u][j].second;
                    pq.push(make_pair(d_[v] * (-1), v));
                }
            }
        }
    }
    int num_;
    std::vector<std::vector<std::pair<int, int>>> adj_; //i, cost
    std::vector<int> c_;
    std::vector<int> d_;
    std::vector<int> p_;
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

class DijkstraQ {
public:
    DijkstraQ(unsigned long long num, int max_cost):
    adj_(num, std::vector<std::pair<int, int>>()),
    c_(num, 0),  d_(num, max_cost)
    {}

    void Compute(int start) {
        std::priority_queue<std::pair<int, int>> q;
        d_[start] = 0;
        q.push(std::make_pair(0, start));

        while(!q.empty()) {
            std::pair<int, int> node = q.top();
            q.pop();
            int n = node.second;
            int c = -node.first;
            c_[n] = 1;
            if (c > d_[n]) {
                continue;
            }
            d_[n] = c;

            for (int i = 0; i < adj_[n].size(); i++) {
                int nn = adj_[n][i].first;
                int nc = adj_[n][i].second;
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
    std::vector<int> d_;
    std::vector<int> c_;
    std::vector<std::vector<std::pair<int, int>>> adj_;
};


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

int N, M;
int F[100010];
int L[100010];
int C[100010];
int DP[100010];
int MOD = 1000000007;

int main() {
    cin >> N >> M;
    DP[0] = 1;
    REP(i, 1, N) {
        cin >> F[i];
        L[i] = C[F[i]];
        C[F[i]] = i;
    }
    int sum = 0;
    int l = 0;
    REP(i, 1, N) {
        sum += DP[i-1];
        sum %= MOD;
        for(; l < L[i]; l++) {
            sum -= DP[l];
            sum %= MOD;
            if (sum < 0) sum += MOD;
        }
        DP[i] = sum % MOD;
    }
    cout << DP[N] << endl;
}