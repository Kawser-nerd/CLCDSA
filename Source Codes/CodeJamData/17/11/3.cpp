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

int H,W;
string S[30];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(i,100) {
			FOR(x,W-1) if(S[y][x]!='?' && S[y][x+1]=='?') S[y][x+1]=S[y][x];
			for(x=W-1;x>=1;x--) if(S[y][x]!='?' && S[y][x-1]=='?') S[y][x-1]=S[y][x];
		}
	}
	FOR(i,100) {
		FOR(y,H-1) if(S[y][0]!='?' && S[y+1][0]=='?') S[y+1]=S[y];
		for(y=H-1;y>=1;y--) if(S[y][0]!='?' && S[y-1][0]=='?') S[y-1]=S[y];
	}
	
	
	_P("Case #%d:\n",_loop);
	FOR(y,H) _P("%s\n",S[y].c_str());
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


