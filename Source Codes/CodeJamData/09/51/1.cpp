#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;


typedef vector< pair<int,int> > VP;
#define MP make_pair
#define PB push_back

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const int maxn = 12 + 3;
const int qsize = 5000000 + 10;

VP st,en,cur;

char g[maxn][maxn];

int n,m;

string tmp;
set<VP> hash;
VP q[qsize];
int qd[qsize];
int l,r;

inline void insert( const VP &a,int D )
{
	if( hash.find(a)==hash.end() )
	{
		hash.insert(a);
		q[++r] = a;
		if( r>=qsize )
		{
			cout<<"ERROR-------------------------"<<endl;
		}
		qd[r] = D;
	}
}

int ihash[maxn][maxn],hid;
int qhash[maxn][maxn],hqd;
int num[maxn][maxn];

int sx[100],sy[100],sl,sr;
bool inq[100];

inline void Dinsert( int x,int y )
{
	if( ihash[x][y]==hid && !inq[ num[x][y] ] )
	{
		sr++;
		sx[sr] = x;
		sy[sr] = y;
		inq[ num[x][y] ] = true;
	}
}
bool ndanger( const VP &a )
{
	hid++;
	sl = sr = 0;
	for(int i=0;i<a.size();i++)
	{
		ihash[ a[i].first ][ a[i].second ] = hid;
		num[ a[i].first ][ a[i].second ] = i;
		inq[i] = false;
	}

	Dinsert( a[0].first,a[0].second );
	while( sl < sr )
	{
		sl++;
		for(int k=0;k<4;k++) Dinsert( sx[sl]+dx[k],sy[sl]+dy[k] );
	}
	return sr == a.size();
}


int solve()
{
	hash.clear();
	l = 0;
	r = 0;
	insert(st,0);
	bool now;
	while( l<r )
	{
		st = q[++l];
		if( st==en ) return qd[l];

//		for(int i=0;i<st.size();i++) cout<<"("<<st[i].first<<","<<st[i].second<<") ";
//		cout<<endl;

		now = ndanger(st);
		hqd++;
		for(int i=0;i<st.size();i++)
			qhash[ st[i].first ][ st[i].second ] = hqd;
		for(int i=0;i<st.size();i++)
		for(int j=0;j<4;j++) if( g[ st[i].first+dx[j] ][ st[i].second+dy[j] ]!='#' && qhash[ st[i].first+dx[j] ][ st[i].second+dy[j] ]!=hqd && qhash[ st[i].first-dx[j] ][ st[i].second-dy[j] ]!=hqd && g[ st[i].first-dx[j] ][ st[i].second-dy[j] ]!='#'  )
		{
			cur = st;
			cur[i].first+=dx[j];
			cur[i].second+=dy[j];
			sort( cur.begin(),cur.end() );
			if( now || ndanger(cur) ) insert(cur,qd[l]+1);
		}
	}

	return -1;
}
int main()
{
	int T;
	cin>>T;
	for(int num=1;num<=T;num++)
	{
		cin>>n>>m;
		st.clear();en.clear();
		for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++) g[i][j] = '#';
		for(int i=1;i<=n;i++)
		{
			cin>>tmp;
			for(int j=1;j<=m;j++)
			{
				g[i][j] = tmp[j-1];
				if( g[i][j]=='o' || g[i][j]=='w' )
					st.PB(MP(i,j));
				if( g[i][j]=='x' || g[i][j]=='w' )
					en.PB(MP(i,j));
			}
		}
		sort(st.begin(),st.end());
		sort(en.begin(),en.end());
		cout<<"Case #"<<num<<": "<<solve()<<endl;
	}
	return 0;
}
