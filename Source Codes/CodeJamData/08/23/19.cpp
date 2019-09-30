#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cctype>

#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v.size()))

using namespace std;

typedef long long int64;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<string> vs;

template<class T> T abs(T x){return x>0 ? x:(-x);}
template<class T> T sqr(T x){return x*x;}


const int maxn =2000000;


typedef int T;

struct segment_tree{
	T t[4*maxn];
	int h;
	segment_tree()
	{
		h=1;
		while(h<=maxn) h*=2;
	}
	inline T segment_tree_operation(T t1, T t2)
	{
		return t1+t2;
	}
	T& operator[](int x)
	{
		return t[x];
	}
	void build_tree()
	{
		for(int i=h-1;i>=1;i--)
			t[i]=segment_tree_operation(t[2*i],t[2*i+1]);
	}
	void set(int x,T a)
	{
		x=x+h-1;
		t[x]=a;
		x/=2;
		while(x>0)
			t[x]=segment_tree_operation(t[2*x],t[2*x+1]),x/=2;
	}
	T get(int x,int y)
	{
		x=x+h-1,y=y+h-1;
		if(x==y) return t[x];
		if(x>y) return 0;
		T ax=t[x],ay=t[y];
		while(y-x>1){
			if(x%2==0)
				ax=segment_tree_operation(ax,t[x+1]);
			if(y%2==1)
				ay=segment_tree_operation(ay,t[y-1]);
			x/=2,y/=2;
		}
		return segment_tree_operation(ax,ay);
	}

	int Next(int v,int p,int c)
	{
		if(p==1) return v-h+1;
		if(c<t[2*v])
			return Next(2*v,p/2,c);
		else
			return Next(2*v+1,p/2,c-t[2*v]);
	}

	int next(int x,int c)
	{
		if(c==0) return x;
		int cur=x+h-1;
		int p=1;
		c--;
		while(cur>1)
		{
			if(cur%2==0)
			{
				if(c>=t[cur+1])
					c-=t[cur+1];
				else 
					return Next(cur+1,p,c);
			}
			cur/=2;
			p*=2;
		}
		throw 57;
	}
};

segment_tree t;

int main()
{
	int tc;
	cin >> tc;
	for(int ic=0;ic<tc;ic++)
	{
		vi d;
		int k,n;
		cin >> k >> n;
		for(int i=0;i<n;i++)
		{
			int x;
			cin >> x;
			d.push_back(x);
		}
		vi res(k,-1);
		for(int i=0;i<k;i++)
			t.set(i+1,1);
		int cur=0;
		for(int i=0;i<k;i++)
		{
			int tmp=i+1;
			if(i==0) tmp=0;
			if(tmp>0) tmp=(tmp-1)%t.get(1,k)+1;
			int next;
			int mn=t.get(cur+1,k);
			if(tmp<=mn)
			{
				next=t.next(cur+1,tmp)-1;
			}
			else
			{
				tmp-=mn;
				next=t.next(1,tmp)-1;
			}
			res[next]=i+1;
			t.set(next+1,0);
			cur=next;
		}
		printf("Case #%d: ",ic+1);
		for(int i=0;i<sz(d);i++)
			printf("%d ",res[d[i]-1]);
		printf("\n");
	}
	return 0;
}
