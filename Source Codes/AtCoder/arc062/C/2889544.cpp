#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const ll N=1005;
int a[N][8];
ll p[4];
map<ll,ll>g;
ll Hash(ll a,ll b,ll c,ll d){
    return (a<<30)|(b<<20)|(c<<10)|d;
}
void Add(ll f,ll v){
    for(int i=0;i<4;i++){
        g[f]+=v;
        f=(f>>10)|((f&(1023))<<30);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            scanf("%d",&a[i][j]);
            a[i][j+4]=a[i][j];
        }
        Add(Hash(a[i][0],a[i][1],a[i][2],a[i][3]),1);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        Add(Hash(a[i][0],a[i][1],a[i][2],a[i][3]),-1);
        for(int j=i+1;j<n;j++){
            Add(Hash(a[j][0],a[j][1],a[j][2],a[j][3]),-1);
            for(int k=0;k<4;k++){
                ll sum=1;
                p[0]=Hash(a[j][k+1],a[j][k+0],a[i][1],a[i][0]);
                p[1]=Hash(a[j][k+0],a[j][k+3],a[i][2],a[i][1]);
                p[2]=Hash(a[j][k+3],a[j][k+2],a[i][3],a[i][2]);
                p[3]=Hash(a[j][k+2],a[j][k+1],a[i][0],a[i][3]);
                if(g[p[0]]&&g[p[1]]&&g[p[2]]&&g[p[3]]){
                    sum*=g[p[0]];
                    Add(p[0],-1);
                    sum*=g[p[1]];
                    Add(p[1],-1);
                    sum*=g[p[2]];
                    Add(p[2],-1);
                    sum*=g[p[3]];
                    //Add(p[3],-1);
                    //Add(p[3],1);
                    Add(p[2],1);
                    Add(p[1],1);
                    Add(p[0],1);
                    ans+=sum;
                }
            }
            Add(Hash(a[j][0],a[j][1],a[j][2],a[j][3]),1);
        }
    }
    printf("%lld\n",ans);
}