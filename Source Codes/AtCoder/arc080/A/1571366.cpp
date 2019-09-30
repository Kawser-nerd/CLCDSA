#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<long> a(N);
	for(int i=0; i<N; i++) cin >> a[i];


	int odd = 0,
		four = 0,
		even = 0;

	for(int i=0; i<N; i++){
		if(a[i]%2 == 1)
			odd++;
		if(a[i]%4 == 0) {
			four++;
			continue;
		}
		if(a[i]%2 == 0)
			even++;
	}

	
	if(odd <= four || (odd == four+1 && even == 0))
		cout << "Yes" << endl;
	else cout << "No" << endl;
}