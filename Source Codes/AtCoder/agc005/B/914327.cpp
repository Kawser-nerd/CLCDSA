#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#define pb push_back
#define mkp make_pair
using namespace std;

const int maxn = 200005;
typedef long long ll;

int n;
int da[maxn];
int st[maxn],top;
int tl[maxn],tr[maxn];

ll f(int l,int r)
{
    return (ll)(l+1)*(r+1);
}
int main()
{
    ll res = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",da+i);
    top = 0;
    for(int i=1;i<=n;i++)
    {
        while(top&&da[i]<da[st[top]])
            top--;
        tl[i] = (top?st[top]+1:1);
        st[++top] = i;
    }
    top = 0;
    for(int i=n;i>=1;i--)
    {
        while(top&&da[i]<da[st[top]])
            top--;
        tr[i] = (top?st[top]-1:n);
        st[++top] = i;
    }
    for(int i=1;i<=n;i++)
        res += da[i]*f(i-tl[i],tr[i]-i);
    printf("%lld\n",res);

}