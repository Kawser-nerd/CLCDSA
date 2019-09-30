#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<utility>
#include<typeinfo>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef set<int> S;
#define rep(i, n) for(int i=0; i<n; i++)
const ll MOD=1e9+7;

int main(){

	string s;
	int r=0, b=0;
	cin >> s;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='0'){
			r++;
		} else {
			b++;
		}
	}
	cout << 2*min(r, b) << endl;

	return 0;
}