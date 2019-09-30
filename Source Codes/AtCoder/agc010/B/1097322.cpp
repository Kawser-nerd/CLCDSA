#include <iostream>
#include <vector>

using namespace std;

bool solve(const vector<int>& a){
	long long n = a.size();
	long long sumN = n*(n+1)/2;
	long long sum = 0;
	for(int i=0;i<n;i++) sum += a[i];
	if(sum%sumN != 0) return false;
	long long sumC = sum/sumN;
	long long cntC = 0;
	for(int i=0;i<n;i++){
		long long dif = a[i] - a[(i+n-1)%n];
		if(sumC - dif < 0) return false;
		if((sumC - dif)%n != 0) return false;
		cntC += (sumC-dif)/n;
	}
	return cntC == sumC;
}

int main(){
	int N;
	while(cin >> N){
		vector<int> a(N);
		for(int& t : a) cin >> t;
		cout << (solve(a) ? "YES" : "NO") << endl;
	}
}