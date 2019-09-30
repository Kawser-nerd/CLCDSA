#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <cmath>

using namespace std;

int func(int p){
	int count = 0;
	while(true){
		if(p%2==0){
			p = p / 2;
			count++;
		}else{
			break;
		}
	}
	return count;
}

int main(void){
	int n; int sum = 0;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		sum += func(arr[i]);
	}
	cout << sum << endl;
	return 0;
}