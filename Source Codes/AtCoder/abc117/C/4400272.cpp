#include <iostream>
#include <vector>

using namespace std;


int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v(M);
	for(auto &x: v) cin >> x;

	sort(v.begin(), v.end());

	vector<int> l(M-1);

	for(int i = 0; i < M - 1; i++) {
		l[i] = v[i+1] - v[i];
	}

	sort(l.begin(), l.end());

	int out = 0;

	for(int i = 0; i < M - N; i++) {
		out += l[i];
	}

	cout << out << endl;

}