#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	vector<int> a(200000,0);
	int n, k, at;
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		cin >> at;
		a[at]++;
	}
	sort(a.rbegin(), a.rend());
	int sum = 0;
	int count = 0;
	for(auto x: a){
		if(x != 0){
			count++;
		}
	}
	for(int i = 0; i < k; ++i){
			sum += a[i];
	}
		cout << n - sum  << endl;
	return 0;
}