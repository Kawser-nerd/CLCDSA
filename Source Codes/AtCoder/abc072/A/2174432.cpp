#include<iostream>
using namespace std;

int main(){

	int X, t;

	cin >> X >> t;

	if (X <= t){
		cout << 0;
	}
	else{
		cout << X - t;
	}


	return 0;
}