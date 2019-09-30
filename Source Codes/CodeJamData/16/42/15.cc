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

using R = long double;
// O(k^2)
R solve(vector<R> &use){//{{{
    const int k = use.size();
    vector<R> dp(k+10);
    dp[0] = 1;
    rep(i, k){
        vector<R> qb(k+10);
        rep(j, k){
            qb[j+1] += dp[j] * use[i];
            qb[j] += dp[j] * (1 - use[i]);
        }
        swap(dp, qb);
    }
    return dp[k/2];
}//}}}

void solve(GCJ::Runner &gcj){
    int n, k; cin >> n >> k;
    vector<R> p(n);
    rep(i, n) cin >> p[i];

    gcj.end_input();
    sort(all(p));

    R res = 0;
    vector<R> use(k);
    rep(l, k+1){
        use.clear();
        rep(i, l) use.emplace_back(p[i]);
        rep(i, k-l) use.emplace_back(p[n-i-1]);
        chmax(res, solve(use));
    }
    gcj << res << endl;
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
