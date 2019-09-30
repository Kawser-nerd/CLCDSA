#include<iostream>
#include<vector>
#include<string>

using namespace std;


void solve1(){
	string s;
	cin >> s;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string ans = "";
	for (int i = 0; i < s.size(); i++)
	{
		
		if (i == a || i == b || i == c || i == d){
			ans += "\"";
		}
		ans += s[i];
	}
	if (d == s.size())
		ans += "\"";
	cout << ans << endl;
}
int main(){
	solve1();
	//solve2();
	//solve3();
	//solve4();
	return 0;
}