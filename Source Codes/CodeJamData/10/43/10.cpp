#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

vector<int> x1,x2,y1,y2;
bool isin(int x,int y,int i)
{
    return x>=x1[i] && x<=x2[i] && y>=y1[i] && y<=y2[i];
}
int tst()
{
    int r;
    cin >> r;
    x1.resize(r);
    x2.resize(r);
    y1.resize(r);
    y2.resize(r);

    for(int i=0;i<r;i++)
    {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x2[i]++;
        y2[i]++;
    }

    vector<vector<int> > G(r);

    for(int i=0;i<r;i++)
        for(int j=0;j<i;j++)
            if(make_pair(x1[i],y1[i])!=make_pair(x2[j],y2[j])
            && make_pair(x1[j],y1[j])!=make_pair(x2[i],y2[i]))
                if(min(x2[i],x2[j])>=max(x1[i],x1[j])
                && min(y2[i],y2[j])>=max(y1[i],y1[j]))
                {
                    G[i].push_back(j);
                    G[j].push_back(i);
//                    cout << "e " << i << ' ' << j << endl;
                }
    vector<int> g(r,-1);

    int c=0;
    for(int i=0;i<r;i++)
    {
        if(g[i]>=0)
            continue;
        g[i]=c;
//        cout << " v " << i << " : " << c << endl;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            for(int j=0;j<G[v].size();j++)
            {
                int u = G[v][j];
                if(g[u]==-1)
                {
                    g[u] = c;
                    q.push(u);
//        cout << " pv " << u << " : " << c << endl;
                }
            }
        }
        c++;
    }
    vector<int> maxx(r,-1000000000);
    vector<int> maxy(r,-1000000000);
    for(int i=0;i<r;i++)
    {
        maxx[g[i]] = max(maxx[g[i]],x2[i]);
        maxy[g[i]] = max(maxy[g[i]],y2[i]);
    }
    int ans = 0;
    for(int i=0;i<r;i++)
    {
//        cout << x1[i] << ' ' << y1[i] << ' ' << maxx[g[i]] << ' ' << maxy[g[i]] << endl;
        ans = max(ans, maxx[g[i]]-x1[i] + maxy[g[i]]-y1[i]-1);
    }
    return ans;


}

int main()
{
    int t;
    cin >> t;
    for(int tt=1;tt<=t;tt++)
        cout << "Case #" << tt << ": " << tst() << endl;
}
