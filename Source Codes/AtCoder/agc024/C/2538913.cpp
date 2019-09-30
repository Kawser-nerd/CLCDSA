#include <iostream>

using namespace std;
int line[200001];
int linep_r[200001];

int main(){
	int N;
	long long A[200001];
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> A[i];
	}
	for (int i=0; i<N; i++) {
		long long line_n = i - A[i];
		if (line_n < 0) {
			cout << -1 << endl;
			return 0;
		}
		line[line_n] = line[line_n] > A[i] ? line[line_n] : A[i];
	}

	long long ans = 0;

	int linep_max = 0;
	for (int i=0; i<200001; i++) {
		linep_max = linep_max > line[i]+i ? linep_max : line[i]+i;
		linep_r[i] = linep_max;
	}
	for (int i=1; i<N; i++) {
		if (i <= linep_r[i-A[i]-1]) {
			cout << -1 << endl;
			return 0;
		}
	}

	for (int i=0; i<200001; i++) {
		ans += line[i];
	}
	cout << ans << endl;



	return 0;
}