#include<cstdio>
#include<map>
#include<string>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)

typedef long long ll;
typedef pair<ll,ll> bits;

char buff[1000];

int n,nq;
map<string,int> name2id;

inline void setbit(pair<ll,ll> &bits,int ind) {
	if(ind<64) bits.first|=1LL<<ind; else bits.second|=1LL<<(ind-64);
}

void run(int casenr) {
	name2id.clear();
	gets(buff);
	sscanf(buff,"%d",&n);
	assert(n<=128);
	REP(i,n) {
		gets(buff);
		name2id[string(buff)]=i;
	}
	gets(buff);
	sscanf(buff,"%d",&nq);
	int ret=0;
	bits cur,all;
	REP(i,n) setbit(all,i);
	REP(i,nq) {
		gets(buff);
		assert(name2id.count(buff));
		int id=name2id[string(buff)];
		setbit(cur,id);
//		printf("%llx,%llx\n",cur.first,cur.second);
		if(cur==all) {
			++ret;
			cur=pair<ll,ll>();
			setbit(cur,id);
		}
	}
	printf("Case #%d: %d\n",casenr,ret);
}

int main() {
	gets(buff);
	int n; sscanf(buff,"%d",&n);
	FORE(i,1,n) run(i);
	return 0;
}
