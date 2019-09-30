#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 300010;
int sumW[MAXN]; //include.
int main() {
	int n;
	int totW=0;
	cin>>n;
	for (int i=0; i<n; i++) {
		char c;
		cin>>c;
		sumW[i] = (i>0?sumW[i-1]:0) + (c=='W'?1:0);
		if (c=='W')
			totW++;
	}
	int ans=MAXN;
	for (int i=0; i<n; i++) {
		int leftW = (i>0?sumW[i-1]:0);
		int rightE = n - (i+1) - (totW-sumW[i]);
		ans = min(ans, leftW+rightE);
	}
	cout<<ans<<endl;
	return 0;
}