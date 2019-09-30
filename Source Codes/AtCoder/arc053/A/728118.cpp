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
	int h, w;
	cin >> h >> w;
	cout << w * (h - 1) + h * (w - 1) << endl;
	return 0;
}