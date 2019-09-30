#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <queue>

#define fr first
#define sc second
#define mk make_pair

using namespace std;

int n, m, color[100001], t[100001], dis[100001];
bool u[100001];
vector<int> vec[100001];
pair<int, int> ar[100001];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
        scanf("%d%d%d", &ar[i].fr, &ar[i].sc, &t[i]);

    int v, d, col;
    queue <int> a, b, c;
    for(int i = q - 1; i >= 0; i--)
    {
        a.push(ar[i].fr);
        u[ar[i].fr] = 1;
        b.push(ar[i].sc);
        c.push(t[i]);
        while(!a.empty())
        {
            v = a.front(), d = b.front(), col = c.front();
           // cout << v << " " << d << " " << col << endl;
            u[v] = 0;
            a.pop();
            b.pop();
            c.pop();
            if(color[v] == 0 || dis[v] < d)
            {
                if(color[v] == 0)
                {
                    color[v] = col;
                    dis[v] = d;
                }else
                {
                    dis[v] = d;
                }
                if(d > 0)
                for(int i = 0; i < vec[v].size(); i++)
                {
                    if(color[vec[v][i]] == 0 || dis[vec[v][i]] < d - 1 && u[vec[v][i]] == 0)
                    {
                        u[vec[v][i]] = 1;
                        a.push(vec[v][i]);
                        b.push(d - 1);
                        c.push(col);
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        //cout << color[i] << endl;
        printf("%d\n", color[i]);
    }
    return 0;
} ./Main.cpp:78:72: warning: '&&' within '||' [-Wlogical-op-parentheses]
                    if(color[vec[v][i]] == 0 || dis[vec[v][i]] < d - 1 && u[vec[v][i]] == 0)
                                             ~~ ~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~
./Main.cpp:78:72: note: place parentheses around the '&&' expression to silence this warning
                    if(color[vec[v][i]] == 0 || dis[vec[v][i]] < d - 1 && u[vec[v][i]] == 0)
                                                                       ^
                                                (                                          )
1 warning generated.