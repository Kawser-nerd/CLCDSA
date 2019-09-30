#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	long Q,H,S,D,N;
	cin >> Q >> H >> S >> D >> N;

	double ql = 0.25,
		   hl = 0.5,
		   sl = 1,
		   dl = 2;

	vector<long> l1 = {Q*4, H*2, S};
	vector<long> l2 = {Q*8, H*4, S*2, D};
	sort(l1.begin(), l1.end());
	sort(l2.begin(), l2.end());

	double nowl = 0;
	long nowM = 0;

	while(nowl <= N-2){
		nowl += 2;
		nowM += l2[0];
		//cout << nowl << ":" << nowM << endl;
	}

	if(N%2 == 1){
		nowM += l1[0];
	}
	cout << nowM << endl;
}