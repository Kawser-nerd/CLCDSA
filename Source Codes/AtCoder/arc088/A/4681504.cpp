//#include <bits/stdc++.h>
#include <iostream>
#define maxn 3008
#define Max(a,b) a>b?a:b
#define Min(a,b) a<b?a:b
#define X first
#define Y second
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
using namespace std;
#pragma warning(disable:4996)//??????
#pragma comment(linker, "/STACK:102400000,102400000")//????
//ios::sync_with_stdio(false);
//**********????int***********************
ll ans, cans, rans, fans, lans,sum;
int main() {
	ll  x, y;
	cin >> x >> y;
	int a = 0;
	//if (x == 1)x++;
	while (x<= y) {
		if (x > INF / 2+1)break;
		x *= 2; a++;
	}
	cout << a<< endl;
	return 0;
}