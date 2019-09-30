#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=j;i>=k;i--)
#define LL long long
using namespace std;

inline int read() {
	int x = 0,f = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f = -1; ch = getchar(); }
	while(ch>='0'&&ch<='9') { x = x *10+ch-48 ; ch = getchar(); }
	return x * f ;
}

const int N = 311;
int n,m,ans;
int a[N][N],cnt[N],vis[N];

int main() {
	n = read(); m = read();
	For(i, 1, n) 
	  For(j, 1, m) a[i][j]=read();
	For(i, 1, m) vis[i] = 1; 
	ans = n;
	For(T, 1, m) {
		memset(cnt,0,sizeof cnt);
		For(i, 1, n) 
		  For(j, 1, m) 
		    if(vis[a[i][j]]) {
		    	++cnt[a[i][j]];
		    	break;
			}
		int Mx = 0,id = 0;
		For(i, 1, m) 
			if( cnt[i] > Mx ) Mx = cnt[i],id = i;
		ans = min(Mx,ans);
		vis[id] = 0;
	} 
	printf("%d\n",ans); 
	return 0;
}