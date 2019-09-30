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
template<class ...Ts> struct Zipper{//{{{
    using Key = typename std::conditional<sizeof...(Ts) == 1, typename std::tuple_element<0, std::tuple<Ts...>>::type,
          typename std::conditional<sizeof...(Ts) == 2, std::pair<typename std::tuple_element<0, std::tuple<Ts...>>::type, typename std::tuple_element<1, std::tuple<Ts..., void>>::type>,
          std::tuple<Ts...>>::type>::type;

    mutable map<Key, int> zip;
    mutable vector<Key> unzip;
    template<class It> void add(It b, It e){ while(b != e) add(*b++); }
    void add(const Ts &...ts){ this->operator()(ts...); }
    void compile(){
        int i = 0;
        for(auto &x : zip) unzip[x.second = i++] = x.first;
    }
    const Key operator[](const int &i) const { return unzip[i]; }
    int operator()(const Ts &...ts) const {
        const Key key(ts...);
        auto it = zip.find(key);
        if(it != std::end(zip)) return it->second;
        const int n = unzip.size();
        unzip.emplace_back(key);
        zip.insert(make_pair(std::move(key), n));
        return n;
    }
    int size() const { return unzip.size(); }
    int count(const Ts &...ts) const { return zip.count(Key(ts...)); }
    typename vector<Key>::const_iterator begin(){ return unzip.begin(); }
    typename vector<Key>::const_iterator end(){ return unzip.end(); }
};//}}}

void solve(GCJ::Runner &gcj){
    int h, w; cin >> h >> w;
    //       x,   y,  section
    Zipper<int, int, char> zip;
    vector<int> pos;
    rep(j, w) pos.emplace_back(zip(0,   j, 'T'));
    rep(i, h) pos.emplace_back(zip(i, w-1, 'R'));
    rep(j, w) pos.emplace_back(zip(h-1, w-j-1, 'B'));
    rep(i, h) pos.emplace_back(zip(h-i-1, 0, 'L'));

    vector<pair<int, int>> lover;
    map<int, int> g;
    rep(_, h+w){
        int i, j; cin >> i >> j; --i; --j;
        lover.emplace_back(pos[i], pos[j]);
        g[pos[i]] = pos[j];
        g[pos[j]] = pos[i];
    }

    gcj.end_input();
    rep(i, h) rep(j, w) REP(di, -1, 2) REP(dj, -1, 2){
        zip.add(i+di, j+dj, 'T');
        zip.add(i+di, j+dj, 'B');
        zip.add(i+di, j+dj, 'R');
        zip.add(i+di, j+dj, 'L');
    }

    rep(A, 1<<(h*w)){
        vector<vector<char>> wall(h, vector<char>(w));
        rep(i, h) rep(j, w) wall[i][j] = ((A>>(i*w+j)&1) ? '/' : '\\');
        UnionFind uf(zip.size());
        rep(i, h) rep(j, w){
            uf.unite(zip(i, j, 'R'), zip(i, j+1, 'L'));
            uf.unite(zip(i, j, 'B'), zip(i+1, j, 'T'));
        }
        rep(i, h) rep(j, w){
            if(wall[i][j] == '/'){
                uf.unite(zip(i, j, 'T'), zip(i, j, 'L'));
                uf.unite(zip(i, j, 'B'), zip(i, j, 'R'));
            }else{
                uf.unite(zip(i, j, 'T'), zip(i, j, 'R'));
                uf.unite(zip(i, j, 'B'), zip(i, j, 'L'));
            }
        }
        bool ok = true;
        repsz(i, pos) rep(j, i) if(uf.same(pos[i], pos[j]) and g[pos[i]] != pos[j])
            ok = false;
        for(auto &a : lover) if(!uf.same(a.first, a.second)) ok = false;
        // tr << wall << endl;
        // repsz(i, pos) rep(j, i)
        //     if(uf.same(pos[i], pos[j])) tr << zip[pos[i]] << ' ' << zip[pos[j]] << endl;

        if(ok){
            rep(i, h){
                rep(j, w) gcj << wall[i][j];
                gcj << endl;
            }
            return;
        }
    }
    gcj << "IMPOSSIBLE" << endl;
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
        std::cout << "Case #" << i+1 << ": " << endl << res.get() << std::flush;
    }
    for(auto &th : threads) th.join();
    return 0;
}//}}}
// vim:set foldmethod=marker commentstring=//%s:
