#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin >> a >> b >>c;
	if(a>=b && a>=c){cout << b+c <<endl;}
	else if(b>=a && b>=c){cout << a+c <<endl;}
	else if(c>=a && c>=b){cout << a+b <<endl;}
	return 0;
}