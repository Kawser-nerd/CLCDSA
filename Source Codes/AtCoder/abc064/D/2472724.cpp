#include <iostream>
using namespace std;

int main() {
	int n, depth = 0;
	string s, ans;
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		if (s[i] == '(') depth++;
		else if(depth) depth--;
			else ans = "(" + ans; 
		ans += s[i];
	}
	if (depth) for(int i = 0; i < depth; i++) ans += ")";
	cout << ans;
	return 0;
}