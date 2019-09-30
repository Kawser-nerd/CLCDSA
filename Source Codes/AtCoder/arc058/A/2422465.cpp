//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
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

#define SORT(c) sort((c).begin(),(c).end())
#define ANS(ans) cout<<(ans)<<endl;
typedef vector<int> VI;


//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for (int i = 0; i < (n); ++i)

int vector_finder(vector<int> vec, int number) {
	auto itr = find(vec.begin(), vec.end(), number);
	size_t index = distance(vec.begin(), itr);
	if (index != vec.size()) { // ???????
		return 1;
	}
	else { // ??????????
		return 0;
	}
}


int main() {
	int n, k;
	cin >> n >> k;
	VI v(k);
	REP(i, k) {
		cin >> v[i];
	}
	SORT(v);

	string s;
	int f = 1;
	FOR(i, n, 10 * n) {
		s = to_string(i);
		f = 1;
		REP(j, s.size()) {
			if (vector_finder(v, s[j] - '0')==1) {
				f = 0;
				break;
			}
		}
		if (f == 1) {
			cout << i << endl;
			return 0;
		}

	}




	return 0;
}