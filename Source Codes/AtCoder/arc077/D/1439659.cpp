#include<cstdio>
#include<cstring>
#include<valarray>
using namespace std;
pair<valarray<long long>,long long> f(long long n,long long l,const valarray<long long> &left,long long r,const valarray<long long> &right)
{
	valarray<long long> ans(26);
	if(l+r<=n)
	{
		auto x=f(n,l+r,left+right,l,left);
		ans+=x.first;
		n=x.second;
	}
	if(l<=n)ans+=left,n-=l;
	return make_pair(ans,n);
}
char s[300000];
long long cnt[300000][30],z[300000],n;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1)>>1;
	z[1]=n;
	long long l=1,r=1;
	for(long long i=2;i<=n;i++)
		if(i>r)
		{
			z[i]=0;
			while(z[i]+i<=n&&s[z[i]+i]==s[z[i]+1])z[i]++;
			if(z[i])l=i,r=i+z[i]-1;
		}
		else if(z[i-l+1]<r-i+1)z[i]=z[i-l+1];
		else
		{
			z[i]=r-i+1;
			while(z[i]+i<=n&&s[z[i]+i]==s[z[i]+1])z[i]++;
			l=i,r=i+z[i]-1;
		}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<26;j++)cnt[i][j]=cnt[i-1][j];
		cnt[i][s[i]-'a']++;
	}
	long long k=0;
	for(long long i=n;i>1;i--)
		if(z[i]+i-1==n)k=z[i];
	scanf("%lld%lld",&l,&r);l--;
	if(!k)
	{
		for(long long i=0;i<26;i++)printf("%lld ",cnt[n][i]*(r/n)+cnt[r%n][i]-cnt[n][i]*(l/n)-cnt[l%n][i]);
		putchar('\n');
		return 0;
	}
	valarray<long long> left(26),right(26);
	for(long long i=0;i<26;i++)
	{
		left[i]=cnt[n-k][i];
		right[i]=cnt[n][i]-cnt[n-k][i];
	}
	auto lower=f(l,n-k,left,k,right),upper=f(r,n-k,left,k,right);
	for(long long i=0;i<26;i++)printf("%lld ",upper.first[i]-lower.first[i]+cnt[upper.second][i]-cnt[lower.second][i]);
	putchar('\n');
	return 0;
}