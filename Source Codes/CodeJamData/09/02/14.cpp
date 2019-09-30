#include<string>
#include<iostream>
#include<sstream>
#include<assert.h>
#include<cstdio>
#include<map>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<queue>
#include<functional>
#include<set>

using namespace std;

//=========================================================
// program:
//
int W,H;
int height[100][100];
int sink[100][100];
int sinkn = 0;
int dx[4] = { 0,-1,1,0};
int dy[4] = {-1, 0,0,1};

int dfs(int x, int y)
{
    int & res = sink[x][y];
    if(res != -1) return res;
    
    int bestd,best = 5;
    
    for (int r=0; r<4; r++)
    {
        int nx = x+dx[r], ny=y+dy[r];
        if( (nx<0) || (ny<0) || (nx>=W) || (ny>=H) || (height[nx][ny]>=height[x][y]) )
            continue;
        if ( (best==5) || (bestd > height[nx][ny] ) )
        {
            best = r;
            bestd = height[nx][ny];
        }
    }
    if(best==5)
        res= sinkn++;
    else
        res = dfs( x+dx[best], y+dy[best] );
    
    return res;
}

void solve()
{
    sinkn = 0;
    memset(sink,-1,sizeof(sink));
    for (int x=W; x--;)
        for (int y=H; y--;)
            dfs(x,y);
    assert(sinkn<=26);
    map<int, char> assigned;
    char let='a';
    for (int y=0; y<H; y++)
    {
        for (int x=0; x<W; x++)
        {
            if(x) cout<<" ";
            int d = sink[x][y];
            if(assigned.count(d)) cout<<assigned[d];
            else
            {
                assigned[d] = let;
                cout<<let;
                let++;
            }
        }
        cout<<endl;
    }
        
    
}

inline void init(){}
//=========================================================
// I/O:
//
int main()
{
    init();
    int T; cin>>T;
    for (int i=1;i<=T;i++)
    {
        cin>>H>>W;
        for (int y=0; y<H; y++)
            for (int x=0; x<W; x++)
                cin>>height[x][y];
                
        cerr<<"["<<i<<" / "<<T<<"]"<<endl;
        cout<<"Case #"<<i<<":"   << endl;
        solve();
        
    }
    return 0;
}
