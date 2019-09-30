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

int n,t,bff[1111],ans,vst[1111],cur,nex,inde[1111],ind;

void solve(int x)
{
    reset(vst,0);
    cur=x;
    vst[cur]=1;
    while(1)
    {
        nex=bff[cur];
        if(vst[nex])
        {
            ans=max(ans,vst[cur]-vst[nex]+1);
            if(vst[cur]==1+vst[nex])
            {
                inde[nex]=max(inde[nex],vst[nex]);
                inde[cur]=max(inde[cur],1);
            }
            return;
        }
        vst[nex]=1+vst[cur];
        cur=nex;
    }
}

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    For(cas,1,1+t)
    {
        cout<<"Case #"<<cas<<": ";
        cin>>n;
        For(i,0,n)
        {
            cin>>bff[i];
            bff[i]--;
        }
        reset(inde,0);
        ans=0;
        ind=0;
        For(i,0,n) solve(i);
        For(i,0,n) ind+=inde[i];
        //For(i,0,n) cout<<i<<' '<<inde[i]<<endl;
        cout<<max(ans,ind)<<endl;
    }
}
