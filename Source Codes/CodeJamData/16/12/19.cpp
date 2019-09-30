#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,t,cnt[2555],val;

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    For(cas,1,1+t)
    {
        cout<<"Case #"<<cas<<": ";
        cin>>n;
        reset(cnt,0);
        For(i,0,2*n-1)
        {
            For(j,0,n)
            {
                cin>>val;
                cnt[val]++;
            }
        }
        For(i,1,2555) if(cnt[i]&1) cout<<i<<' ';
        cout<<endl;
    }
}
