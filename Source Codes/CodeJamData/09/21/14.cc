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
#include <cassert>

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

//#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

struct node {
	double weight;
	string feature;
	int yes, no;
};

vector<node> tree;

void parse(int i)
{
	string s;
	char c;
	node tmp;

	do { cin >> c; } while ( isspace(c) );

	debug("parse %d, c = '%c'\n",i,c);
	assert( c=='(' );

	cin >> tmp.weight;

	do { c = getchar(); } while ( isspace(c) );

	if ( c!=')' ) {
		ungetc(c,stdin);
		cin >> tmp.feature;
		debug("s = '%s': recurse\n",tmp.feature.c_str());
		tmp.yes = tree.size(); tree.PB(tmp);
		tmp.no  = tree.size(); tree.PB(tmp);
		parse(tmp.yes);
		parse(tmp.no);

		cin >> c;
		assert( c==')' );
	}

	tree[i] = tmp;
}

double cute(set<string> features)
{
	double p = 1;
	int node = 0;

	do {
		p *= tree[node].weight;
		if ( tree[node].feature=="" ) break;
		if ( features.count(tree[node].feature) ) {
			node = tree[node].yes;
		} else {
			node = tree[node].no;
		}
	} while ( 1 );

	return p;
}

int main()
{
	int nruns;

	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		int L, A;

		cin >> L;

		tree = vector<node>(1);
		parse(0);

		cin >> A;
		printf("Case #%d:\n",run);

		REP(i,A) {
			set<string> features;
			string s;
			int n;

			cin >> s >> n;
			REP(j,n) { cin >> s; features.insert(s); }
			printf("%lf\n",cute(features));
		}
	}

	return 0;
}
