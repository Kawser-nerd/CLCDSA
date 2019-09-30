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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,c;cin>>n>>c;
    int t;cin>>t;
    int s=t,en=t+c;
    ll ans=0;
    for(int i=0;i<n-1;++i)
    {
        cin>>t;
        if(t>en)
        {
            ans+=en-s;
            s=t;en=s+c;
        }
        else
        {
            en=t+c;
        }
    }
    cout<<ans+en-s<<'\n';
}