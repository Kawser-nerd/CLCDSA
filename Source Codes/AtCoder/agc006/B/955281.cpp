#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

int main(){
	int n, x;
	cin >> n >> x;
	int s = x - n;
	if(x == 1 || x == 2*n-1){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for(int i=0;i<2*n-1;i++){
		cout << (s + i + 2*n-1) % (2*n-1) + 1 << endl;
	}
	return 0;
}