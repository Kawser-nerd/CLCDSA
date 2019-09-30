#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 55;

ld p[maxn];
ld ans[maxn];
ld U;
int n, k;

ld getneed(int stfrom, ld th)
{
    ld need = 0;
    for (int i = stfrom; i < n; i++) need += max((ld)0, th - p[i]);
    return need;
}

ld get(int stfrom, ld th)
{
    for (int i = 0; i <= n; i++) ans[i] = 0;
    ans[0] = 1;
    ld sum = 0;
    for (int i = 0; i < n; i++)
    {
        ld curp = p[i];
        if (i >= stfrom) curp = max(curp, th);
        sum += curp - p[i];
        for (int j = n; j > 0; j--) ans[j] = ans[j] * (1 - curp) + curp * ans[j - 1];
        ans[0] *= (1 - curp);
    }
    assert(sum <= U);
    return accumulate(ans + k, ans + n + 1, (ld)0);
}

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d: ", T);
        
        scanf("%d%d", &n, &k);
        double dU;
        scanf("%lf", &dU);
        U = dU;
        for (int i = 0; i < n; i++)
        {
            double x;
            scanf("%lf", &x);
            p[i] = x;
        }
        sort(p, p + n);
        ld answer = 0;
        for (int i = 0; i < n; i++)
        {
            ld l = 0;
            ld r = 1;
            for (int IT = 0; IT < 100; IT++)
            {
                ld m = (l + r) / 2;
                if (getneed(i, m) <= U) l = m;
                else r = m;
            }
            ld used = getneed(i, l);
            ld old_pim1;
            if (i > 0)
            {
                old_pim1 = p[i - 1];
                p[i - 1] = min((ld)1, p[i - 1] + U - used);
            }
            answer = max(answer, get(i, l));
            if (i > 0)
            {
                p[i - 1] = old_pim1;
            }
        }
        printf("%.20f\n", (double)answer);

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
