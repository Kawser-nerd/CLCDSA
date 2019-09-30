#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cctype>
using namespace std;
#define maxn 500100
#define mod 1000000007
struct tt{
	long long key;
	long long cnt;
	long long allcnt;
	int h;
	int l, r;
};
int nsc, sc;
long long a[maxn];
long long mas[maxn];
long long n,m, x, y, z;
long long cnt[maxn];
tt h[2*maxn];
int nh;
void init(){
	int i;
	scanf("%lld%lld%lld%lld%lld", &n, &m, &x, &y, &z);
	for(i=0;i<m;i++)
		scanf("%lld", &a[i]);
	for(i=0;i<n;i++){
		mas[i]=a[i%m];
		a[i%m]=(x*a[i%m]+y*(i+1))%z;
	}
}
void norm1(int root){
	if (root==0) return;
	h[root].h=max(h[h[root].l].h, h[h[root].r].h)+1;
	h[root].allcnt=(h[root].cnt+h[h[root].l].allcnt+h[h[root].r].allcnt)%mod;
}
void turnright(int &root){
	int acc=root;
	if (h[root].l==0)
		acc=acc;
	root=h[root].l;
	h[acc].l=h[root].r;
	h[root].r=acc;
	norm1(h[root].r);
	norm1(root);
}
void turnleft(int &root){
	int acc=root;
	if (h[root].r==0)
		acc=acc;
	root=h[root].r;
	h[acc].r=h[root].l;
	h[root].l=acc;
	norm1(h[root].l);
	norm1(root);
}
void norm(int &root){
	int lh, rh;
	int l, r;
	if (root==0) return;
	l=h[root].l;
	r=h[root].r;
	lh=h[l].h;
	rh=h[r].h;
	if (lh>rh+1){
		if (h[h[l].r].h>h[h[l].l].h)
			turnleft(h[root].l);
		turnright(root);
	}
	else if (rh>lh+1){
		if (h[h[r].l].h>h[h[r].r].h)
			turnright(h[root].r);
		turnleft(root);
	}
	else
		norm1(root);
}
void insert(int &root, long long key, long long cnt){
	if (root==0){
		root=++nh;
		h[root].h=1;
		h[root].cnt=h[root].allcnt=cnt%mod;
		h[root].key=key;
		h[root].l=h[root].r=0;
		return;
	}
	else if (key==h[root].key){
		h[root].cnt=(h[root].cnt+cnt)%mod;
	}
	else if (key<h[root].key){
		insert(h[root].l, key, cnt);
	}
	else 
		insert(h[root].r, key, cnt);
	norm(root);
}
long long getsum(int root, long long val){
	if (root==0) return 0;
	if (val<h[root].key)
		return getsum(h[root].l, val);
	else{
		long long ret=h[h[root].l].allcnt;
		if (val>h[root].key)
			ret=(ret+h[root].cnt)%mod;
		return (ret+getsum(h[root].r, val))%mod;
	}
}
int root;
void solve(){
	int i,j;
	long long res=0;
	for(i=n;i>0;i--)
		mas[i]=mas[i-1];
	cnt[0]=1;
	mas[0]=-1;
	nh=0;
	root=0;
	insert(root, -1, 1);
	long long work;
	for(i=1;i<=n;i++){
		work=getsum(root, mas[i]);
		insert(root, mas[i], work);
		res=(res+work)%mod;
	}
	printf("Case #%d: %lld\n", sc, res);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&nsc);
	for(sc=1; sc<=nsc; sc++){
		init();
		solve();
	}
	return 0;
}