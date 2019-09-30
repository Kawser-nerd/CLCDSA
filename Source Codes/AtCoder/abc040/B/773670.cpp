#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int n;
	while (cin>>n) {
		int ofs = 9999;
		for (int i = 1; i <= 1000; i++) {
			for (int j = 1; j <= 1000; j++) {
				if (n >= i*j) ofs = min(ofs, abs(i - j) + n - i*j);
			}
		}
		cout << ofs << endl;
	}
}