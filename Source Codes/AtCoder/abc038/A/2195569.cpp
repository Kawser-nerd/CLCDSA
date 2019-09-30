#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	string s;
	char si;
	cin >> s;
	si = s.back();
	if(si == 'T'){
		cout << "YES" <<endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;

}