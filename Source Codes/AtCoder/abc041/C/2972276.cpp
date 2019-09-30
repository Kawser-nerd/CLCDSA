#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main(void){
	map<int, int> mp;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		mp.insert(make_pair(temp,i));
	}
	for(auto x = mp.rbegin(); x != mp.rend(); ++x){
		cout << x->second + 1 << endl;
	}
	return 0;
}