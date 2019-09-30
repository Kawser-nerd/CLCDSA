#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 2000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int grid[1000][1000] = {};
int main() {
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	if (H % h != 0) {
		cout << "Yes" << endl;
		for (int i = 0;i < H;++i) {
			for (int q = 0;q < W;++q) {
				if (i % h == h - 1) {
					grid[i][q] = -10000 * (h - 1) - 1;
				}
				else {
					grid[i][q] = 10000;
				}
			}
		}
	}
	else if (W % w != 0) {
		cout << "Yes" << endl;
		for (int i = 0;i < H;++i) {
			for (int q = 0;q < W;++q) {
				if (q % w == w - 1) {
					grid[i][q] = -10000 * (w - 1) - 1;
				}
				else {
					grid[i][q] = 10000;
				}
			}
		}
	}
	else {
		cout << "No" << endl;
		return 0;
	}
	for (int i = 0;i < H;++i) {
		for (int q = 0;q < W;++q) {
			cout << grid[i][q] << " ";
		}
		cout << endl;
	}
	return 0;
}