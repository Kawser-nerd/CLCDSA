#include <iostream>

using namespace std;
int main() {
	int pos[22];
	memset(pos, 0xff, sizeof(pos));

	int n;
	cin>>n;
	long long ans=0;
	int right = -1;
	for (int i=0; i<n; i++) {
		int a; cin>>a;
		for (int p=0; p<20; p++)
			if (a & (1<<p)) {
				right = max(right, pos[p]);
				pos[p] = i;
			}
		ans += i-right;
	}
	cout<<ans<<endl;
	return 0;
}