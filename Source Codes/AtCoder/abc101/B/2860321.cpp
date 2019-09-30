#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cctype>
#include <ctime>

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

size_t n;

void solve(void)
{
    legit(n);
    size_t tmp = n;
    size_t sum = 0;
    while (tmp != 0)
    {
        sum += tmp % 10;
        tmp /= 10;
    }
    printf(n % sum == 0 ? "Yes\n" : "No\n");
}