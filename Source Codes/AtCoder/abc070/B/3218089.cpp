#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a,b,c,d;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	int l =max(a,c);
	int r = min(b,d);
	cout << max(0,r-l) << endl;
	return 0;
}