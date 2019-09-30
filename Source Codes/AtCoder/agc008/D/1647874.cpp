#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
#define eps 0.00000000000000000000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)                                                                             
#define seg_size 524288
int grid[2000000] = {};
map<int, int> geko;
vector<pair<int, int>> wow;
vector<int>x;
int main() {
	int n;
	cin >> n;
	while (true) {
		for (int i = 0;i < 500000;++i) grid[i] = 0;
		REP(i, n) {
			int geko;
			cin >> geko;
			x.push_back(geko);
			wow.push_back(make_pair(geko, i + 1));
			if (grid[geko] != 0) {
				cout << "No" << endl;
				return 0;
			}
			grid[geko] = i + 1;
		}
		sort(wow.begin(), wow.end());
		//?????
		int now_itr = n - 1;
		int now_filled = wow[now_itr].second;
		if (now_filled == n) {
			if (now_itr != 0) {
				now_itr--;
				now_filled = wow[now_itr].second;
			}
		}
		for (int i = n*n;i >= 1;--i) {
			if (grid[i] == false) {
				grid[i] = wow[now_itr].second;
				now_filled++;
			fo2:;
				if (now_filled == n) {
					if (now_itr == 0) {
						break;
					}
					now_itr--;
					now_filled = wow[now_itr].second;
					goto fo2;
				}
			}
		}
		now_itr = 0;
		now_filled = wow[now_itr].second - 1;
		if (now_filled == 0) {
			if (now_itr != n - 1) {
				now_itr++;
				now_filled = wow[now_itr].second - 1;
			}
		}
		for (int i = 1;i <= n*n;++i) {
			if (grid[i] == false) {
				grid[i] = wow[now_itr].second;
				now_filled--;
			fo1:;
				if (now_filled == 0) {
					now_itr++;
					if (now_itr == n) {
						break;
					}
					now_filled = wow[now_itr].second - 1;
					goto fo1;
				}
			}
		}
		for (int i = 1;i <= n*n;++i) {
			if (grid[i] == 0) {
				cout << "No" << endl;
				return 0;
			}
			geko[grid[i]]++;
			if (geko[grid[i]] == grid[i]) {
				if (i != x[grid[i] - 1]) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
		cout << "Yes" << endl;
		for (int i = 1;i <= n*n;++i) {
			cout << grid[i] << " ";
		}
		cout << endl;
		return 0;
	ok:;
	}
	return 0;
}