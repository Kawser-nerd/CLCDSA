#define SORT(v) sort(begin(v), end(v))
#define FIND(v,x) find(begin(v), end(v), (x))
#define MEMNEXT(from, to) do{ memmove((to), (from), sizeof(from)); \
                            memset((from), 0, sizeof(from)); } while(0)
#define DUMP(x) std::cerr << "(DUMP) " << (#x) << ": " << x << std::endl
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <numeric>
#include <utility>

// #include "ane.cpp"

const long long INFLL = 1e18;
const int INF  = 1e9;
const int NMAX = 102;
const int MMAX = 100005;
const int MOD  = 1e9 + 7;
using namespace std;

// comment to disable debug functions
#define DEBUG





//
//  library begin
//

// frequent used aliases
typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, int> lp;
typedef pair<ll, ll> llp;
typedef vector<int> vec;
typedef vector<vec> mat;

// frequently used constants
static const int di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
static const int dj[] = {-1, -1, -1, 0, 0, 1, 1, 1};

// freawuently used structs
struct edge{
    int to,cost;
};

// printf for debug
void debug(const char* format, ...){
    #ifndef DEBUG
    return;
    #endif
    va_list arg;
    va_start(arg, format);
    vprintf(format, arg);
    va_end(arg);
}

// fill of multi dimensions
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
    // *** important: NMAX must be a power of 2.***
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
// library end
//







ll N,M,K,A,B,C,D,E;
int W[NMAX], V[NMAX], W_0;
ll dp[NMAX][NMAX][NMAX * 3];
vec v;

ll ans = 0;

void solve(){
    // mainalgorithm
    dp[1][1][0] = V[0];
    dp[1][0][0] = 0;
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            for (int k = 0; k < N * 3; ++k)
            {
                if(dp[i][j][k] == -1LL) continue;
                if(W_0 * (j+1) + (k + W[i]) <= M)
                    dp[i+1][j+1][k+W[i]] = max(dp[i+1][j+1][k+W[i]],
                                               dp[i][j][k] + V[i]);
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }
}
void debug(){
    // output debug information
}
void answer(){
    // output answer
    for (int i = 0; i < N+1; ++i)
    {
        for (int j = 0; j < N * 3; ++j)
        {
            if(i * W_0 + j > M) continue;
            ans = max(ans, dp[N][i][j]);
        }
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    // operate inputs

    Fill(dp, -1LL);
    scanf("%lld%lld", &N,&M);
    cin >> W[0] >> V[0];
    W_0 = W[0];
    W[0] = 0;
    for (int i = 1; i < N; ++i)
    {
        scanf("%d%d", &W[i], &V[i]);
        W[i] -= W_0;
    }
    solve();
    #ifdef DEBUG
    debug();
    #endif
    answer();

    return 0;
}