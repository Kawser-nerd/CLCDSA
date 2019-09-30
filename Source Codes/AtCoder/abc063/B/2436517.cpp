#include <iostream>
#include <map>
using namespace std;

int main() {
	char c;
	map<char, int> m;
	while(cin >> c){
		m[c] ? m[c]++ : m[c] = 1;
		if(m[c] == 2){
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;
	return 0;
}