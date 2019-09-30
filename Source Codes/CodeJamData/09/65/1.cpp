#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int maxn = 100;


string color[maxn];
bool vis[maxn];
int l[maxn],r[maxn];
int n,tot;

int con[maxn];
int ans;

int ty[maxn];

int stack[maxn],top,mt;
int f( int t )
{
	mt = 0;top = 0;
	stack[0] = 100000;
	for(int i=0;i<tot;i++) if( ty[i]==t )
	{
		while( stack[top]<r[i] ) top--;
		stack[++top] = r[i];
		if( top>mt ) mt = top;
	}
	return mt;
}
void dfs( int dep,int s0,int s1 )
{
	if( dep==tot ) ans = min( ans,f(1)+f(2) );else
	{
		if( (s0&con[dep])==0 )
		{
			ty[dep] = 1;
			dfs( dep+1,s0+(1<<dep),s1 );
		}
		if( (s1&con[dep])==0 )
		{
			ty[dep] = 2;
			dfs( dep+1,s0,s1+(1<<dep) );
		}
	}
}
int main()
{
	int T;
	cin>>T;
	for(int num=1;num<=T;num++)
	{
		cin>>n;
		n = n*2;

		for(int i=0;i<n;i++)
			cin>>color[i];
		tot = 0;

		for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++) if(color[i]==color[j])
		{
			l[tot] = i;
			r[tot] = j;
			tot++;
		}


		for(int i=0;i<tot;i++) con[i] = 0;
		for(int i=0;i<tot;i++)
		for(int j=i+1;j<tot;j++) if( l[j]<r[i] && r[j]>r[i] )
		{
			con[i]+= (1<<j);
			con[j]+= (1<<i);
		}

		ans = 100000;
		dfs( 0,0,0 );
		cout<<"Case #"<<num<<": ";
		if( ans==100000 ) cout<<"-1"<<endl;else
			cout<<ans<<endl;
	}
	return 0;
}
