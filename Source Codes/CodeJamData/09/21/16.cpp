// Adrian Kügel
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <assert.h>
#include <limits.h>
#include <complex>
#include <algorithm>
#include <ctype.h>
#include <string>
using namespace std;

typedef set<int> SI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef complex<double> tComp;

char line[1000];
string s;
int pos;

struct dtree {
	double weight;
	char feature[12];
	struct dtree *has_it, *has_not;
	dtree() {
		has_it = has_not = NULL;
	}
	~dtree() {
		delete has_it;
		delete has_not;
	}
};

void skip_spaces() {
	while(pos < (int)s.size() && isspace(s[pos]))
		++pos;
}

dtree *parse() {
	dtree *cur = new dtree();
	skip_spaces();
	assert(s[pos] == '(');
	++pos;
	skip_spaces();
	string temp;
	while(isdigit(s[pos]) || s[pos] == '+' || s[pos] == '-' || s[pos] == '.') {
		assert(pos < (int)s.size());
		temp += s[pos++];
	}
	sscanf(temp.c_str(), "%lf", &(cur->weight));
	skip_spaces();
	assert(pos < (int)s.size());
	if (s[pos] == ')') {
		++pos;
		return cur;
	}
	int i = 0;
	assert(pos < (int)s.size());
	while(!isspace(s[pos]) && s[pos] != '(')
		cur->feature[i++] = s[pos++];
	cur->feature[i] = 0;
	cur->has_it = parse();
	cur->has_not = parse();
	skip_spaces();
	assert(pos < (int)s.size());
	assert(s[pos] == ')');
	++pos;
	return cur;
}

int main() {
	int tc;
	char feature[12];
	gets(line);
	sscanf(line, "%d", &tc);
	for (int scen=1; scen<=tc; ++scen) {
		printf("Case #%d:\n", scen);
		gets(line);
		int l;
		sscanf(line, "%d", &l);
		s = "";
		while(l--) {
			gets(line);
			s += line;
			s += " ";
		}
		pos = 0;
		dtree *root = parse();
		int a, n;
		scanf("%d", &a);
		while(a--) {
			double log_sum = 0;
			bool zero = false;
			scanf("%*s %d", &n);
			vector<string> features;
			for (int i=0; i<n; ++i) {
				scanf("%s", feature);
				features.push_back(feature);
			}
			sort(features.begin(), features.end());
			dtree *cur = root;
			while(1) {
				if (cur->weight == 0.0)
					zero = true;
				else
					log_sum += log(cur->weight);
				if (cur->has_it != NULL) {
					if (binary_search(features.begin(), features.end(), cur->feature))
						cur = cur->has_it;
					else
						cur = cur->has_not;
				}
				else
					break;
			}
			if (zero)
				puts("0.000000");
			else
				printf("%.6lf\n", exp(log_sum));
		}
		delete root;
		gets(line);
	}
	return 0;
}
