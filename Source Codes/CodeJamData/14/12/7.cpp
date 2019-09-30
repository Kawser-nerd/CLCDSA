#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout << #a << ": " << (a) << endl;
typedef long long ll;
typedef pair<int, int> pii;
#define MP make_pair
#define A first
#define B second

const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
int N;
vector<int> adj[MAXN];

int ssize[MAXN];
int subtree_size(int at, int fr)
{
    int &ans = ssize[at];
    if (ans != -1) return ans;
    ans = 1;
    for (int i=0; i<adj[at].size(); i++) if (adj[at][i] != fr)
        ans += subtree_size(adj[at][i], at);
    return ans;
}

int solve(int at, int fr)
{
    if (adj[at].size() == 0) return 0;
    if (adj[at].size() == 1 && fr != -1) return 0;
    if ((adj[at].size() == 2 && fr != -1) || adj[at].size() == 1)
    {
        int ans = -INF;
        for (int i=0; i<adj[at].size(); i++) if (adj[at][i] != fr)
            ans = subtree_size(adj[at][i], at);
        return ans;
    }

    int ans = 0;
    int m1 = 0, m2 = 0;

    for (int i=0; i<adj[at].size(); i++) if (adj[at][i] != fr)
    {
        int s = subtree_size(adj[at][i], at);
        ans += s;
        int cur = s-solve(adj[at][i], at);
        if (cur > m2)
            m2 = cur;
        if (m2 > m1)
            swap(m2, m1);
    }
    //cout << at << ' ' << fr << ' ' << ans << ' ' << m1 << ' ' << m2 << endl;
    return ans-m1-m2;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int kase=1; kase<=t; kase++)
    {
        cout << "Case #" << kase << ": ";
        for (int i=0; i<MAXN; i++)
            adj[i].clear();
        cin >> N;
        for (int i=1; i<N; i++)
        {
            int x, y; cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int ans = INF;
        for (int i=0; i<N; i++)
        {
            memset(ssize, -1, sizeof(ssize));
            ans = min(ans, solve(i, -1));
        }
        cout << ans << '\n';
    }
    return 0;
}
