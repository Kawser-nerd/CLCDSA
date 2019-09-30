#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <complex>
using namespace std;


int main(void){
	int a, b;
	string s1, s2;
	cin >> s1 >> s2;
	string s3 = s1 + s2;
	int n = atoi(s3.c_str());
	if((int)sqrt(n) * (int)sqrt(n) == n){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}