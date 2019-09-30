#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

int main(){
	string s;
	cin >> s;
	int n = s.size();
	int p = 0, g = 0;
	for(char c : s){
		if(c == 'p'){
			p++;
		}else{
			g++;
		}
	}
	int mp = n / 2, mg = n - mp;
	// int dp = mp - p, dg = g - dg;
	cout << mp - p << endl;
	// cout << (n % 2 == 0 ? 0 : -1) - p_g << endl;
	return 0;
}