#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
using namespace std;
typedef long long LL;
const int N=4e5+100;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int x[N],a[N],b[N];
int head[N],nxt[N],to[N],tot=1;
bool o[N],vis[N];
inline void link(int a,int b) {
	to[++tot]=b,nxt[tot]=head[a],head[a]=tot;
	to[++tot]=a,nxt[tot]=head[b],head[b]=tot;
}
inline void dfs(int k) {
	for (int i;i=head[k];)
		if (head[k]=nxt[i],!vis[i]) {
			vis[i^1]=true;
			dfs(to[i]);
			if (i&2)
				x[a[k]==to[i]?k:to[i]]=i&1?-1:1;
		}
}
inline void back(int k) {
	for (int i=head[k];i;i=nxt[i]) {
		x[k]-=x[i];
		back(i);
	}
}
int main()
{
	int n=gi(),i,rt;
	for (i=1;i<=n;i++) if ((a[i]=gi())==-1) a[i]=n+1,rt=i;
	for (i=1;i<=n;i++) if ((b[i]=gi())==-1) b[i]=n+1;
	for (i=1;i<=n;i++) {
		o[a[i]]^=1;o[b[i]]^=1;
		link(a[i],i);link(i,b[i]);
	}
	for (i=1;i<=n;i++) if (o[i]) return puts("IMPOSSIBLE"),0;
	puts("POSSIBLE");
	dfs(n+1);
	for (i=1;i<=n;i++) head[i]=0;
	for (i=1;i<=n;i++) nxt[i]=head[a[i]],head[a[i]]=i;
	back(rt);
	for (i=1;i<=n;i++) printf("%d ",x[i]);
	return 0;
} ./Main.cpp:31:14: warning: using the result of an assignment as a condition without parentheses [-Wparentheses]
        for (int i;i=head[k];)
                   ~^~~~~~~~
./Main.cpp:31:14: note: place parentheses around the assignment to silence this warning
        for (int i;i=head[k];)
                    ^
                   (        )
./Main.cpp:31:14: note: use '==' to turn this assignment into an equality comparison
        for (int i;i=head[k];)
                    ^
                    ==
1 warning generated.