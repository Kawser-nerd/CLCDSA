#include <iostream>
using namespace std;

int main() {
	long long res=1,n;
	cin>>n;
	for (int i=1;i<=n;i++){
		res=(res*i)%1000000007;
	}
	cout<<res;
	return 0;
}