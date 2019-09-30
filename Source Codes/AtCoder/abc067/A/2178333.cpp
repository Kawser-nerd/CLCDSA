#include<iostream>
using namespace std;

int main(){

	int a, b, mochi;
	cin >> a >> b;
	mochi = a+b;

	if(a%3 == 0){
		cout <<"Possible\n";
	}
	else if(b%3 == 0){
		cout <<"Possible\n";
	}
	else if(mochi%3 == 0){
		cout <<"Possible\n";
	}
	else{
		cout <<"Impossible\n";
	}

	return 0;

}