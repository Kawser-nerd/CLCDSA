//Aho
#include<iostream>
#include<string>
#define rep(i, n) for (int(i) = 0; (i)<(n); (i)++)
#define rep2(i, a, b) for (int(i) = (a); (i)<(b); (i)++)
#define rrep(i, n) for (int(i) = (n - 1); (i) >= 0; (i)--)
#define rrep2(i, a, b) for (int(i) = (a - 1); (i) >= b; (i)--);
using namespace std;

int main() {
	char a[2500];
	int k;
	int N;
	int i;

	cin >> N;
	for (i = 0; i < N*N; i++) cin >> a[i];

	if(N!=1){
		k = N*N - N;
		for (i = 0; i < N*N; i++) {
			cout << a[k - (N*(i%N))];
			if (!((i + 1) % N)) {
				k = N*N - N + ((i + 1) / N);
				cout << endl;
			}
		}
	}
	else cout << a[0];
	return 0;

}