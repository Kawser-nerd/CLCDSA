#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int T, teste;
int diana, tower, n;
pii mon[200];

int pd[200][410000];

int rec(int v, int fr) {
	if (v == n) return 0;

	int &ret = pd[v][fr];
	if (ret == -1) {
		ret = rec(v+1, fr + (mon[v].first + tower - 1) / tower);

		int needs, spends;
		
		spends = mon[v].first / tower;
		if (spends*tower == mon[v].first) spends--;

		fr += spends;
		needs = ((mon[v].first - spends*tower) + diana - 1) / diana;
		if (needs <= fr) ret = max(ret, mon[v].second + rec(v+1, fr - needs));
		
	}
	return ret;
}

int main() {
	for (scanf("%d", &T) ;T ;T--) {
		memset(pd,-1,sizeof(pd));

		printf("Case #%d: ", ++teste);
		scanf("%d %d %d", &diana, &tower, &n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &mon[i].first, &mon[i].second);
		}

		printf("%d\n", rec(0, 1));
	}	
}