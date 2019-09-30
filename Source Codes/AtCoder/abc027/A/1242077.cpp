#include<iostream>

using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	
	int res;
	if(a == b) res = c; 
	if(a == c) res = b;
	if(b == c) res = a;
	cout << res << endl;
}