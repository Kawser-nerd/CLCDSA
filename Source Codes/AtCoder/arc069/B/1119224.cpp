#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>
#include <climits>
 
using namespace std;
 
#define FOR(k,a,b) for(int k=(a); k < (b); k++)
#define FORE(k,a,b) for(int k=(a); k <= (b); k++)
#define REP(k,a) for(int k=0; k < (a); k++)
 
#define ALL(c) (c).begin(), (c).end()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define RANGE(lb, x, ub) ((lb) <= (x) && (x) < (ub))
 
#define dump(x) cerr << #x << ": " << (x) << endl;
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
 
const int INF = 1000000000;
const double EPS = 1e-10;
const double PI = acos(-1.0);

bool test(int n, string &s, string &result) {
	REP(i, n) {
		int prev = (i - 1 + n) % n;
		int next = (i + 1) % n;
		if (s[i] == 'o') {
			if ((result[i] == 'S' && result[prev] == result[next]) ||
			(result[i] == 'W' && result[prev] != result[next])) {}
			else {
				return false;
			}
		} else {
			if ((result[i] == 'S' && result[prev] != result[next]) ||
			(result[i] == 'W' && result[prev] == result[next])) {}
			else {
				return false;
			}
		}
	}
	return true;
}

string fill(int i, int n, string &s, string &result) {
	int prev = (i - 1 + n) % n;
	char kind = result[i];
	char prev_kind = result[prev];
	char answer = s[i];

	if (i == n - 1) {
		return test(n, s, result) ? result : "";
	}

	if (answer == 'o') {
		if (kind == 'S') {
			result[i + 1] = prev_kind;
		} else {
			result[i + 1] = (prev_kind == 'S') ? 'W' : 'S';
		}
	} else {
		if (kind == 'S') {
			result[i + 1] = (prev_kind == 'S') ? 'W' : 'S';
		} else {
			result[i + 1] = prev_kind;
		}
	}

	return fill(i + 1, n, s, result);
}
 
int main(void) {
	int n; cin >> n;
	string s; cin >> s;

	string tmp = "";
	REP(i, n) tmp += ' ';

	tmp[0] = 'S'; tmp[1] = 'S';
	if (fill(1, n, s, tmp) != "") {
		cout << tmp << endl;
		return 0;
	}

	tmp[0] = 'S'; tmp[1] = 'W';
	if (fill(1, n, s, tmp) != "") {
		cout << tmp << endl;
		return 0;
	}

	tmp[0] = 'W'; tmp[1] = 'S';
	if (fill(1, n, s, tmp) != "") {
		cout << tmp << endl;
		return 0;
	}

	tmp[0] = 'W'; tmp[1] = 'W';
	if (fill(1, n, s, tmp) != "") {
		cout << tmp << endl;
		return 0;
	}
	
	cout << "-1" << endl;

    return 0;
}