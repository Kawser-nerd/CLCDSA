#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	int a, s, d;
	cin >> a >> s >> d;
	if(a==s){
		cout << d <<endl;
	}
	else if(a==d){
		cout << s <<endl;
	}
	else{
		cout << a <<endl;
	}

	return 0;

}