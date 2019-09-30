#include <iostream>
using namespace std;

int main() {
	char a,b;
	cin>>a>>b;
	if (a=='H') cout<<b;
	else if (a=='D') {
		if (b=='H') cout<<'D';
		else if (b=='D') cout<<'H';
	}
	return 0;
}