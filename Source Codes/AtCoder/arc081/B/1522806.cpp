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
using namespace std;
#define eps 0.00000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	long long ans = 1;
	int back = 0;
	for (int i = 0;i < n;++i) {
		if (a[i] == b[i]) {
			if (back == 0) {
				ans *= 3;
				back = 1;
			}
			else if(back == 1){
				ans *= 2;
			}
			else {
				ans *= 1;
				back = 1;
			}
		}
		else {
			if (back == 0) {
				ans *= 6;
				back = 2;
			}
			else if (back == 1) {
				ans *= 2;
				back = 2;
			}
			else {
				ans *= 3;
				back = 2;
			}
			i++;
		}

		ans		%= MAX_MOD;
	}
	cout << ans << endl;
	return 0;
}