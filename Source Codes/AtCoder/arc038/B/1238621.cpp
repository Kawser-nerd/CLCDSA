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

#define INF (int)1e9
#define INFLL (long long)1e18
#define NMAX 102
#define MMAX 100005
#define MOD 100000
using namespace std;

// comment to disable debug functions
// #define DEBUG





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

// frequent used constants
static const int di[] = {0, 1, 1};
static const int dj[] = {1, 0, 1};

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
// library end
//







ll N,M,K,A,B,C,D,E;
int grundy[NMAX][MMAX] = {};
bool wall[NMAX][MMAX] = {};
ll ans = 0;

void solve(){
    // main algorithm
    grundy[N][M] = 0;
    for (int i = N; i > 0; --i)
    {
        for (int j = M; j > 0; --j)
        {
            if(i == N && j == M) continue;
            if (wall[i][j]) continue;
            set<int> st;
            for (int k = 0; k < 3; ++k)
            {
                int ii = i + di[k], jj = j + dj[k];
                if(wall[ii][jj]) continue;
                st.insert(grundy[ii][jj]);
            }
            for (int gr = 0; gr < 4; ++gr)
            {
                if (!st.count(gr))
                {
                    grundy[i][j] = gr;
                    break;
                }
            }
        }
    }
}
void debug(){
    // output debug information
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if(wall[i+1][j+1]) cout << '.';
            else cout << grundy[i+1][j+1];
        }
        cout << endl;
    }
}
void answer(){
    // output answer
    if (grundy[1][1])
    {
        cout << "First\n";
    }else{
        cout << "Second\n";
    }
}
int main(int argc, char const *argv[])
{
    // operate inputs

    Fill(wall, true);
    scanf("%lld%lld", &N,&M);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            char ch;
            scanf(" %c", &ch);
            wall[i+1][j+1] = (ch == '#');
        }
    }
    solve();
    #ifdef DEBUG
    debug();
    #endif
    answer();

    return 0;
}