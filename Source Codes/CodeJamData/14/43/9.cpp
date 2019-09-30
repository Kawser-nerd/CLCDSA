#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
#include <cassert>
using namespace std;

int X0[1000], Y0[1000], X1[1000], Y1[1000];

int SS, TT;
int dist[1002][1002];

bool ord(int a, int b, int c)
{
    return a<=b && b<=c;
}

int D(int a, int b, int c, int d)
{
    if(ord(a, c, b) || ord(a, d, b) || ord(c, a, d) || ord(c, b, d))
        return 0;
    assert(b<c || a>d);
    if(b<c) return c-b;
    return a-d;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int W, H, B;
        scanf("%d%d%d", &W, &H, &B);
        SS=B;
        TT=B+1;
        for(int i=0; i<B; i++)
        {
            scanf("%d%d%d%d", X0+i, Y0+i, X1+i, Y1+i);
            X1[i]++;
            Y1[i]++;
            dist[SS][i]=X0[i];
            dist[i][TT]=W-X1[i];
        }
        dist[SS][TT]=W;
        for(int i=0; i<B; i++)
        for(int j=0; j<B; j++)
        {
            if(i==j){ dist[i][j]=0; continue; }
            int &d=dist[i][j];
            d=W;
            int dx=D(X0[i], X1[i], X0[j], X1[j]);
            int dy=D(Y0[i], Y1[i], Y0[j], Y1[j]);
            d=max(dx, dy);
        }
        int cost[1002];
        for(int i=0; i<1002; i++)
            cost[i]=W+1;
        cost[SS]=0;
        priority_queue<pair<int, int>> q;
        q.push(make_pair(0, SS));
        while(!q.empty())
        {
            int at=q.top().second;
            int c=-q.top().first;
            q.pop();
            if(cost[at]!=c)
                continue;
            if(at==TT)
                break;
            for(int i=0; i<B+2; i++)
            {
                int nc=c+dist[at][i];
                if(nc<cost[i])
                {
                    cost[i]=nc;
                    q.push(make_pair(-nc, i));
                }
            }
        }
        printf("Case #%d: %d\n", t, cost[TT]);
    }
    return 0;
}
