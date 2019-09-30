#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cctype>
#include <ctime>
#include <set>
#include <algorithm>

namespace LegitStream
{
char bufdatum[BUFSIZ];
char *buf = bufdatum, *endbuf = bufdatum;

inline bool eof(void)
{
    if (endbuf == buf)
    {
        endbuf = (buf = bufdatum) + fread(bufdatum, 1, BUFSIZ, stdin);
        return endbuf == buf;
    }
    else
        return false;
}

inline int nextch(void)
{
    return eof() ? EOF : *buf++;
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
}
using LegitStream::nextch;
using LegitStream::eof;
using LegitStream::legit;

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

const size_t MaxN = 100 + 7;

size_t n;
char str[MaxN];
bool pre[MaxN][MaxN], post[MaxN][MaxN];

void solve(void)
{
    // Init
    legit(n);
    for (size_t i = 0; i < n; ++i)
        str[i] = nextch();
    pre[0][str[0] - 'a'] = true;
    for (size_t i = 1; i < n; ++i)
    {
        for (size_t j = 0; j < 30; ++j)
            pre[i][j] = pre[i - 1][j];
        pre[i][str[i] - 'a'] = true;
    }
    post[n - 1][str[n - 1] - 'a'] = true;
    for (int i = n - 2; i >= 0; --i)
    {
        for (size_t j = 0; j < 30; ++j)
            post[i][j] = post[i + 1][j];
        post[i][str[i] - 'a'] = true;
    }
    int ans = 0;
    for (size_t pos = 0; pos < n - 1; ++pos)
    {
        int now = 0;
        for (size_t i = 0; i < 30; ++i)
            if (pre[pos][i] && post[pos + 1][i])
                ++now;
        ans = std::max(ans, now);
    }
    printf("%d\n", ans);
}