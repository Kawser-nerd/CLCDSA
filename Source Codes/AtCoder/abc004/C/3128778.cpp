#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	int n;
	int a[] = {1,2,3,4,5,6};
	cin >> n;
	for(int i = 0; i < n; ++i){
		int temp = a[i%5];
		a[i%5] = a[i%5+1];
		a[i%5+1] = temp;
	}
	for(int i = 0; i < 6; ++i){
		cout << a[i];
	}
	cout << endl;
	return 0;
}