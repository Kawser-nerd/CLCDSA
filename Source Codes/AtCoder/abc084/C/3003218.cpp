#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int>c,s,f;
	c.resize(n+1);	s.resize(n+1);	f.resize(n+1);
	for(int i = 1; i <= n-1; ++i){
		cin >> c[i] >> s[i] >> f[i];
	}
	for(int i = 1; i <= n; ++i){
		int t = 0, pos = i;
		while(pos < n){
			if(t <= s[pos]){
				t = s[pos];
			}
			if(t%f[pos]!=0){
				t += f[pos] - (t % f[pos]);
			}
			t += c[pos];
			++pos;
		}
		cout << t << endl;
	}
	return 0;
}