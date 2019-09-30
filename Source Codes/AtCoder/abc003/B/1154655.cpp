#include<iostream>
#include<string>
using namespace std;

bool judge(char c){
	switch(c){
		case 'a':
		case 't':
		case 'c':
		case 'o':
		case 'd':
		case 'e':
		case 'r':
			return true;
		default:
			return false;
	}
}
int main(){
	string a, b;
	cin >> a >> b;
	string at = "atcoder";
	bool win = true;
	for (int i=0; i<b.size() && win; i++){
		if(a[i] == b[i]) continue;
		else {
			win = false;
			if(a[i] == '@') win = judge(b[i]);
			if(b[i] == '@') win = judge(a[i]);
		}
	}

	cout << (win? "You can win": "You will lose") << endl;
}