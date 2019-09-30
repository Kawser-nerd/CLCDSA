#include<string>
#include<stdio.h>
#include<climits>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node{
    char x;
    ll y;
};
struct node ai[100005],bi[100005];
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    ll n,m; cin>>n>>m;
    string a,b; cin>>a>>b;
    ai[0].y = 1; ai[0].x = a[0];
    bi[0].y = 1; bi[0].x = b[0];
    for(ll i=1;i<n;i++)
    {
        ll t = m*i + 1;
        ai[i].y = t; ai[i].x = a[i];
    }
    for(ll i=1;i<m;i++)
    {
        ll t = n*i + 1;
        bi[i].y = t; bi[i].x = b[i];
    }
    int flag = 0;
    if(n<=m){
        for(ll i=0;i<n;i++)
        {
            ll q = ai[i].y; char w = ai[i].x;
           // printf("%d %c%c\n",q,w);
            for(ll j=i;j<m;j++){
                if(bi[j].y<=q)
                {
                    if(bi[j].y==q&&bi[j].x!=w)
                    {
                        flag = 1;
                        break;
                    }
                }
                else {
                    break;
                }
            }
            if(flag == 1)
                break;
        }
    }
    else {
        for(ll i=0;i<m;i++)
        {
            ll q = bi[i].y; char w = bi[i].x;
           // printf("%d %c%c\n",q,w);
            for(ll j=i;j<n;j++){
                if(ai[j].y<=q)
                {
                    if(ai[j].y==q&&ai[j].x!=w)
                    {
                        flag = 1;
                        break;
                    }
                }
                else {
                    break;
                }
            }
            if(flag == 1)
                break;
        }

    }
    if(flag==1){
        printf("-1\n");
    }
    else {
        printf("%lld\n",n*m/gcd(n,m));
    }
    return 0;
}