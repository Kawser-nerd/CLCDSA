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

const int maxn = 1005;

pair2<int> pc[maxn];
int n, k;

inline ld getside(const pair2<int> pancake)
{
    return 2 * M_PI * pancake.fi * pancake.se;
}

inline bool cmpside(const pair2<int> a, const pair2<int> b)
{
    return getside(a) > getside(b);
}

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d: ", T);
        
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &pc[i].fi, &pc[i].se);
        }
        sort(pc, pc + n);
        ld answer = 0;
        for (int i = k - 1; i < n; i++)
        {
            sort(pc, pc + i, cmpside);
            ld curans = M_PI * pc[i].fi * pc[i].fi + getside(pc[i]);
            for (int j = 0; j < k - 1; j++) curans += getside(pc[j]);
            answer = max(answer, curans);
        }
        printf("%.20f\n", (double)answer);

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
