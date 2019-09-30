#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
	
	int K;
	cin >> K;
	
	int a = 1;
	int b = 1;
	
	for(int i = 0; i < K; i++){
		int num = a + b;
		b = a;
		a = num;
	}
	
	cout << a << " " << b << endl;
	
	return 0;
}