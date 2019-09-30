#include<iostream>
using namespace std;

int main(){

	int x, a, b;
	cin >> x >> a >> b;
	if(b-a <= 0){
		cout << "delicious\n";
	}
	else if(b-a <= x){
		cout << "safe\n";
	}
	else if(b-a > x){
		cout << "dangerous\n";
	}

	return 0;

}