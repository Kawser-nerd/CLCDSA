#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N, Q; cin >> N >> Q;
	string S; cin >> S;
	vector<int> l(Q+1, 0), r(Q+1, 0);
	for(int i = 1; i <= Q; i++) cin >> l[i] >> r[i];

	vector<int> cumlativeS(N+1, 0);

	for(int i = 2; i <= N; i++) {
		if(S[i-2] == 'A' && S[i-1] == 'C') {
			cumlativeS[i] = cumlativeS[i-1] + 1;
		} else {
			cumlativeS[i] = cumlativeS[i-1];
		}
	}

/*
	for(int i = 0; i < S.length()+1; i++) {
		cout << cumlativeS[i] << " ";
	}
	cout << endl;
*/

	for(int i =1; i <= Q; i++) {
		cout << cumlativeS[r[i]] - cumlativeS[l[i]] << endl;
	}
}