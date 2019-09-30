#include <iostream>
using namespace std;
int main()
{
	int n,sum=0;;
	cin >> n;
	for(int i=1;i<=n;i++){
		sum += i*10000;
	}
	sum = sum/n;
	cout << sum << endl;
	return 0;
}