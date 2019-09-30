using namespace std;
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define PB push_back
#define ALL(x) ((x).begin()),((x).end())
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(int i=0; i<(n); ++i)

const int infty = 999999999;

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

int main()
{
	int nruns;

	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		string n;

		cin >> n;

		if ( !next_permutation(n.begin(),n.end()) ) {
			VI nd(10,0);

			REP(i,(int)n.size()) nd[n[i]-'0']++;

			string res;
			int i;
			for(i=1; nd[i]==0; i++);
			res = '0'+i; nd[i]--;
			res += '0';
			REP(i,10) REP(j,nd[i]) res += '0'+i;
			n = res;
		}

		printf("Case #%d: %s\n",run,n.c_str());
	}

	return 0;
}
