#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s,ans = "";
	cin >> s;
	for(int i= 0;i<s.length();i+=2){
		ans+=s[i];
	}
	cout << ans << endl;
	return 0;
}