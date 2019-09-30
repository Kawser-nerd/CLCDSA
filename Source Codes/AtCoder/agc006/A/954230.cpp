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
	int n;
	string s, t;
	cin >> n >> s >> t;
	for(int i=0;i<s.size();i++){
		bool ok = true;
		for(int j=0;i+j<s.size();j++){
			if(s[i + j] != t[j]){
				ok = false;
				break;
			}
		}
		if(ok){
			cout << max(s.size(), i + t.size()) << endl;
			return 0;
		}
	}
	cout << s.size() + t.size() << endl;
	return 0;
}