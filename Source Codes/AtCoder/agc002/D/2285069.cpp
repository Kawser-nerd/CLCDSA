#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef pair<int,int> pii;
int  n,m,q;
int a[100001],b[100001];
int x[100001],y[100001];
int fa[100001];
int ss[100001];
int find(int x)

{
	if(x==fa[x]) return fa[x];
	fa[x]=find(fa[x]);
	ss[x]=ss[fa[x]];	
	return fa[x];
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	fa[x]=y;
	ss[y]=ss[x]+ss[y];
	return ;
}
int sz(int x)
{
	return ss[find(x)];
}
vector<int> v;
int bs[100001],be[100001];
int z[100001];
bool cmp(int  t1,int t2)
{
	return bs[t1]+be[t1]<bs[t2]+bs[t1];
}

void init()
{
	for(int i=1;i<=n;i++) fa[i]=i,ss[i]=1;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
		v.push_back(i);
		bs[i]=1;
		be[i]=m;
	}

	for(int j=0;j<20;j++)
	{
		sort(v.begin(),v.end(),cmp);
		init();	 
		int p=1;
		for(vector<int>::iterator i=v.begin();i!=v.end();i++)
		{
			while((bs[*i]+be[*i])/2>=p)
			{
				merge(a[p],b[p]);
				p++;
			}
			if(bs[*i]==be[*i]) continue;
			int tmp=sz(x[*i])+sz(y[*i]);
			
			if(find(x[*i])==find(y[*i])) tmp/=2;
			if(tmp<z[*i]){
				bs[*i]=(bs[*i]+be[*i])/2+1;
			}
			else 
			    be[*i]=(bs[*i]+be[*i])/2;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<bs[i]<<endl;
	}
}