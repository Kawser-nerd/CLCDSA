#include<iostream>
#include <string>
#include<algorithm>
#include<functional>
using namespace std;


int main() {
	int num[100];
	int n, k,count=0;
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		cin >> num[i];
	}
	    sort(num, num + n);
		reverse(num, num + n);
	
	for (int j = 0;j < k;j++) {
		count += num[j];
	}
	cout << count << endl;
}