#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,a[100010],x=0;
	cin >> n;
	REP(i,n){
		scanf("%d",&a[i]);
		a[i]--;
	}
	REP(i,n){
		if(x==1){
			cout << i << endl;
			return 0;
		}
		x = a[x];
	}
	cout << -1 << endl;
	return 0;
}