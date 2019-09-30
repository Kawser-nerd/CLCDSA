#include <iostream>
using namespace std;
int main(){
	int n,k,x,ans=0;

	cin >> n >> k;
	for (int i=0;i<n;i++ ) {
		cin >> x;
		if (x > k - x){
			ans += 2*(k-x);
		}else{
			ans += 2*x;
		}
	}
	cout << ans << endl;

	return 0;
}