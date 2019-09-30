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
using namespace std;
const int N=2e6;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int p[N];
int head[N],nxt[N],to[N],d[N],tot,ans[N];
struct cmp{ inline bool operator () (const int &a,const int &b) const { return p[a]<p[b]; } };
struct cmp2{ inline bool operator () (const int &a,const int &b) const { return a>b; } };
inline void link(int a,int b) { d[to[++tot]=b]++,nxt[tot]=head[a],head[a]=tot; }
int main()
{
	int n=gi(),m=gi(),i,k,t;
	for (i=1;i<=n;i++) p[i]=gi();
	set<int,cmp>s;set<int>::iterator it;
	priority_queue<int,vector<int>,cmp2>q;
	for (i=1;i<=n;i++) {
		if (i>m) s.erase(i-m);
		it=s.insert(i).first;
		if (++it!=s.end()) link(i,*it);
	}
	s.clear();
	for (i=n;i;i--) {
		if (i+m<=n) s.erase(i+m);
		it=s.insert(i).first;
		if (++it!=s.end()) link(i,*it);
	}
	for (i=1;i<=n;i++) if (!d[i]) q.push(i);
	for (t=1;t<=n;t++) {
		k=q.top();q.pop();
		ans[k]=t;
		for (i=head[k];i;i=nxt[i]) if (!--d[to[i]]) q.push(to[i]);
	}
	for (i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}