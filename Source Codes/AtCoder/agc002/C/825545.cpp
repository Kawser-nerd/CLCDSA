#include<iostream>
#include<vector>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
using ulong = unsigned long;
using ll = long long;

void out(int last, int n){
	for(int i=1;i<last;i++){
		cout << i << endl;
	}
	for(int i=n-1;i>=last;i--){
		cout << i << endl;
	}
}

int main(){
	int n, l;
	cin >> n >> l;
	int prev;
	cin >> prev;
	for(int i=1;i<n;i++){
		int a;
		cin >> a;
		if(prev + a >= l){
			cout << "Possible" << endl;
			out(i, n);
			return 0;
		}
		prev = a;
	}
	cout << "Impossible" << endl;
	return 0;
}