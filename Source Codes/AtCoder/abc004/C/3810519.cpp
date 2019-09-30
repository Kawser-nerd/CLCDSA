#include <iostream>
using namespace std;
int main()
{
	int n,tmp;
	int m[6] = {1,2,3,4,5,6};
	cin >> n;
	for(int i=0;i<n%30;i++){
		tmp = m[i%5];
		m[i%5] = m[i%5 + 1];
		m[i%5 + 1] = tmp;
	}
	
	for(int j=0;j<6;j++){
		cout << m[j];
	}
	cout << endl;
	
	return 0;
}