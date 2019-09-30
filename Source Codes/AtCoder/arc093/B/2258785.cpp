#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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
#include <map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007 
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
using namespace std;
long long geko[200][200];
int main() {
	int a, b;
	cin >> a >> b;
	a--;
	b--;
	for (int i = 1; i <= 100; ++i) {
		for (int q = 1; q <= 100; ++q) {
			if (i <= 50) {
				geko[i][q] = 1;
			}
			else {
				geko[i][q] = 2;
			}
		}
	}
	for (int i = 2; b != 0; i += 2) {
		for (int q = 2; b != 0 && q <= 98; q += 2) {
			b--;
			geko[i][q] = 2;
		}
	}
	for (int i = 52; a != 0; i += 2) {
		for (int q = 2; a != 0 && q <= 98; q += 2) {
			a--;
			geko[i][q] = 1;
		}
	}
	cout << "100 100" << endl;
	for (int i = 1; i <= 100; ++i) {
		for (int q = 1; q <= 100; ++q) {
			if (geko[i][q] == 1) {
				cout << ".";
			}else cout << "#";
		}
		cout << endl;
	}
	return 0;
}