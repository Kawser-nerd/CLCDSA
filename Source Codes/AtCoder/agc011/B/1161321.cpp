#define SORT(v) sort(v.begin(), v.end())
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cstdarg>
#include <cstdio>
#include <numeric>

// #include "ane.cpp"

#define INF (int)1e9
#define LLINF (long long)1e18
#define NMAX 100000
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

ll N,M,K,A[NMAX],B,C,D,E;
int dp[NMAX][MMAX] = {};

static const int di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
static const int dj[] = {-1, -1, -1, 0, 0, 1, 1, 1};

ll ans = 0;

void solve(){
    // ????????
    sort(A, A+N);
    ll sum = A[0], chasm = 0;
    for (int i = 1; i < N; ++i)
    {
        if (sum * 2 < A[i])
        {
            chasm = i;
        }
        sum += A[i];
    }
    ans = N - chasm;
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

    scanf("%lld", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%lld", &A[i]);
    }
    solve();
    #ifdef DEBUG
    debug();
    #endif
    answer();

    return 0;
}