#include<iostream>
using namespace std;
long long m,n,ans;
int main()
{
    while(cin>>n>>m&&n)
    {
        if(m>=2*n)
        {
            ans=(m-2*n)/4+n;
        }
        else
        {
            ans=m/2;
        }
        cout<<ans<<endl;

    }

}