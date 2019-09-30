#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dis(int x1, int x2, int y1, int y2){
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main(){
	
	int x1, x2, x3, y1, y2, y3, r;
	cin >> x1 >> y1 >> r;
	cin >> x2 >> y2 >> x3 >> y3;
	
	if(x2 + r <= x1 && x3 - r >= x1 && y2 + r <= y1 && y3 - r >= y1){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}
	
	r *= r;
	
	if(dis(x1, x2, y1, y2) <= r && dis(x1, x3, y1, y2) <= r && dis(x1, x2, y1, y3) <= r && dis(x1, x3, y1, y3) <= r){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}
	
	return 0;
}