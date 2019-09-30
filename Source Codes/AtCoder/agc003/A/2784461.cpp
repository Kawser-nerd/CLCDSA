#include <iostream>
using namespace std;

string STR;
bool N, S, E, W;


int main() {
	cin >> STR;
	
	for(char c : STR) {
		if(c == 'N')
			N = true;
		if(c == 'E')
			E = true;
		if(c == 'W')
			W = true;
		if(c == 'S')
			S = true;
	}
	
	if((N + S) % 2 || (E + W) % 2) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	
	
	
	return 0;
}