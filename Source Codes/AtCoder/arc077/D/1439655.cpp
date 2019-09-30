#include<iostream>
#include<cstring>
#include<valarray>
#define array valarray<long long>
using namespace std;
long long a[200011],b[200011],p[200011]={1},q[200011]={1},moda=1000000007,modb=2147483647,cnt[300000][27];
char s[300000];
pair<long long,long long> query(long long l,long long r){return make_pair((p[r-l]*a[l]-a[r]+moda)%moda,(q[r-l]*b[l]-b[r]+modb)%modb);}
pair<array,long long> f(long long n,long long l,const array &left,long long r,const array &right)
{
	array ans(26);
	if(l+r<=n)
	{
		auto x=f(n,l+r,left+right,l,left);
		ans+=x.first;
		n=x.second;
	}
	if(l<=n)
	{
		ans+=left;
		n-=l;
	}
	return make_pair(ans,n);
}
int main()
{
	long long l,r;
	string s;
	cin>>s>>l>>r;l--;
	s=s.substr(0,s.size()>>1);
	long long n=s.size();
	for(long long i=1;i<=n;i++)
	{
		a[i]=(a[i-1]*17+s[i-1]-'a')%moda;
		b[i]=(b[i-1]*19+s[i-1]-'a')%modb;
		p[i]=p[i-1]*17%moda;
		q[i]=q[i-1]*19%modb;
	}
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<26;j++)cnt[i+1][j]=cnt[i][j];
		cnt[i+1][s[i]-'a']++;
	}
	long long k=0;
	for(long long i=0;i<n;i++)
		if(query(0,i)==query(n-i,n))k=i;
	if(!k)
	{
		for(long long i=0;i<26;i++)cout<<cnt[n][i]*(r/n)-cnt[n][i]*(l/n)+cnt[r%n][i]-cnt[l%n][i]<<' ';
		cout<<endl;
		return 0;
	}
	array left(26),right(26);
	for(long long i=0;i<26;i++)
	{
		left[i]=cnt[n-k][i];
		right[i]=cnt[n][i]-cnt[n-k][i];
	}
	auto lower=f(l,n-k,left,k,right),upper=f(r,n-k,left,k,right);
	for(long long i=0;i<26;i++)cout<<upper.first[i]+cnt[upper.second][i]-lower.first[i]-cnt[lower.second][i]<<' ';
	cout<<endl;
	return 0;
}