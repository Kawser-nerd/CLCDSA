#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cmath>
#include <algorithm>

int nextch(void)
{
    static char bufdatum[BUFSIZ];
    static char *buf = bufdatum, *endbuf = bufdatum;
    if (endbuf == buf)
    {
        endbuf = (buf = bufdatum) + fread(bufdatum, 1, BUFSIZ, stdin);
        if (endbuf == buf)
            return EOF;
    }
    return *buf++;
}

void legit(void) {}

template<typename Car, typename ...Cdr>
void legit(Car &var, Cdr &...Rest)
{
    int peek;
    while (!isdigit(peek = nextch())
#ifdef LEGIT_NEGI
        && peek != '-'
#endif  // LEGIT_NEGI
        )
        ;
#ifdef LEGIT_NEGI
    bool negi;
    if (peek == '-')
        negi = true;
    else
        negi = false;
#endif  // LEGIT_NEGI
    var = 0;
    do
        var = (((var << 2) + var) << 1) + (peek ^ '0');
    while (isdigit(peek = nextch()));
#ifdef LEGIT_NEGI
    if (negi)
        var = -var;
#endif  // LEGIT_NEGI
    legit(Rest...);
}

void solve(void);

int main(void)
{
#ifdef redirect
    freopen("check/data.in", "r", stdin);
    freopen("check/prog.out", "w", stdout);
    freopen("check/log.out", "w", stderr);
#endif  // redirect
#ifdef chrono
    auto begtm = clock();
#endif  // chrono
    solve();
#ifdef chrono
    auto endtm = clock();
    printf("%f\n", static_cast<float>(endtm - begtm) / CLOCKS_PER_SEC);
#endif  // chrono
    return 0;
}

const size_t MaxN = static_cast<size_t>(1e5 + 7);

int n, k;
int arr[MaxN];
size_t idx1;

void solve(void)
{
    legit(n, k);
    for (size_t i = 0; i < n; ++i)
    {
        legit(arr[i]);
        if (1 == arr[i])
            idx1 = i;
    }
    --k;
    size_t ans = 19260817;
    for (int left = idx1, right = n - 1 - idx1 - k; left >= 0; --left, ++right)
    {
        size_t now = 0;
        if ( left % k != 0)
            ++now;
        now += left / k;
        if (right > 0)
        {
            if (right % k != 0)
                ++now;
            now += right / k;
        }
        ans = std::min(ans, now + 1);
    }
    printf("%llu\n", ans);
} ./Main.cpp:102:22: warning: format specifies type 'unsigned long long' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
    printf("%llu\n", ans);
            ~~~~     ^~~
            %zu
1 warning generated.