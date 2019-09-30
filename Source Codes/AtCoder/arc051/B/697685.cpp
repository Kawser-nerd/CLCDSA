#include <iostream>
using namespace std;
typedef long long ll;

int main(){
	int K;
	cin >> K;
	ll a = 2, b = 1;
	--K;
	while(K--){
		ll c = a;
		a = a + b;
		b = c;
	}
	cout << a << " " << b << endl;
	return 0;
}