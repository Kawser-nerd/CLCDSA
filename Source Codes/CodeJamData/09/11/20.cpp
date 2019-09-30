#include <cstdio>
#include <cctype>
#include <cstring>
#include <set>
#include <mem>
#include <bitset>
#include <algorithm>

using namespace std;

int T;
#define ll long long
const int MAXL=10000005;

int mem[11][MAXL];
int base;
bitset<MAXL> v;

char buf[MAXL];int bufind;
inline bool read(int &x) {
	while (1) {
		if (buf[bufind]=='\n') {bufind++;return false;}
		if (isdigit(buf[bufind])) {break;}
		bufind++;
	}
	x=0;
	while (isdigit(buf[bufind])) {
		x=10*x+(int)(buf[bufind]-'0');
		bufind++;
	}
	return true;
}

inline ll sqr(ll x) {return x*x;}
inline ll calc(ll x) {
	ll ret=0;
	while (x>0) {
		ret+=sqr(x%base);
		x/=base;
	}
	return ret;
}

ll path[MAXL],L;
inline void solve() {
	mem[base][1]=1;
	v.reset();
	for(int i=2;i<30005;i++) {
		if (mem[base][i]!=-1) {continue;}
		L=0;
		path[L++]=i;
		while (path[L-1]!=1 && v[path[L-1]]==0) {
			v[path[L-1]]=1;
			path[L]=calc(path[L-1]);L++;
		}
		if (path[L-1]==1 || mem[base][path[L-1]]==1) {
			for(int j=0;j<L;j++) {mem[base][path[j]]=1;}
		}	else {
			for(int j=0;j<L;j++) {mem[base][path[j]]=0;}
		}
	}
}

int N,B[15];

inline bool good(int x) {
	for(int i=0;i<N;i++) {
		base=B[i];
		if (mem[B[i]][calc(x)]==0) {return false;}
	}
	return true;
}

map<set<int> , int> m;

int main() {
	memset(mem,-1,sizeof(mem));
	for(base=2;base<=10;base++) {
		solve();
	}
	scanf("%d\n",&T);
	fread(buf,1,MAXL,stdin);
	for(int t=1;t<=T;t++) {
		N=0;
		int a;
		set<int> s;
		while (read(a)) {
			B[N++]=a;
			s.insert(a);
		}
		if (m.find(s)!=m.end()) {
			printf("Case #%d: %d\n",t,mem[s]);
			continue;
		}
		int ans=2;
		while (!good(ans)) {ans++;}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}