#include <iostream>

using namespace std;

const string target = "welcome to code jam";
const string empty = "";
int ways[20];

int main(){
	int n; cin >> n; string temp; getline(cin,temp);
	for (int zzz = 1; zzz <= n; zzz++){
		string s; getline(cin,s);
		ways[0] = 1;
		for (int i = 1; i < 20; i++)
			ways[i] = 0;
		for (int i = 0; i < s.length(); i++)
			for (int pos = 19; pos > 0; pos--)
				if (s[i] == target[pos-1]) ways[pos] = (ways[pos] + ways[pos-1]) % 10000;
		string ss = ""; int ans = ways[19];
		//cout << ans << endl;
		for (int i = 0; i < 4; i++){
			ss = empty + (char)(ans%10 + '0') + ss;
			ans /= 10;
		}
		cout << "Case #" << zzz << ": " << ss << endl;
	}
	return 0;
}
