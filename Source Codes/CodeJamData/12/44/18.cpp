// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#define X first
#define Y second
#define N 65
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;
const int dx[]={-1,0,0,1},dy[]={0,1,-1,0};
int r,c;
char s[N][N];
void input() {
	scanf("%d%d",&r,&c);
	for ( int i=0; i<r; i++ ) scanf("%s",s[i]);
}
int nc,vis[N][N];
void dfs( int x, int y ) {
	vis[x][y]=1;
	nc++;
	for ( int i=0; i<3; i++ ) {
		int nx=x+dx[i],ny=y+dy[i];
		if ( !vis[nx][ny] && s[nx][ny]!='#' ) dfs(nx,ny);
	}
}
set<VII> vs;
bool chk( VII &v ) {
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	if ( vs.count(v) ) return 0;
	vs.insert(v);
	return 1;
}
void solve( int x, int y ) {
	memset(vis,0,sizeof(vis));
	nc=0; dfs(x,y);
	VII now;
	for ( int i=0; i<r; i++ ) for ( int j=0; j<c; j++ ) if ( vis[i][j] ) now.PB(MP(i,j));
	if ( SZ(now)==1 ) {
		printf("%c: %d Lucky\n",s[x][y],nc);
		return;
	}
	vs.clear();
	queue<VII> q;
	q.push(now);
	while ( !q.empty() ) {
		for ( int i=1; i<4; i++ ) {
			now=q.front();
			int flg=1;
			FOR(it,now) {
				//printf("(%d,%d)",it->X,it->Y);
				int nx=dx[i]+it->X,ny=dy[i]+it->Y;
				if ( s[nx][ny]=='#' ) continue;
				if ( !vis[nx][ny] ) {
					flg=0;
					break;
				}
				*it=MP(nx,ny);
			}
			//puts("");
			if ( !flg ) continue;
			if ( chk(now) ) {
				if ( SZ(now)==1 ) {
					printf("%c: %d Lucky\n",s[x][y],nc);
					return;
				}
				q.push(now);
			}
		}
		q.pop();
	}
	printf("%c: %d Unlucky\n",s[x][y],nc);
}
void solve() {
	static int cas=0;
	printf("Case #%d:\n",++cas);
	for ( int i=0; i<10; i++ ) for ( int j=0; j<r; j++ ) for ( int k=0; k<c; k++ ) if ( s[j][k]==i+'0' ) solve(j,k);
}
int main()
{
	int t;
	scanf("%d",&t);
	while ( t-- ) {
		input();
		solve();
	}
	return 0;
}
