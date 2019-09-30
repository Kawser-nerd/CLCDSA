#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;

typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PI;
#define MP make_pair
#define REP(x,n) for(int x=0; x<(int)(n); ++x)
#define REB(b,x,n) for(int x=b; x<(int)(n); ++x)
#define REPD(x,n) for(int x=(n)-1; x>=0; --x)
#define PB push_back
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

int inp[500002];
PI inp2[500002];
int revi[500002];
int revj[500002];
int a[101];
int dyn[500002];

int tr[500002][20];

const LL MOD = 1000000007;

void init(int n) {
	//cout<<"init"<<endl;
	REP(i,20) {
		REP(j,n+1) tr[j][i]=0;
		n = (n+1)/2;
	}
}

void put(int where, int value, int n) {
	//cout<<"put "<<where<<" v "<<value<<endl;
	assert(tr[where][0]==0);
	REP(i,20) {
		tr[where][i] = ((LL)tr[where][i] + (LL)value) % MOD;
		where/=2;
	}
}

int getsumm(int max, int n) {
	//REP(l,3) {REP(i,n) cout<<tr[i][l]<<" "; cout<<endl;}
	int result = 1;
	int tmp = max;
	//int l = 0;
	REP(l,20){
		if(max%2) result = ((LL)result + (LL)tr[max-1][l] ) % MOD;
		max/=2;
		//l++;
	}
	//cout<<"get "<<tmp<<" "<<result<<endl;
	return result;
}

int doit(int n) {
	//REP(i,n) cout<<"i "<<inp[i]<<endl;
	REP(i,n) inp2[i]=MP(inp[i],i);
	sort(inp2,inp2+n);
	//REP(i,n) cout<<"s "<<inp2[i].ST<<inp2[i].ND<<endl;
	REP(i,n) revi[inp2[i].ND]=i;
	REP(i,n) {
		revj[inp2[i].ND]=i;
		int j=i-1;
		while(j>=0) if(inp2[j--].ST == inp2[i].ST) revj[inp2[i].ND]--; else break;
	}
	//REP(i,n) cout<<"r "<<revi[i]<<endl;

	init(n);
	//put(0,1,n); //	dyn[0]=1;

	int result=0;
	REP(i,n) {
		int d = getsumm(revj[i],n);
		put(revi[i],d,n);
		//dyn[i+1]=0;
		//REP(j,i+1)
		//	if(inp[j]<inp[i+1])
		//		dyn[i+1] = ((LL)dyn[i+1] + dyn[j]) % MOD;
		result = ((LL)result + (LL)d) % MOD;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int NCase;
	cin>>NCase;
	REP(ncase,NCase) {
		int n,m,X,Y,Z;
		cin>>n>>m>>X>>Y>>Z;
		REP(i,m) cin>>a[i];
		inp[0]=-1;
		REP(i,n) {
			inp[i]=a[i%m];
			a[i%m]=((LL)X*(LL)a[i%m] + (LL)Y*(LL)(i+1))%(LL)Z;
		}

		cout<<"Case #"<<ncase+1<<": "<<doit(n)<<endl;
	}

  return 0;
}
