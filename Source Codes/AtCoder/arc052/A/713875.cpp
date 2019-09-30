#include<iostream>
#include<string>

using namespace std;

int main(){
	string s;

	cin >> s;

	int i = 0;

	while(s[i] != '\0'){

		if('0' <= s[i] && s[i] <= '9')cout << s[i] ;
		i++;
	}

	cout << endl;

	return 0;
}