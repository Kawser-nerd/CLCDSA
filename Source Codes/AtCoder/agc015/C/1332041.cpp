#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
#include"set"
#include"unordered_set"
#include"map"
#include"unordered_map"
#include"string"
#include"cstring"
#include"iomanip"
using namespace std;
typedef long long ll;
const int maxn=2010;
bool rec[maxn][maxn];
int h[maxn][maxn],v[maxn][maxn],b[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;cin>>n>>m>>q;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            char ch;cin>>ch;
            if(ch=='1')
                rec[i][j]=1;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            v[i][j]=v[i-1][j];
            h[i][j]=h[i][j-1];
            b[i][j]=b[i-1][j];
            if(rec[i][j])
            {
                if(rec[i-1][j])
                    v[i][j]++;
                if(rec[i][j-1])
                    h[i][j]++;
                b[i][j]++;
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            v[i][j]+=v[i][j-1];
            h[i][j]+=h[i-1][j];
            b[i][j]+=b[i][j-1];
        }
    }
    /*
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cout<<h[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    while(q--)
    {
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        int node=b[x2][y2]+b[x1-1][y1-1]    -        b[x2][y1-1]-b[x1-1][y2];
        int edge=v[x2][y2]+v[x1][y1-1]+h[x2][y2]+h[x1-1][y1]-v[x2][y1-1]-v[x1][y2]-h[x1-1][y2]-h[x2][y1];  
        cout<<node-edge<<'\n';
    }
}