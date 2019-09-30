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

bool ugly(LL N) {
	return !((N%2) && (N%3) && (N%5) && (N%7));
}

int main()
{
	ios_base::sync_with_stdio(0);
	int NCase;
	cin>>NCase;
	REP(ncase,NCase) {
		string s;
		cin>>s;
		int maxr = 1;
		REP(i,s.size()-1) maxr*=3;
		int result = 0;
		REP(ter,maxr) {
			int itr = ter;
			bool sgn=1;
			stringstream ss;
			ss<<s[0];
			LL curn =0;
			REP(i,s.size()) {
				if(itr%3==1) {
					ss<<s[i+1];
					//cout<<"j "<<s[i+1]<<endl;
				}
				else {
					LL tmp=0;
					//cout<<"i "<<ss.string()<<endl;
					ss>>tmp;
					//cout<<"a "<<tmp<<endl;
					ss.clear();
					curn += (sgn?1:-1)*tmp;
					if(itr%3==2) sgn=1;
					else sgn=0;
					ss<<s[i+1];
				}
				itr/=3;
			}
			//cout<<"n"<<curn<<endl;
			if(ugly(curn)) result++;
		}

		cout<<"Case #"<<ncase+1<<": "<<result<<endl;
	}

  return 0;
}
