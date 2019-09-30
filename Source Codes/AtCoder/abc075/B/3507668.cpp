#include<iostream>//???
using namespace std;
int n,m,dir[8][2]={{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,-1},{1,1},{-1,1}};//8???
char mp[101][101];
void dfs()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int num=0;
            if(mp[i][j]=='#')cout<<'#';
            if(mp[i][j]=='.')
            {
                for(int k=0;k<8;k++)
                {
                    int x0=i+dir[k][0];
                    int y0=j+dir[k][1];
                    if(mp[x0][y0]=='#')num++;
                }
            cout<<num;
            }

        }
        cout<<endl;
    }

}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mp[i][j];
    dfs();
    return 0;
}