#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	string a,b,c;
	cin >> a >> b >> c;
	int A, B ,C;
	A = toupper(a[0]);
	B = toupper(b[0]);
	C = toupper(c[0]);
	cout << char(A) << char(B) << char(C) <<endl;

	return 0;

}