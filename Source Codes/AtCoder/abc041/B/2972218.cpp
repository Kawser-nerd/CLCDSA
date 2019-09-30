#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007

int main(void){
	long long a,b,c;
	cin >> a >> b >> c;
	cout << a %MOD * b %MOD * c %MOD << endl;
	return 0;
}