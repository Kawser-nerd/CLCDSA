#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int _,n,o,g,v,r,y,b,__;
char s[10];
int cnt[10];
VI construct(int a,int b,int c) {
	VI v(a,0);
	int sp=a;
	rep(i,0,b) {
		if (sp==0) {
			rep(j,0,SZ(v)) if (v[j]!=1&&v[(j+1)%v.size()]!=1) {
				v.insert(v.begin()+j+1,1);
				break;
			}
		} else {
			rep(j,0,SZ(v)) if (v[j]==0&&v[(j+1)%v.size()]==0) {
				v.insert(v.begin()+j+1,1);
				break;
			}
			sp--;
		}
	}
	rep(i,0,c) {
		if (sp==0) {
			rep(j,0,SZ(v)) if (v[j]!=2&&v[(j+1)%v.size()]!=2) {
				v.insert(v.begin()+j+1,2);
				break;
			}
		} else {
			rep(j,0,SZ(v)) if (v[j]==0&&v[(j+1)%v.size()]==0) {
				v.insert(v.begin()+j+1,2);
				break;
			}
			sp--;
		}
	}
	return v;
}
string ret;
int gao() {
	if (v>y||g>r||o>b) {
		return 0;
	}
	// o=r+y
	// g=y+b
	// v=r+b
	ret="";
	if (v==y&&y>0) {
		if (o||g||r||b) return 0;
		rep(i,0,y) ret+="YV";
		return 1;
	}
	if (g==r&&r>0) {
		if (o||v||y||b) return 0;
		rep(i,0,g) ret+="RG";
		return 1;
	}
	if (o==b&&b>0) {
		if (g||v||r||y) return 0;
		rep(i,0,o) ret+="BO";
		return 1;
	}
	b-=o; r-=g; y-=v;
	int ss=r+y+b;
	if (2*r>ss||2*y>ss||2*b>ss) return 0;
	cnt[0]=r; cnt[1]=y; cnt[2]=b;
	s[0]='R'; s[1]='Y'; s[2]='B';
	rep(i,0,3) rep(j,i+1,3) if (cnt[i]<cnt[j]) swap(cnt[i],cnt[j]),swap(s[i],s[j]);
	vector<int> vv=construct(cnt[0],cnt[1],cnt[2]);
	bool vr=(g==0),vy=(v==0),vb=(o==0);
//	printf("%d %d %d %d %d %d\n",vr,vy,vb,g,v,o);

	rep(i,0,SZ(vv)) {
		if (s[vv[i]]=='R'&&vr==0) {
			rep(k,0,g) ret+="RG";
			vr=1;
		}
		if (s[vv[i]]=='Y'&&vy==0) {
			rep(k,0,v) ret+="YV";
			vy=1;
		}
		if (s[vv[i]]=='B'&&vb==0) {
			rep(k,0,o) ret+="BO";
			vb=1;
		}
		ret+=s[vv[i]];
	}
//	printf("%d %d %d\n",vr,vy,vb);
	return 1;
}
void add(int u) {
	if (u=='R') cnt[0]++;
	if (u=='O') cnt[0]++,cnt[1]++;
	if (u=='Y') cnt[1]++;
	if (u=='G') cnt[1]++,cnt[2]++;
	if (u=='B') cnt[2]++;
	if (u=='V') cnt[2]++,cnt[0]++;
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		scanf("%d%d%d%d%d%d",&r,&o,&y,&g,&b,&v);
		int rr=r,oo=o,yy=y,gg=g,bb=b,vv=v;
		printf("Case #%d: ",++__);
		if (!gao()) puts("IMPOSSIBLE"); else {
			printf("%s\n",ret.c_str());
			assert(SZ(ret)==n);
			rep(i,0,SZ(ret)) {
				if (ret[i]=='R') --rr;
				if (ret[i]=='O') --oo;
				if (ret[i]=='Y') --yy;
				if (ret[i]=='G') --gg;
				if (ret[i]=='B') --bb;
				if (ret[i]=='V') --vv;
			}
			assert(rr==0&&oo==0&&yy==0&&gg==0&&bb==0&&vv==0);
			rep(i,0,SZ(ret)) {
				char u=ret[i],v=ret[(i+1)%n];
				cnt[0]=cnt[1]=cnt[2]=0;
				add(u); add(v);
				assert(cnt[0]<=1&&cnt[1]<=1&&cnt[2]<=1);
			}
		}
	}
}
