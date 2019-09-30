#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
	long long N;
	cin >> N;
	int max = int(sqrt(N));

	int fmin_other = 1; 
	for (int i = 2; i < max + 1; i++) {
		if (N % i == 0) {
			fmin_other = i;
		}
	}

	int fmin = N / fmin_other;
	int keta = 0;
	for (int i = 1; i < N * 10 + 1; i = i * 10) {
		keta++;
		if (fmin / i == 0) {
			cout << keta - 1 << endl;
			break;
		}
	}
	return 0;
}