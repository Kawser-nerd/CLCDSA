#include<iostream>
using namespace std;
int t,cases,a1,b1,a2,b2;
long long ans;
int check(int a,int b)
{
    if (a<b) swap(a,b);
    if (a==b) return 0;
    if (a>=2*b) return 1;
    return 1-check(b,a-b);
}

int calc(int l,int r)
{
    if (l>r) return 0;
    if (b2<l) return 0;
    if (b1>r) return 0;
    if ((b1>=l)&&(b2<=r)) return b2-b1+1;
    if ((b1<=l)&&(b2>=r)) return r-l+1;
    if (b1<l) return b2-l+1;
    return r-b1+1;
}

void solve()
{
     int i,j,l,r;
     ans=0;
     l=0;
     r=0;
     for (i=1;i<=a2;i++)
     {
         if (i>1)
         if (check(i,l+1)) l++;
         else r++;
         if (i>=a1) ans+=calc(1,l)+calc(2*i-r,2*i-1)+calc(2*i,1000000);
     }
     printf("Case #%d: %lld\n",t+1,ans);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for (t=0,scanf("%d",&cases);t<cases;t++)
    {
        scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
        solve();
    }
}
