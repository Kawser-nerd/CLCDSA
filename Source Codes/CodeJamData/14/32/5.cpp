#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int mod=1000000007;
typedef long long LL;
int n;
int cnt[26],next[26],pre[26];
bool mid[26],vis[26],app[26];
bool all(string s,char c)
{
	for(int i=0;i<s.length();i++)
		if(s[i]!=c) return false;
	return true;
}
LL fact(int n)
{
	if(n==0) return 1LL;
	return fact(n-1)*n%mod;
}
int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		bool havesol=true;
		cin>>n;
		memset(cnt,0,sizeof cnt);
		memset(next,-1,sizeof next);
		memset(pre,-1,sizeof pre);
		memset(mid,0,sizeof mid);
		memset(vis,0,sizeof vis);
		memset(app,0,sizeof app);
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			cnt[s[0]-'a']+=all(s,s[0]);
			for(int i=0;i<s.length();i++)  app[s[i]-'a']=true;
			for(int i=0;i<s.length()-1;i++)
			{
				if(s[i]!=s[0] && s[i]!=s[s.length()-1])
					mid[s[i]-'a']=true;
				if(s[i]!=s[i+1])
					if(next[s[i]-'a']==-1 && pre[s[i+1]-'a']==-1)
					{
						next[s[i]-'a']=s[i+1]-'a';
						pre[s[i+1]-'a']=s[i]-'a';
					}
					else havesol=false;
			}
		}
		for(int i=0;i<26;i++)
			if(mid[i] && cnt[i])
			{
				havesol=false;
				break;
			}
			LL ans=1;
			int nc=0;
		if(havesol)
		{
			for(int i=0;i<26;i++)
			{
				if(app[i] && !vis[i])
				{
					++nc;
					int v;
					for(v=i;!vis[v] && (~pre[v]);vis[v]=true,v=pre[v]);
					if(vis[v])
					{
						havesol=false;
						break;
					}
					for(;~v;v=next[v])
					{
						vis[v]=true;
						ans=(ans*fact(cnt[v]))%mod;
					}
				}
			}
			ans=(ans*fact(nc))%mod;
		}
		if(havesol)
			cout<<"Case #"<<t<<": "<<ans<<endl;
		else cout<<"Case #"<<t<<": "<<0<<endl;
	}
	return 0;
}
