#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
 
using namespace std;
 
const int len = 200010;
int a[len],n,k;
 
int main() {
	cin >> n;
	long long sum = 0;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		sum += a[i];
	}
	long long mn = 1e18;
	long long s = 0;
    if  (n == 2) {
    	cout << abs(a[1]-a[2]) << endl;
	}
	else {
		for (int i=1;i<n;i++) {
			s += a[i];
			sum -= a[i];
			mn = min(mn,abs(s-sum));
		}
		cout << mn << endl;
    }
	return 0;
} ./Main.cpp:13:1: warning: treating Unicode character as whitespace [-Wunicode-whitespace]
 
^
./Main.cpp:15:1: warning: treating Unicode character as whitespace [-Wunicode-whitespace]
 
^
./Main.cpp:18:1: warning: treating Unicode character as whitespace [-Wunicode-whitespace]
 
^
3 warnings generated.