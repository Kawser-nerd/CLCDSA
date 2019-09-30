#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=int(2e5+5);
typedef long long LL;
LL f[MAXN];
char s[MAXN];
int main()
{
	scanf("%s",s+1);
	LL ans=0,n=strlen(s+1);
	for(LL i=n;i>=1;i--) {
		f[i]=f[i+1];
		if(s[i]=='W')
			f[i]+=1;
	}
	for(LL i=1;i<=n;i++)
		if(s[i]=='B') ans+=f[i];
	printf("%lld",ans);
}