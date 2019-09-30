#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	int x;
	cin >> x;
	int iti,ni;
	iti = x%10;
	ni = x/10;
	cout << iti + ni << endl;

	return 0;

}