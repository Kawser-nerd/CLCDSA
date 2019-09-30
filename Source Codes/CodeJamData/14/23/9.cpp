#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <fstream>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define y0 gfdssdfer
#define y1 wetgwervbwqr

typedef long long Int;

const int INF = 1000000000;
const int MOD = 1000000007;

vector<int> zip;
vector<int> g[55];
int A[55][55];
bool used[55];
bool us[55];

void dfs(int v)
{
    used[v] = 1;
    FOR(i,0,g[v].size())
        if (!used[g[v][i]])
            dfs(g[v][i]);
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);

    int t;
    cin >> t;
    FOR(ttt,0,t)
    {
        printf("Case #%d: " , ttt + 1);
        int n,m;
        cin >> n >> m;
        zip.clear();
        FILL(A,0);
        FILL(us,0);
        FOR(i,0,n)
        {
                int x;
                cin >> x;
                zip.push_back(x);
        }

        FOR(i,0,55)
        {
            g[i].clear();
        }

        FOR(i,0,m)
        {
            int a, b;
            cin >> a >> b;
            --a;--b;
            g[a].push_back(b);
            g[b].push_back(a);
            A[a][b] = A[b][a] = 1;
        }

        vector<int> res;
        vector<int> path;
        vector<int> dead;

        int M = 100007;
        int v;
        FOR(i,0,n)
        {
            if (zip[i] < M)
            {
                M = zip[i];
                v = i;
            }
        }

        res.push_back(M);
        us[v] = 1;
        path.push_back(v);

        FOR(it,0,n - 1)
        {
            int M = 100007;
            int v;
            FOR(i,0,n)
                if (!us[i])
                {
                    if (zip[i] > M)
                        continue;

                    int id = -1;
                    FOR(j,0,path.size())
                        if (A[path[j]][i])
                        {
                            id = j;
                        }

                    FILL(used,0);
                    FOR(j,0,dead.size())
                        used[dead[j]] = 1;
                    FOR(j,id + 1 , path.size())
                        used[path[j]] = 1;
                    if (id != -1)
                    {
                        dfs(path[id]);
                    }
                    bool ok = 1;
                    FOR(j,0,n)
                        ok &= used[j];

                    if (ok)
                    {
                        v = i;
                        M = zip[i];
                    }

                }
            int id = -1;
            FOR(j,0,path.size())
                if (A[path[j]][v])
                {
                    id = j;
                }
            res.push_back(zip[v]);
            us[v] = 1;
            while (path.size() > id + 1)
            {
                dead.push_back(path.back());
                path.pop_back();
            }
            path.push_back(v);
        }

        FOR(i,0,res.size())
            cout << res[i];
        cout << endl;
    }

    return 0;
}

