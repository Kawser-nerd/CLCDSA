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

const int TIME = 2 * 720;

const int inf = 1e9;

bool can[TIME + 5][2];
int ans[2][TIME + 5][TIME + 5][2];
int n, m;

inline void upd(int &a, int b)
{
    a = min(a, b);
}

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        scanf("%d%d", &n, &m);
        for (int i = 0; i < TIME; i++)
        {
            can[i][0] = true;
            can[i][1] = true;
        }
        for (int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            for (int j = x; j < y; j++) can[j][0] = false;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            for (int j = x; j < y; j++) can[j][1] = false;
        }
        for (int st = 0; st < 2; st++)
        {
            for (int t = 0; t <= TIME; t++)
            {
                for (int nw = 0; nw < 2; nw++)
                {
                    for (int fst = 0; fst <= TIME; fst++) ans[st][t][fst][nw] = inf;
                }
            }
        }
        if (can[0][0]) ans[0][1][1][0] = 0;
        if (can[0][1]) ans[1][1][0][1] = 0;
        int answer = inf;
        for (int st = 0; st < 2; st++)
        {
            for (int t = 1; t < TIME; t++)
            {
                for (int fst = 0; fst <= t; fst++)
                {
                    for (int nw = 0; nw < 2; nw++)
                    {
                        for (int nxt = 0; nxt < 2; nxt++) if (can[t][nxt])
                        {
                            upd(ans[st][t + 1][fst + (nxt == 0)][nxt], ans[st][t][fst][nw] + (nxt != nw));
                        }
                    }
                }
            }
            assert(ans[st][TIME][720][1 - st] == inf || ans[st][TIME][720][st] % 2 == 0);
            assert(ans[st][TIME][720][1 - st] == inf || ans[st][TIME][720][1 - st] % 2 == 1);
            upd(answer, ans[st][TIME][720][st]);
            upd(answer, ans[st][TIME][720][1 - st] + 1);
        }
        printf(" %d\n", answer);
        
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
