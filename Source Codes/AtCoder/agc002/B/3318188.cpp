#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
 
bool a[100005];
int b[100005];
 
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int i;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=1;i<=n;i++)
            b[i]=1;
        a[1]=1;
        while(m--)
        {
            int x1,x2;
            cin>>x1>>x2;
            if(a[x1]==1&&b[x1]==1)
            {
                a[x1]=0;
                a[x2]=1;
            }
            else if(a[x1]==1)
                a[x2]=1;
            b[x1]--;
            b[x2]++;
        }
        int sum=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]&&b[i]>0)
            {
                sum++;
            }
        }
        cout<<sum<<endl;
    }
}