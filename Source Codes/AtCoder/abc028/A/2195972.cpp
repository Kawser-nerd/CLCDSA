#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	int n;
	cin >> n;
	if(n<=59){
		cout << "Bad" << endl;
	}
	else if(n<=89){
		cout << "Good" <<endl;
	}
	else if(n<=99){
		cout << "Great" <<endl;
	}
	else if(n==100){
		cout << "Perfect" <<endl;
	}

	return 0;

}