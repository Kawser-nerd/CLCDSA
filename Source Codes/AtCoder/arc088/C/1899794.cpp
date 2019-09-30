#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
int n,q,i;
int tree[4*N],a[N],m;
#define p(a,b) a+b
inline int ask(int l,int r,int i,int j,int nod){
	if(i>j)return 0;
    int mid=(l+r)>>1;
	if (l==i&&j==r) return tree[nod];
	if (j<=mid) return ask(l,mid,i,j,nod<<1);
	else if(i>mid) return ask(mid+1,r,i,j,(nod<<1)+1);
	int left=ask(l,mid,i,mid,nod<<1);
	int right=ask(mid+1,r,mid+1,j,(nod<<1)+1);
	return p(left,right);
}
inline void insert(int l,int r,int i,int nod){
	int mid=(l+r)>>1;
	if (l==r){tree[nod]=0; return;}
	if (i<=mid)insert(l,mid,i,nod<<1);
	else insert(mid+1,r,i,(nod<<1)+1);
	tree[nod]=p(tree[nod<<1],tree[(nod<<1)+1]);
}
inline void build(int l,int r,int nod){int mid=(l+r)>>1;
	if (l==r) {tree[nod]=1; return;}
	build(l,mid,nod<<1); build(mid+1,r,(nod<<1)+1);
	tree[nod]=p(tree[nod<<1],tree[(nod<<1)+1]);
}
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
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
char ch[N];
int vis[N],tong[26],sum;
long long ans;
#include<vector>
vector<int> que[26];
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(int i=1;i<=n;i++)tong[ch[i]-'a']++;
	for(int i=0;i<26;i++)sum+=tong[i]&1;
	if(sum>1){
		puts("-1"); return 0;
	}
    build(1,n,1);
	for(int i=1;i<=n;i++)que[ch[i]-'a'].push_back(i);
	for(int i=1;i<=n;i++){
		int pos=que[ch[i]-'a'][que[ch[i]-'a'].size()-1];
		que[ch[i]-'a'].pop_back();
		if(vis[i])continue;
		if(pos==i){
			ans+=ask(1,n,i+1,n,1)/2; insert(1,n,i,1); vis[i]=1;
		}else{
			//cout<<pos<<" "<<i<<" "<<ask(1,n,pos+1,n,1)<<endl;
			ans+=ask(1,n,pos+1,n,1);
			insert(1,n,pos,1); insert(1,n,i,1); vis[i]=vis[pos]=1;
		}
	}
	cout<<ans<<endl;
}