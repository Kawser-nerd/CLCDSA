#include<iostream>
using namespace std;
long long i,n,ans;
int main()
{
    while(cin>>n&&n)
    {
        ans=1;

    for(i=1;i<=n;i++)
    {
        ans=(ans*i)%1000000007;
        //if(ans>1000000007){
        //    cout<<"#############"<<i<<endl;
        //cout<<i<<" "<<ans%1000000007<<endl;
        //}
       // else


    }cout<<ans<<endl;

    }

}