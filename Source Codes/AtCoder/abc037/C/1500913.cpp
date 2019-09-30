#include <iostream>
#include "string.h"
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,K;
	cin >> N >> K;
	vector<int> a(N);
	for(int i = 0;i < N;i++) cin >> a[i];
	long long sum = 0;
	for(int i = 0; i < N - K + 1;i++){
		int count = 0;
		for(int j = i;count < K;j++){
			sum += a[j];
			count += 1;
		}
	}
	cout << sum << endl;
	return 0;
}