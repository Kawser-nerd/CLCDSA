#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;


int main(void){
	int n,k;
	vector<int>r;
	cin >> n >> k;
	r.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> r[i];
	}
	sort(r.begin(), r.end());
	double c = 0;
	for(int i = n - k; i < n; ++i){
		c = (c + (double)r[i]) / 2;
	}
	printf("%.9lf\n", c);
}