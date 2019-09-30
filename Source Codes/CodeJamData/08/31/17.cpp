#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>

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

int freq[1000000];

void doit() {
	int P,K,L;
	cin>>P>>K>>L;

	REP(i,L) cin>>freq[i];
	sort(freq, freq+L, greater<int>());
	LL result = 0;
	int tt=0;
	REP(i,P) {
		REP(j,K) {
			result+=(LL)freq[tt]*(LL)(i+1);
			tt++;
			if(tt>=L) break;
		}
		if(tt>=L) break;
	}

	cout<<result;
	cout<<endl;
}



int main()
{
	ios_base::sync_with_stdio(0);
	int NCase;
	cin>>NCase;
	REP(ncase,NCase) {
		cout<<"Case #"<<ncase+1<<": ";
		doit();
	}

  return 0;
}
