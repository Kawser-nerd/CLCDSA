#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
LL vis[200001];
char s[200010];
int main() {
	scanf("%s",s);
	int len=strlen(s);
	for (int i=0;i<len;i++) vis[s[i]-97]++;
	LL ans=0;
	for (int i=0;i<26;i++)
		ans+=vis[i]*(len-vis[i]);
	ans/=2;
	ans++;
	printf("%lld\n",ans);
	return 0;
}