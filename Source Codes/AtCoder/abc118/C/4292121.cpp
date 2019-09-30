#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n, x, m = INT_MAX, gcd_;

int gcd(int a, int b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}

int main() {
	int whe;
	cin >> n;
	vector<int> a;
	for (int i=0;i<n;i++) {cin >> x; a.push_back(x);}
	gcd_=gcd(a[0],a[1]); for (int i=0;i<n;i++) gcd_=gcd(a[i],gcd_);
	cout << gcd_ << endl;
	return 0;
}