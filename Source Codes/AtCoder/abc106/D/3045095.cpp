#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[550][550];
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]++;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        a[i][j]+=a[i][j-1];
    while(q--)
    {
        int x,y,sum=0;
        cin>>x>>y;
        for(int i=x;i<=y;i++)
            sum+=a[i][y];
        cout<<sum<<endl;
    }
}