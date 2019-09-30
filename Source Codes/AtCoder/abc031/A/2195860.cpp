#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	int a, d;
	cin >> a >> d;
	if((a+1)*d >= a*(d+1)){
		cout << (a+1)*d <<endl;
	}
	else{
		cout << a*(d+1) <<endl;
	}

	return 0;

}