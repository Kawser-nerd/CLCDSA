#include <iostream>
using namespace std;

int main(){
	char a , b;
	cin >> a >> b;
	cout << (a == toupper(b) ? "Yes" : "No") << endl;
}