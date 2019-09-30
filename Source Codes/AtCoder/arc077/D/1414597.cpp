#include<iostream>
#include<vector>
using namespace std;
typedef long long int64;
struct Hash
{
	int n;
	static const int64 moda=1000000007ll,modb=2147483647ll;
	vector<int64> a,b,p,q;
	Hash(const string &s):n(s.size()),a(n+1,0),b(n+1,0),p(n+1,1),q(n+1,1)
	{
		for(int i=0;i<n;i++)
		{
			a[i+1]=(a[i]*17+s[i])%moda;
			b[i+1]=(b[i]*19+s[i])%modb;
			p[i+1]=p[i]*17%moda;
			q[i+1]=q[i]*19%modb;
		}
	}
	pair<int64,int64> query(int l,int r){return make_pair((p[r-l]*a[l]-a[r]+moda)%moda,(q[r-l]*b[l]-b[r]+modb)%modb);}
};
int64 cnt[300000][33];
vector<int64> add(vector<int64> a,vector<int64> b)
{
	for(int i=0;i<26;i++)a[i]+=b[i];
	return a;
}
pair<vector<int64>,int64> f(int64 n,int64 l,vector<int64> left,int64 r,vector<int64> right)
{
	vector<int64> ans(26);
	if(l+r<=n)
	{
		int64 tot=l+r;
		vector<int64> sum=add(left,right);
		auto x=f(n,tot,sum,l,left);
		ans=add(ans,x.first);
		n=x.second;
	}
	if(l<=n)
	{
		ans=add(ans,left);
		n-=l;
	}
	return make_pair(ans,n);
}
int main()
{
	string s;
	int64 l,r,k=0;
	cin>>s>>l>>r;
	s=s.substr(0,s.size()>>1);l--;
	int64 n=s.size();
	Hash h(s);
	for(int i=0;i<n;i++)
		if(h.query(0,i)==h.query(n-i,n))k=i;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<26;j++)cnt[i+1][j]=cnt[i][j];
		cnt[i+1][s[i]-'a']++;
	}
	if(!k)
	{
		for(int i=0;i<26;i++)
		{
			cout<<cnt[n][i]*(r/n)+cnt[r%n][i]-cnt[n][i]*(l/n)-cnt[l%n][i];
			if(i==25)cout<<endl;
			else cout<<' ';
		}
		return 0;
	}
	vector<int64> left(26,0),right(26,0);
	for(int i=0;i<26;i++)
	{
		left[i]=cnt[n-k][i];
		right[i]=cnt[n][i]-cnt[n-k][i];
	}
	auto lower=f(l,n-k,left,k,right),upper=f(r,n-k,left,k,right);
	for(int i=0;i<26;i++)
	{
		cout<<upper.first[i]+cnt[upper.second][i]-lower.first[i]-cnt[lower.second][i];
		if(i==25)cout<<endl;
		else cout<<' ';
	}
	return 0;
}