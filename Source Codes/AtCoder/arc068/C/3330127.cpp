#include <cstdio>
#include <algorithm>
const int MAXN=3E5+10;
const int mod=1E9+7;
int N,M;
struct pair {
	int l,r;
	bool operator < (const pair&a) const {
		return r-l < a.r-a.l;
	}
	int len() {return r-l+1;}
}rc[MAXN];
struct FWT {
	int f[MAXN];
	void change(int i,int x) {
		for(;i<=M;i+=i&(-i))
			f[i]+=x;
	}
	int query(int i) {
		int ans=0;
		for(;i;i-=i&(-i))
			ans+=f[i];
		return ans;
	}
}fw;
int main() {
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i) {
		scanf("%d%d",&rc[i].l,&rc[i].r);
	}std::sort(rc+1,rc+N+1);
	/*for(int i=1;i<=N;++i) {
		fw.change(rc[i].l,1);
		fw.change(rc[i].r+1,-1);
	}*/
	int tail=1;
	for(int i=1;i<=M;++i) {
		while(tail<=N&&rc[tail].len()<i){
			fw.change(rc[tail].l,1);
			fw.change(rc[tail].r+1,-1);
			++tail;
		}
		int ans=N-tail+1;
		for(int j=0;j<=M;j+=i) {
			ans+=fw.query(j);
		}printf("%d\n",ans);
	}
	return 0;
}