#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
int cnt[4] = {};
int main(){
	int N; cin >> N;
	string s; cin >> s;
	for (int i = 0; i < N; i++){
		int tmp = (int)s[i] - '0';
		cnt[tmp - 1]++;
	}
	sort(cnt, cnt + 4);
	cout << cnt[3] << " " << cnt[0] << endl;
}