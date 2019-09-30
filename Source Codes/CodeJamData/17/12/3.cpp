#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,P;
int R[100];
vector<int> Q[100];
int ID[100];
int LL[100][100];
int RR[100][100];


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>P;
	FOR(i,N) {
		cin>>R[i];
		R[i]*=10;
	}
	FOR(y,N) {
		Q[y].clear();
		FOR(x,P) {
			cin>>j;
			j*=10;
			int LLL=(j+(R[y]*11/10)-1)/(R[y]*11/10);
			int RRR=j/(R[y]*9/10);
			if(LLL<=RRR) Q[y].push_back(j);
		}
		sort(ALL(Q[y]));
		
		FOR(x,Q[y].size()) {
			LL[y][x]=max(1,(Q[y][x]+(R[y]*11/10)-1)/(R[y]*11/10));
			RR[y][x]=(Q[y][x])/(R[y]*9/10);
		}
		ID[y]=0;
	}
	int ret=0;
	while(1) {
		int mal=0;
		FOR(y,N) {
			if(ID[y]>=Q[y].size()) goto out;
			mal=max(mal,LL[y][ID[y]]);
		}
		int up=1;
		while(up) {
			up=0;
			FOR(y,N) {
				while(ID[y]<Q[y].size() && RR[y][ID[y]]<mal) {
					ID[y]++;
					if(ID[y]>=Q[y].size()) goto out;
					
					up=1;
					mal=max(mal,LL[y][ID[y]]);
				}
				if(ID[y]>=Q[y].size()) break;
			}
			if(y<N) break;
		}
		
		
		ret++;
		FOR(y,N) ID[y]++;
	}
	out:
	_P("Case #%d: %d\n",_loop,ret);
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


