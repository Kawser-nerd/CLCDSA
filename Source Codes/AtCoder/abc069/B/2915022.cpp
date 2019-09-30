#include <iostream>
using namespace std;

int main(void){
	string s;
	cin >> s;
	int l = s.length();
	cout << s[0] << l-2 << s[l-1] << endl;
	return 0;
}