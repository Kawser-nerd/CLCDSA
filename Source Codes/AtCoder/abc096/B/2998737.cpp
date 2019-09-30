#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main(void){
	int a,b,c,k;
	cin >> a >> b >> c >> k;
	cout << max(max(a,b),c)*pow(2,k)+a+b+c-max(max(a,b),c) << endl;

	return 0
	;
}