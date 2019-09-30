#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <cmath>

using namespace std;

int power(int m){
	int ret = 1;
	for(int i=1;i<=m;i++){
		ret *= 100;
	}
	return ret;
}

int main(void){
	int d, n;
	cin >> d >> n;
	if(n!=100){
		cout << n * power(d) << endl;
	}else{
		cout << power(d) * 101 << endl;
	}
	return 0;
}