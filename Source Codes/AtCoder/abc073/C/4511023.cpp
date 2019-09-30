#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int nums;
	map<string,bool> a;
	scanf("%d", &nums);
	map<string, bool> ::iterator it;
	for (int i = 0; i < nums; i++) {
		string temp;
		cin >> temp;
		it = a.find(temp);
		if (it != a.end()) a.erase(it);
		else a[temp] = 1;
	}
	cout << a.size();
	return 0;
}