#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(auto i: c)
#define SORT(c) sort((c).begin(),(c).end())

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	VI A(N + 2);
	REP(i, N) cin >> A[i + 1];
	A[0] = A[N + 1] = 0;

	LL sum = 0;
	FOR(i, 0, N + 1){
		sum += abs(A[i] - A[i + 1]);
	}

	FOR(i, 1, N + 1){
		LL tmp = 0;
		tmp -= abs(A[i - 1] - A[i]) + abs(A[i] - A[i + 1]);
		tmp += abs(A[i - 1] - A[i + 1]);
		cout << sum + tmp << endl;
	}

	return 0;
}