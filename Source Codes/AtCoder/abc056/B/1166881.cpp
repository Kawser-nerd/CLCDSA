#define SORT(v) sort(v.begin(), v.end())
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cstdarg>
#include <cstdio>
#include <numeric>

// #include "ane.cpp"

#define INF (int)1e9
#define INFLL (long long)1e18
#define NMAX 200
#define MMAX 200
#define MOD 100000
using namespace std;

// ??????????db_printf()??????
#define DEBUG
// ?????printf
void db_printf(const char* format, ...){
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
typedef pair<int, int> p;
typedef long long ll;

ll N,M,K,a,b,C,D,E;
int dp[NMAX][MMAX] = {};

static const int di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
static const int dj[] = {-1, -1, -1, 0, 0, 1, 1, 1};

ll ans = 0;

void solve(){
    // ????????
    if (abs(b-a) <= N)
    {
        ans = 0;
        return;
    }
    if (a < b)
    {
        ans = b - a - N;
    }else{
        ans = a - b - N;
    }
}
void debug(){
    // ???????
}
void answer(){
    // ????
    printf("%lld\n", ans);
}
int main(int argc, char const *argv[])
{
    // ???????????

    Fill(dp, -1);

    scanf("%lld%lld%lld", &N,&a, &b);
    solve();
    #ifdef DEBUG
    debug();
    #endif
    answer();

    return 0;
}