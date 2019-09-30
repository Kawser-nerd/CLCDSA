#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
using ulong = unsigned long;
using ll = long long;

int main(){
	ll a, b, k, l;
	cin >> a >> b >> k >> l;
	cout << min(b * ((k -1)/ l + 1), b * (k / l) + a * (k - l * (k / l))) << endl;
	return 0;
}