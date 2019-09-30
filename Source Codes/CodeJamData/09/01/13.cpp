#include <iostream>
#include <vector>

using namespace std;

int l, d, n;
string words[5100];
bool patterns[15][26];

int main(){
	cin >> l >> d >> n;
	for (int i = 0; i < d; i++)
		cin >> words[i];
	for (int zzz = 1; zzz <= n; zzz++){
		string s; cin >> s;
		int pos = 0;
		for (int i = 0; i < l; i++){
			for (int j = 0; j < 26; j++)
				patterns[i][j] = false;
			if (s[pos] == '('){
				pos++;
				for (; s[pos] != ')'; pos++){
					patterns[i][s[pos]-'a'] = true;
				}
			}
			else patterns[i][s[pos]-'a'] = true;
			pos++;
		}
		int cnt = 0;
		for (int i = 0; i < d; i++){
			bool okay = true;
			for (int j = 0; j < l; j++){
				if (!patterns[j][words[i][j]-'a']){
					okay = false; break;
				}
			}
			
			if (okay) cnt++;
		}
		cout << "Case #" << zzz << ": " << cnt << endl;
	}
	return 0;
}
