#include <iostream>
#include <cstring>

bool atCoder(char c){
	if(c == 'a' || c == 't' || c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'r'){
		return 1;
	}
	return 0;
}

using namespace std;
int main(){
	char s[12];
	char t[12];
	cin >> s;
	cin >> t;
	int len = strlen(s);
	for(int i = 0; i < len; i++){
		if(s[i] == '@'){
			if(atCoder(t[i]) == 1){
				continue;
			}
		}else if(t[i] == '@'){
			if(atCoder(s[i]) == 1){
				continue;
			}
		}
		if(s[i] != t[i]){
			cout << "You will lose" << endl;
			return 0;
		}
	}
	cout << "You can win" << endl;
	return 0;
}