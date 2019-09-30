#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int main() {
	int a,b,k;
	cin >> a >> b >> k;
	map<int,bool> m;
	vector<int> v;
	for(int i = 0; i < k; i++) {
		if(a + i <= b) {
			v.push_back(a + i);
			m[a + i] = true;
		}
	}
	for(int i = k - 1; i >= 0; i--) {
		if(b - i >= a && !m[b - i]) {
			v.push_back(b - i);
			m[b - i] = true;
		}
	}

	for(int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
	
	
}