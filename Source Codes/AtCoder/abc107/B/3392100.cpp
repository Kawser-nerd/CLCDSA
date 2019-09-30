#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define int long long

const int maxn=105;
int n,m;
char a[maxn][maxn];
bool wrt[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for (int i=1;i<=m;i++){
		wrt[i]=false;
		for (int j=1;j<=n;j++) if (a[j][i]=='#') wrt[i]=true;
	}
	for (int i=1;i<=n;i++){
		bool flg=false;
		for (int j=1;j<=m;j++) if (a[i][j]=='#') flg=true;
		if (flg){
			for (int j=1;j<=m;j++) if (wrt[j]) putchar(a[i][j]);
			printf("\n");
		}
	}
	return 0;
}