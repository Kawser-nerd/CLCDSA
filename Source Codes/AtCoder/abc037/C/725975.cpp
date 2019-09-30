#include <iostream>

using namespace std;

int main(void){
	int n,k;
	long long int sum = 0;
	cin >> n >> k;
	long long int a[n], b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
		if(i > 0){
			b[i] += b[i-1];
		}
	}
	sum += b[k-1];
	for(int i = 0; i < n - k; i++){
		sum += b[k+i] - b[i];
	}
	cout << sum << endl;
	return 0;
}