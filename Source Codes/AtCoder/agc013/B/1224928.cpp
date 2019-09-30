#define SORT(v) sort(begin(v), end(v))
#define FIND(v,x) find(begin(v), end(v), (x))
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstdarg>
#include <cstdio>
#include <cmath>
#include <numeric>
#include <utility>

// #include "ane.cpp"

#define INF (int)1e9
#define INFLL (long long)1e18
#define NMAX 100005
#define MMAX 100005
#define MOD 100000
using namespace std;

// ??????????debug()??????
// #define DEBUG





//
//  ?????
//

// frequent used aliases
typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, int> lp;
typedef pair<ll, ll> llp;
typedef vector<int> vec;
typedef vector<vec> mat;

// frequent used constants
static const int di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
static const int dj[] = {-1, -1, -1, 0, 0, 1, 1, 1};

// ?????printf
void debug(const char* format, ...){
    #ifndef DEBUG
    return;
    #endif
    va_list arg;
    va_start(arg, format);
    vprintf(format, arg);  // ????????
    va_end(arg);
}

// n??????????????????????????????
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// Union-Find Tree
class UnionFindTree{
    struct node{
        int par;
    };
    std::vector<node> T;

    public:
    void init(int num){
        T.resize(num+1);    // ignore T[0]
        for (int i = 1; i <= num; ++i)
        {
            T[i].par = i;
        }
    }
    void unite(int x, int y){
        T[find(y)].par = find(x);
    }
    int find(int x){
        if (T[x].par == x) return x;
        else return T[x].par = find(T[x].par);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

// Segment Tree for Range Minimum Query
    // **********************************************************
    // *** important: all functions' variable,                ***
    // *** such as "index", "l", "r", etc., must be 0-origin. ***
    // **********************************************************
    // ********************************************
    // *** important: NMAX must be power of 2. ***
    // ********************************************
template<typename T>
class SegmentTree{
    private:
    ll N;
    T INF_VAL;
    T dat[NMAX * 2]; // 0 origin, A[i] = dat[i + N]

    T _query(ll l, ll r, ll l_resp, ll r_resp, ll i_dat){
        debug("query(%lld, %lld, %lld, %lld, %lld) called\n",
            l, r, l_resp, r_resp, i_dat);
        if (r < l_resp || r_resp < l) return INF_VAL;
        else if(l <= l_resp && r_resp <= r) return dat[i_dat];
        else return min(_query(l ,r, l_resp, (l_resp + r_resp) / 2, i_dat * 2),
                        _query(l, r, (l_resp + r_resp) / 2 + 1, r_resp, i_dat * 2 + 1));
    }

    public:
    void init(ll _N, T _inf_val){
        N = 1; while(N < _N) N *= 2;
        INF_VAL = _inf_val;
        Fill(dat, _inf_val);
    }
    T get(ll index){
        return dat[index + N];
    }
    void set(int index, T val){
        int i_dat = index + N;
        dat[i_dat] = val;
        for (i_dat /= 2; i_dat > 0; i_dat /= 2)
        {
            dat[i_dat] = min(dat[i_dat * 2], dat[i_dat * 2 + 1]);
        }
    }
    T query(ll l, ll r){
        return _query(l, r, 0, N - 1, 1);
    }
    void dump(){
        cout << "*** SegTree dump begin ***\n";
        cout << "N = " << N << ", INF_VAL = " << INF_VAL << endl;
        for (int i = 1; i < N * 2; i *= 2)
        {
            for (int j = i; j < i * 2; ++j)
            {
                if(dat[j] == INF_VAL) cout << "INF ";
                else cout << dat[j] << " ";
            }
            cout << endl;
        }
        cout << "*** SegTree dump end ***\n";
    }
};

// Binary Indexed Tree for Range Sum Query
    // *******************************************
    // *** important: all functions' variable, ***
    // *** such as "i", must be 1-origin.      ***
    // *******************************************
template<typename T>
class BinaryIndexedTree{
    private:
    ll N;
    T dat[NMAX + 1]; // 1 origin, A[i] = sum(i) - sum(i-1)

    public:
    void init(ll _N){
        N = _N;
        Fill(dat, 0);
    }
    void add(int i, T val){
        while(i <= N) {
            dat[i] += val;
            i += i & -i;
        }
    }
    T sum(ll i){
        T ret = 0;
        while(i > 0) {
            ret += dat[i];
            i -= i & -i; // set last HIGH bit to LOW
        }
        return ret;
    }
    T sum(ll left, ll right){
        return sum(right) - sum(left - 1);
    }
    void dump(){
        cout << "*** BITree dump begin ***\n";
        cout << "N = " << N << endl;
        for (int i = 1; i <= N; i *= 2)
        {
            cout << dat[i] << " ";
        }
        cout << "*** BITree dump end ***\n";
    }
};

//
// ???????
//







ll N,M,K,A[MMAX],B[MMAX],C,D,E;
int dp[NMAX] = {};
vec G[NMAX];
deque<int> ans;
map<int, bool> ans_includes;

void solve(){
    // ????????
    ans.push_back(1);
    ans_includes[1] = true;
    // ans: 1
    while(true) {
        bool next = false;
        for (auto&& i: G[ans.front()])
        {
            if (!ans_includes[i])
            {
                ans.push_front(i);
                ans_includes[i] = true;
                // debug("push_front(%d)\n", i);
                next = true;
                break;
            }
        }
        if(!next)break;
    }
    while(true){
        bool next = false;
        for (auto&& i: G[ans.back()])
        {
            if (!ans_includes[i])
            {
                ans.push_back(i);
                ans_includes[i] = true;
                // debug("push_back(%d)\n", i);
                next = true;
                break;
            }
        }
        if(!next) break;
    }

}
void debug(){
    // ???????
}
void answer(){
    // ????
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size() - 1; ++i) {
        printf("%d ", ans[i]);
    }
    cout << ans.back() << endl;
}
int main(int argc, char const *argv[])
{
    // ???????????

    // Fill(dp, -1);
    scanf("%lld%lld", &N,&M);
    for (int i = 0; i < N; ++i)
    {
        G[i].reserve(min(N, 500LL));
    }
    for (int i = 0; i < M; ++i)
    {
        scanf("%lld%lld", &A[i], &B[i]);
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    solve();
    #ifdef DEBUG
    debug();
    #endif
    answer();

    return 0;
}