#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
using ulong = unsigned long;
using ll = long long;

int main(){
	string s;
	cin >> s;
	int az[26] = {};
	for(char c : s){
		az[c - 'a']++;
	}
	int odd = 0, pair = 0;
	for(int i : az){
		odd += i & 1;
		pair += i / 2;
	}
	bool allEven = false;
	if(!odd){
		odd++;
		allEven = true;
	}
	int sNum = pair / odd;
	cout << sNum * 2 + (allEven ? 0 : 1) << endl;
	return 0;
}