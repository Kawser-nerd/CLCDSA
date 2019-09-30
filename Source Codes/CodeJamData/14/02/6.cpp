#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main() {
	int _; cin >> _; 
	for (int __ = 1; __ <= _; __ ++) {
		double c, f, x; 
		cin >> c >> f >> x; 
		printf ("Case #%d: ", __); 
		double lt = 0; 
		double S = x/2; 
		for (int i = 0; i <= 100000; i ++) {
			S = min(S, lt+x/(i*f+2)); 
			lt += c/(i*f+2); 
		}
		printf ("%.9lf\n", S); 
	}
	return 0; 
}