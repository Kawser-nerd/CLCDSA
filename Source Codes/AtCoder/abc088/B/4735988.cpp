#include <iostream>
using namespace std;

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

long long N, A[110], als, bob;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	sort(A, A + SIZE_OF_ARRAY(A), greater<long long>());
	
	als += A[0];
	for (int i = 1; i < N; i++) {
		if (i % 2 == 0) {
			als += A[i];
		} else {
			bob += A[i];
		}
	}
	
	cout << als - bob << endl;
	return 0;
}