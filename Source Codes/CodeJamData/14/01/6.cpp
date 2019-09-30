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
		int r1, r2; 
		int a[17], b[17]; 
		cin >> r1; 
		for (int i = 0; i < 4; i ++) {int x; cin >> x; a[x] = 1; }
		for (int i = 0; i < 4; i ++) {int x; cin >> x; a[x] = 2; }
		for (int i = 0; i < 4; i ++) {int x; cin >> x; a[x] = 3; }
		for (int i = 0; i < 4; i ++) {int x; cin >> x; a[x] = 4; }
		cin >> r2;
		for (int i = 0; i < 4; i ++) {int x; cin >> x; b[x] = 1; }
		for (int i = 0; i < 4; i ++) {int x; cin >> x; b[x] = 2; }
		for (int i = 0; i < 4; i ++) {int x; cin >> x; b[x] = 3; }
		for (int i = 0; i < 4; i ++) {int x; cin >> x; b[x] = 4; }
		int u = -1; 
		bool F = true; 
		for (int i = 1; i <= 16; i ++) 
			if (a[i] == r1 && b[i] == r2) {
				if (u == -1) u = i; else F = false; 
			}
		printf ("Case #%d: ", __); 
		if (!F) puts ("Bad magician!"); else
		if (u == -1) puts ("Volunteer cheated!"); else printf ("%d\n", u); 
	}
	return 0; 
}