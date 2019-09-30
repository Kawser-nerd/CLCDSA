#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cmath>
#include <numeric>
#include <string>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define rrep(i, a, b) for(int i = (a); i > (b); --i )
#define REP(i, a, b) for(int i = (a); i <= (b); ++i )
#define RREP(i, a, b) for(int i = (a); i >= (b); --i )
#define ullrep(i, a, b) for(ull i = (a); i < (b); ++i )
#define ullrrep(i, a, b) for(ull i = (a); i > (b); --i )
#define ullREP(i, a, b) for(ull i = (a); i <= (b); ++i )
#define ullRREP(i, a, b) for(ull i = (a); i >= (b); --i )

class DisjointSet {
public:
    DisjointSet(){};
    DisjointSet(int size) {
        p_.resize(size, 0);
        rank_.resize(size, 0);
    };

    void makeSet(int x) {
        p_[x] = x;
        rank_[x] = 0;
    }

    bool same(int x, int y) {
        return findSet(x) == findSet(y);
    }
    int findSet(int x) {
        if (x != p_[x]) {
            p_[x] = findSet(p_[x]);
        }
        return p_[x];
    }

    void unite(int x, int y) {
        link(findSet(x), findSet(y));
    }

    void link(int x, int y) {
        if (rank_[x] > rank_[y]) {
            p_[y] = x;
        }else{
            p_[x] = y;
            if (rank_[x] == rank_[y]) {
                rank_[y]++;
            }
        }
    }

private:
    vector<int> p_, rank_;
};


int P[100001];
int main() {
    int N, M;
    cin >> N >> M;
    auto d = DisjointSet(N);
    rep(i, 0, N) {
        cin >> P[i];
        d.makeSet(i);
    }
    rep(i, 0, M) {
        int x, y;
        cin >> x >> y;
        d.unite(P[x-1]-1, P[y-1]-1);
    }
    std::vector<int> s;
    s.resize(N, 0);
    int cnt = 0;
    rep(i, 0, N) {
        if (d.same(i, P[i]-1)) {
            cnt++;
        }
    }
    cout << cnt << endl;
}