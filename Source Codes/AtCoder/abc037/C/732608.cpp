//
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <array>
#include <numeric>
#include <functional>

#define rep(i,n) for(int i=0;i<n;i++)
#define scanInt(i) scanf("%d", &i)

using namespace std;

int main(){

	int n, k;
	cin >> n >> k;

	long long a[n];
	rep(i,n){
		cin >> a[i];
	}

	vector<long long int>s(n+1, 0);
	s[0] = a[0];
	for(int i=1; i<n+1; i++){
		s[i] = s[i-1] + a[i-1];
	}

	long long int sum = 0;
	for(int i=0; i<n-k+1; i++){
		sum += s[i+k] - s[i];
		// cout << sum << endl;
	}
	cout << sum << endl;

	return 0;
}