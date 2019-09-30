#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
using ulong = unsigned long;
using ll = long long;

int s[201][201];

bool calc(int n, int idx){
	ll ret = 1;
	while(idx < n){
		int iNot0 = -1;
		for(int i=idx;i<n;i++){
			if(s[i][idx]){ 
				iNot0 = i;
				break;
			}
		}
		if(iNot0 == -1){ ret = 0; break;}
		for(int i=idx;i<n;i++){
			swap(s[idx][i], s[iNot0][i]);
		}
		// if((iNot0 - idx) % 2 == 1){
		// 	ret = -ret;
		// }
		for(int i=idx+1;i<n;i++){
			if(s[i][idx] == 0){ continue; }
			for(int j=idx+1;j<n;j++){
				s[i][j] ^= s[idx][j];
			}
		}
		// ret *= s[idx][idx];
		// ret %= 2;
		++idx;
	}
	return ret % 2 == 0;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char c;
			cin >> c;
			s[i][j] = c - '0';
			// cin >> s[i][j];
		}
	}
	cout << (calc(n, 0) ? "Even" : "Odd") << endl;
	return 0;
}