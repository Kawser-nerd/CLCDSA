#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cctype>
#include <ctime>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>

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

std::vector<int> table = { 
1000,961,900,841,784,729,676,625,576,529,512,484,441,400,361,324,289,256,243,225,216,196,169,144,128,125,121,100,81,64,49,36,32,27,25,16,9,8,4,1
};

void solve(void)
{
    int x;
    legit(x);
    int index = -1;
    while (table[++index] > x)
        ;
    printf("%d\n", table[index]);
}