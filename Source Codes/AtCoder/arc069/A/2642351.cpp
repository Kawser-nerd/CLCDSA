#include <iostream>
using namespace std;

int main() {
	long long n,m;
	cin>>n>>m;
	if (n==m) cout<<m/2;
	else if (n>m) cout<<m/2;
	else cout<<((m/2)+n)/2;
	return 0;
}