#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=105;
int n,m;
char a[N][N];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
//shang xia zuo you
int dir[267];
int Main(){
	int ans=0;
	dir['^']=0;
	dir['v']=1;
	dir['<']=2;
	dir['>']=3;
	rep(i,1,n)rep(j,1,m)if(a[i][j]!='.'){
		bool have[4];
		memset(have,0,sizeof have);
		rep(k,0,3){
			int x=i+dx[k];int y=j+dy[k];
			while(x>=1&&x<=n&&y>=1&&y<=m){
				if(a[x][y]!='.')have[k]=1;
				x+=dx[k];y+=dy[k];
			}
		}
		if(have[dir[a[i][j]]])continue;
		bool hh=0;
		rep(k,0,3)hh|=have[k];
		if(!hh)return -1;
		ans++;
	}
	return ans;
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;scanf("%d",&T);
	rep(Cas,1,T){
		scanf("%d%d",&n,&m);
		rep(i,1,n)scanf("%s",a[i]+1);
		int v=Main();
		if(v!=-1)
		printf("Case #%d: %d\n",Cas,v);
		else 
		printf("Case #%d: IMPOSSIBLE\n",Cas);
	}
	return 0;
}


