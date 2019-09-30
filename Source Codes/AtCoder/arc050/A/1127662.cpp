#include <iostream>
using namespace std;

int main(){
	char a,b;
	cin >> a >> b;
	if(a - ('A' - 'a') == b) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}