#include <bits/stdc++.h>
namespace GCJ{//{{{
    std::mutex input_mutex;
    int current_case_num = 0;

    struct Runner{
        int id; // 0-origin
        std::istream &is;
        std::ostringstream os;
        Runner(std::istream &is, const std::ostream &fmt) : id(-1), is(is){
            input_mutex.lock();
            id = current_case_num++;
            os.copyfmt(fmt);
        }

        void end_input(){
            input_mutex.unlock();
        }
        std::string get_result() const { return os.str(); }

        template<class T>
        Runner &operator<<(const T &val){
            os << val;
            return *this;
        }
        Runner &operator<<(std::ostream &(*pf)(std::ostream &)){
            os << pf;
            return *this;
        }
    };
}//}}}

#include <gmpxx.h>
using ZZ = mpz_class;
using QQ = mpq_class;

#define all(x) begin(x),end(x)
#define rall(x) (x).rbegin(),(x).rend()
#define REP(i,b,n) for(int i=(int)(b);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define repsz(i,v) rep(i,(v).size())
#define aur auto&
#define bit(n) (1LL<<(n))
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second

typedef long long ll;
// #define int long long
template<class C>int size(const C &c){ return c.size(); }
template<class T,class ...U>bool chmin(T&a, const U&...bs){const T b(bs...);if(a<=b)return false;a=b;return true;}
template<class T,class ...U>bool chmax(T&a, const U&...bs){const T b(bs...);if(a>=b)return false;a=b;return true;}
using namespace std;

struct UnionFind{ //{{{
    vector<int> par;
    int n, cnt;
    UnionFind(const int &x=0){init(x);}
    void init(const int &x){par.assign(cnt = n = x, -1);}
    inline int find(const int &x){ return par[x]<0 ? x : par[x] = find(par[x]); }
    inline bool same(const int &x, const int &y){ return find(x) == find(y); }
    inline bool unite(int x, int y){
        if((x = find(x)) == (y = find(y))) return false;
        --cnt;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    inline int count() const { return cnt; }
    inline int count(int x){ return -par[find(x)]; }
};
//}}}

void solve(GCJ::Runner &gcj){
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    rep(i, n){
        string s; cin >> s;
        rep(j, n) g[i][j] = s[j] == '1';
    }
    gcj.end_input();
    UnionFind uf(2*n);
    rep(i, n) rep(j, n) if(g[i][j]) uf.unite(i, j+n);
    rep(i, n) rep(j, n) rep(k, n) if(g[i][j] and g[i][k]) uf.unite(j+n, k+n);
    rep(i, n) rep(j, n) rep(k, n) if(g[i][j] and g[k][j]) uf.unite(i, k);
    vector<pair<int, int>> bs;
    rep(i, 2*n) if(uf.find(i) == i){
        bs.emplace_back(0, 0);
        rep(j, n) if(uf.find(j) == i) ++bs.back().first;
        rep(j, n) if(uf.find(n+j) == i) ++bs.back().second;
        if(bs.back().first == bs.back().second) bs.pop_back();
    }
    int res = 0;
    rep(i, n) rep(j, n) if(!g[i][j] and uf.same(i, j+n)) ++res;

    const int T = size(bs);
    const int inf = n * n * n;
    vector<int> cost(1<<T, inf);
    rep(A, 1<<T){
        pair<int, int> ab;
        int c = 0;
        rep(i, T) if(A>>i&1){
            c += ab.fst * bs[i].snd + ab.snd * bs[i].fst;
            ab.fst += bs[i].fst;
            ab.snd += bs[i].snd;
        }
        if(ab.fst == ab.snd) cost[A] = c;
    }

    vector<int> dp(1<<T, inf);
    dp[0] = 0;
    rep(A, 1<<T) if(cost[A] < inf){
        const int mask = ((1<<T)-1)^A;
        chmin(dp[A], cost[A]);
        for(int B = mask; B > 0; B=(B-1)&mask){
            chmin(dp[A|B], dp[B] + cost[A]);
        }
    }
    gcj << res + dp.back() << endl;


    // gcj << res << std::endl;
}

signed main(){//{{{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    constexpr int max_thread = 3;

    const int T = []{
        std::string s;
        std::getline(std::cin, s);
        return std::stoi(s);
    }();

    std::mutex job_mutex;
    int job_count = 0;
    auto get_job = [&]{
        std::lock_guard<std::mutex> job_lock(job_mutex);
        return job_count++ < T;
    };
    std::vector<std::promise<std::string>> results(T);

    auto runner = [&]{
        while(get_job()){
            GCJ::Runner gcj(std::cin, std::cout);
            job_mutex.unlock();
            solve(gcj);
            results[gcj.id].set_value(gcj.get_result());
        }
    };
    std::vector<std::thread> threads(max_thread);
    for(auto &th : threads) th = std::thread(runner);
    for(int i = 0; i < T; ++i){
        std::future<std::string> res = results[i].get_future();
        std::cout << "Case #" << i+1 << ": " << res.get() << std::flush;
    }
    for(auto &th : threads) th.join();
    return 0;
}//}}}
// vim:set foldmethod=marker commentstring=//%s:
