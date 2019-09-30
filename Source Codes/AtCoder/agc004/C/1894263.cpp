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
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int grid[1000][1000] = {};
int main() {
	int h, w;
	cin >> h >> w;
	for (int i = 0;i < h;++i) {
		string s;
		cin >> s;
		for (int q = 0;q < w;++q) {
			if (s[q] == '#') grid[i][q] = 1;
		}
	}
	for (int i = 0;i < h;++i) {
		for (int q = 0;q < w;++q) {
			if (q == 0 || q == w - 1 || i == 0 || i == h - 1||grid[i][q] == 1) {
				cout << "#";
			}else if(i % 2 == 1 && q != 1){
				cout << "#";
			}
			else cout << ".";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0;i < h;++i) {
		for (int q = 0;q < w;++q) {
			if ((q == 1&&i != 0&&i != h-1) || grid[i][q] == 1 || (i % 2 == 0 && i != 0 && i != h - 1 && q != 0 && q != w - 1)) {
				cout << "#";
			}
			else cout << ".";
		}
		cout << endl;
	}
	return 0;
}