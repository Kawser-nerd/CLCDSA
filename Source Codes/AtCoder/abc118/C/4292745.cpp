#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, x;

int gcd(int a, int b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}

int main() {
	cin >> n;
	vector<int> a;
	for (int i=0;i<n;i++) {cin >> x; a.push_back(x);}
	x=gcd(a[0], a[1]); for (int i=0;i<n;i++) x=gcd(a[i], x);
	cout << x << endl;
	return 0;
}