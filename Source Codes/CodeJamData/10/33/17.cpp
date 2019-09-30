
//Written by Alex Hamed Ahmadi (alex@hamedahmadi.com)

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
using namespace std;

#define FOR(i,n) for (int i=0;i<(n);i++)
#define FORIT(it,s) for (__typeof(s.begin()) it=s.begin(); it!=s.end(); ++it)
#define FORITR(it,s) for (__typeof(s.rbegin()) it=s.rbegin(); it!=s.rend(); ++it)
#define ALL(x) (x).begin(),(x).end()
#define P(x) cerr<<#x<<" = "<<x<<endl
#define pb push_back

#define zer(x) memset(x,0,sizeof(x));
#define isin(x,s) (s.find(x)!=s.end())

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;

const int maxn=600;

int a[maxn][maxn];
int d[maxn][maxn];
int m,n;

int mleft[maxn][maxn];
int up[maxn][maxn];
int mark[maxn][maxn];

map <int,int> ans;

struct Square {
  int size;
  int row, col;
  inline bool operator < (const Square &o) const {
	if (size!=o.size) return size>o.size;
	if (row!=o.row) return row<o.row;
	return col<o.col;
  }
  void eat() {
	//cerr<<"Eating ("<<row<<","<<col<<") of size "<<size<<endl;
	++ans[size];
	FOR (i,size) {
	  FOR (j,size) {
		int x=row+i, y=col+j;
		mark[x][y]=1;
		mleft[x][y]=j+1;
		if (col>0) mleft[x][y]+=mleft[x][col-1];
		up[x][y]=i+1;
		if (row>0) up[x][y]+=up[row-1][y];
	  }
	}
  }
};


set <Square> s;

inline bool good(int i, int j) {
  return !mark[i][j];
}

void clear() {
  ans.clear();
  s.clear();
  zer(mleft);
  zer(up);
  memset(a,-1, sizeof a);
  zer(d);
  zer(mark);
}

void solve(int cnum) {
  cin>>m>>n;
  FOR (i,m) {
	for (int j=0;j<n;j+=4) {
	  char c;
	  cin>>c;
	  int x;
	  if (c>='0' && c<='9') x=c-'0';
	  else x=10+c-'A';
	  for (int k=0;k<4;k++)
		if (x&(1<<k)) 
		  a[i][j+3-k]=1;
	}
  }

  for (int i=m-1;i>=0;i--) {
	for (int j=n-1;j>=0;j--) {
	  if (a[i][j]!=a[i+1][j] && a[i][j]!=a[i][j+1] && a[i][j]==a[i+1][j+1])
		d[i][j]=1+min(min(d[i+1][j], d[i][j+1]), d[i+1][j+1]);
	  else d[i][j]=1;

	  d[i][j]=min(d[i][j], n-j);
	  d[i][j]=min(d[i][j], m-i);
	}
  }

  FOR (i,m) {
	FOR (j,n) {
	  Square x;
	  x.size=d[i][j];
	  x.row=i; x.col=j;
	  s.insert(x);
	}
  }

  int nleft=m*n;
  while (nleft) {
	set <Square>::iterator it = s.begin();
	Square x = *it;
	s.erase(it);

	if (!good(x.row, x.col)) continue;
	bool changed=0;

	{
	  //fix x
	  int w=x.size, h=x.size;
	  while (w>0 && mark[x.row][x.col+w-1]) {
		changed=1;
		w-=mleft[x.row][x.col+w-1];
	  }
	  if (w<=0) continue;

	  while (h>0 && mark[x.row+h-1][x.col]) {
		changed=1;
		h-=up[x.row+h-1][x.col];
	  }
	  if (h<=0) continue;

	  while (w>0 && h>0 && mark[x.row+h-1][x.col+w-1]) {
		changed=1;
		int lo=min(mleft[x.row+h-1][x.col+w-1], up[x.row+h-1][x.col+w-1]);
		w-=lo; h-=lo;
	  }

	  x.size=min(w,h);
	  if (x.size<=0) continue;
	}
	
	if (changed) {
	  s.insert(x);
	  continue;
	}
	
	x.eat();
	nleft-=x.size*x.size;
	assert(nleft>=0);
  }

  cout<<"Case #"<<cnum<<": "<<ans.size()<<endl;
  cerr<<"Case #"<<cnum<<": "<<ans.size()<<endl;
  FORITR(it, ans) {
	cout<<it->first<<" "<<it->second<<endl;
  }

}

int main() {
  int nt;
  cin>>nt;
  for (int cnum=1; cnum<=nt; cnum++) {
	clear();
	solve(cnum);
  }
  return 0;
}
