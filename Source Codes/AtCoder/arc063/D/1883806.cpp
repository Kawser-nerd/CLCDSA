#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=300005;
int ans,top1,top2,n,tree[N<<2],add[N<<2],w,h;
pair<int,int> a[N],q1[N],q2[N];
inline bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}
void del(int l,int r,int i,int j,int s,int nod){
	//cout<<l<<" "<<r<<" "<<i<<" "<<j<<" "<<s<<endl;
	if(i>j)return;
	if(l==i&&r==j){
		tree[nod]+=s; add[nod]+=s; return;
	}
	int mid=(l+r)>>1;
	if(j<=mid)del(l,mid,i,j,s,nod<<1); else if(i>mid)del(mid+1,r,i,j,s,nod<<1|1);
	else{
		del(l,mid,i,mid,s,nod<<1); del(mid+1,r,mid+1,j,s,nod<<1|1);
	}
	tree[nod]=max(tree[nod<<1],tree[nod<<1|1])+add[nod];
}
void build(int l,int r,int nod){
	if(l==r){
		tree[nod]=w-a[l].second; return;
	}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	add[nod]=0; tree[nod]=max(tree[nod<<1],tree[nod<<1|1]);
}
void solve(){
	sort(&a[1],&a[n+1],cmp);
	build(0,n,1);
	int mid=w>>1;
	q1[0].first=q2[0].first=-1;
	q1[top1=1]=mp(0,0); q2[top2=1]=mp(0,w);
	for(int i=1;i<=n;i++){
		ans=max(ans,tree[1]+a[i].second); //cout<<a[i].second<<" "<<tree[1]<<endl;
		if(a[i].first<=mid){
			while(top1&&a[i].first>q1[top1].second){
				del(0,n,q1[top1-1].first+1,q1[top1].first,q1[top1].second-a[i].first,1); top1--;
			}
			q1[++top1]=mp(i-1,a[i].first); 
		}else{
			while(top2&&a[i].first<q2[top2].second){
				del(0,n,q2[top2-1].first+1,q2[top2].first,a[i].first-q2[top2].second,1); top2--;
			}
			q2[++top2]=mp(i-1,a[i].first);
		}
		q1[++top1]=mp(i,0); q2[++top2]=mp(i,w);
	}
	ans=max(ans,tree[1]+h);
}
int main(){
	w=read(); h=read(); n=read();
	for(int i=1;i<=n;i++){
		a[i].first=read(); a[i].second=read();
	}
	solve();
	swap(w,h);
	for(int i=1;i<=n;i++)swap(a[i].first,a[i].second);
	solve();
	cout<<ans*2<<endl;
}