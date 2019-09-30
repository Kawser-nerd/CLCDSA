#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;

const int inf=1e9;
int mini,n,cnt,xx;
int main()
{
	mini=inf;
	cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>xx;
        cnt=cnt+xx;
        if(xx%10!=0&&xx<mini)
            mini=xx;
    }
    if(cnt%10!=0)
		cout<<cnt<<endl;
    else if(mini==inf)
		cout<<0<<endl;
    else cout<<cnt-mini;
    return 0;
}