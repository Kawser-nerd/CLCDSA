#include<iostream>

using namespace std;

int main(){

	char r,s;

	cin >> r >> s;

	if(r == 'A'-'a'+s){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}