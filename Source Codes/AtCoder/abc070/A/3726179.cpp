#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int hun = n/100;
	int one = n%10;
	if(hun == one){cout << "Yes" <<endl;}
	else{cout << "No" <<endl;}
	return 0;
}