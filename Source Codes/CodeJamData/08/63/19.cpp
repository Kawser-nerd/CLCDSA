#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <cmath>
#include <sstream>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int,int>

#define fo(i,n) for(int i=0; i < (n) ; ++i)
#define FO(i,a,b) for(int i=a;i<=(b);++i)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
#define UNIQ(v) (v).erase(unique(ALL(v)),(v).end())

#define VDebug(x)  {fo(i,(x).size()) cout<<(x)[i]<<" ";cout<<endl;}
#define VVDebug(x) {fo(j,(x).size()) VDebug(x[j])}
				     
typedef istringstream iss;
typedef ostringstream oss;
typedef long long int lint;
typedef complex<double> point;
				     
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VS> VVS;
				     
const char eof = -123;

void printBits(unsigned int x,int end = 32,int start = 0){for(int i = end-1;i>=start;i--) if(x & (1<<i)) cout<<1<<" "; else cout<<0<<" ";}
int readInt(){	int x;if(scanf("%d",&x) != 1) return eof;return x;}
char readChar() { char c; if(scanf("%c",&c) != 1) return eof; return c;}
lint readLL(){lint x; if(cin>>x) return x; return eof;}
double readDouble(){double f;if(scanf("%lf",&f) == 1)return f;return eof;}


double P;
double Million = 1000000;
double memo[16][1<<16];

void init(){
}

double doit(int roundsLeft, int where)
{
	if(where >= (1<<roundsLeft)) return 1.0;
	if(where < 0) return 0;
	if(roundsLeft == 0) return 0;
//	cout<<roundsLeft<<" "<<where<<endl;

	double & ret = memo[roundsLeft][where];
	if(ret > -0.5) return ret;
	ret = 0;
	int sx, sy, dx, dy, tx, ty;
	if(where % 2){
		sx = 1, sy = 0;
		dx = 0, dy = -1;
		tx = 1, ty = -1;
	}
	else{
		sx = 0, sy = -1;
		dx = 1, dy = 0;
		tx = 1, ty = -1;
	}
	ret >?= doit(roundsLeft - 1, where / 2);
	for(;;){
		if(sx > where) break;
		ret >?= P * doit(roundsLeft - 1 , (where + sx)/2) + (1-P) * doit(roundsLeft-1, (where + sy)/2);
		sx += dx; sy += dy;
		dx = tx - dx; dy = ty - dy;
		if((where+sx) > (1 << roundsLeft)  && (where - sx) < 0) break;
	}
//	cout<<roundsLeft<<" "<<where<<" "<<ret<<endl;
	return ret;
}


void solve(){
	int rounds = readInt();
	P = readDouble();
	double X = readInt();
	for(int i=0;i<16;i++) fo(j,((1<<16) + 1)) memo[i][j] = -1;
	double ret = doit(rounds,  (int)((1<<rounds)*X/Million));
	printf("%.6f\n",ret);
}

main()
{
	init();
	int cases = readInt();
	int tc = 0;
	while(cases--){
		tc++;
		printf("Case #%d: ",tc);
		solve();
	}
}

