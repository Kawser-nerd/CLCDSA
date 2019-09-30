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
	double l, x, y, s, d;
	cin >> l >> x >> y >> s >> d;
	if(s > d){
		cout << fixed << setprecision(10) << min((d + (l - s)) / (y + x), x > y ? 1e12 : (s - d) / (y - x)) << endl;
	}else{
		cout << fixed << setprecision(10) << min((d - s) / (y + x), x > y ? 1e12 : (s + (l - d)) / (y - x)) << endl;
	}
	return 0;
}