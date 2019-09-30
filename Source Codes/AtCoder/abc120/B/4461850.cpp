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

	int a, b, k;
	cin >> a >> b >> k;
	for(int i=min(a, b); 0<i; i--){
		if(a%i==0 && b%i==0){
			k--;
		}
		if(!k){
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}