#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
 
int main(void){
	int t, v, xa, ya, xb, yb;
	cin >> xa >> ya >> xb >> yb >> t >> v;
	int n;
	cin >> n;
	bool flag = false;
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		double dis = sqrt(pow(abs(xa-x),2) + pow(abs(ya-y),2));
		dis += sqrt(pow(abs(xb-x),2) + pow(abs(yb-y),2));
		if(t * v >= dis){
			flag = true;
		}
	}
	if(flag){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}