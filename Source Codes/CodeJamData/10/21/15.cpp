#include <string>
#include <cctype>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <memory.h>
#include <assert.h>
using namespace std;
#define SZ(a) (int)(a).size()
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define REP(i,n) for (int i=0; i<(n); ++i)
#define ALL(c) c.begin(), c.end()
#define CLR(c,n) memset(c,n,sizeof(c))
#define TR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define CONTAIN(container, it) (container.find(it)!=container.end())
#define CLR(container, val) memset(container, val, sizeof(container))
#define MCPY(dest,src) memcpy(dest,src,sizeof(src))
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
const double EPS=1e-9;
const double PI=acos(-1);
const int INF=0x3F3F3F3F;
int main(int argc, char *argv[])
{
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int test_case;
	scanf("%d", &test_case);
	for (int test_case_id=1; test_case_id<=test_case; ++test_case_id) {
		fprintf(stderr, "Case %d of %d\n", test_case_id, test_case);
		printf("Case #%d: ", test_case_id);
		int n, m;
		set<string> exists, todo;
		exists.insert("/");
		string s;
		cin>>n>>m;
		while (n--) {
			cin>>s; s+="/";
			REP(i,SZ(s)) if (i&&s[i]=='/') exists.insert(s.substr(0,i));
		}
		while (m--) {
			cin>>s; s+="/";
			REP(i,SZ(s)) if (i&&s[i]=='/'&&!CONTAIN(exists,s.substr(0,i))) todo.insert(s.substr(0,i));
		}
		cout << todo.size() << endl;
	}
}

