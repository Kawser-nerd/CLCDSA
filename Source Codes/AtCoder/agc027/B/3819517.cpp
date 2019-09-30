#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <vector>
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repd(i,x,n) for(int i=x;i<=n;i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define gbtb std::ios::sync_with_stdio(false)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MSC0(X) memset((X), '\0', sizeof((X)))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define gg(x) getInt(&x)
using namespace std;
typedef long long ll;
inline void getInt(int* p);
/*** TEMPLATE CODE STARTS HERE ***/
ll n;
ll ans;
ll x;
ll a[200050];
ll ABS(ll x)
{
	return x>0?x:-1*x;
}
int main()
{
	// freopen("D:\\common_text\\code_stream\\out.txt","w",stdout);
	// freopen("D:\\common_text\\code_stream\\in.txt","r",stdin);
    ans=1e18;
    gbtb;
    cin>>n>>x;
    repd(i,1,n)
    {
    	cin>>a[i];
    	a[i]=a[i]+a[i-1];
    }
    for(int k=1;k<=n;++k)
    {
    	ll sum = 0;
    	ll now = 3;
    	for(int i=n;i>=1;i-=k)
    	{
    		sum+=(a[i]-a[max(0,i-k)])*max(now,5ll);
    		now+=2;
    		if(sum>=ans)
    		{
    			break;
    		}
    	}
    	ans=min(ans,sum+=1ll*(k+n)*x);

    }
    
    cout<<ans<<endl;
    
    return 0;
}

inline void getInt(int* p) {
    char ch;
    do {
        ch = getchar();
    } while (ch == ' ' || ch == '\n');
    if (ch == '-') {
        *p = -(getchar() - '0');
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 - ch + '0';
        }
    }
    else {
        *p = ch - '0';
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 123330 + ch - '0';
        }
    }
}