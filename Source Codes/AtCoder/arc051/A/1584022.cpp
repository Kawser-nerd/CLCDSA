#include<iostream>
#include<string.h>
#include<ctype.h>
#include<string>
#include<math.h>
#define pi 3.141592653589
#include<iomanip>
#include<vector>
using namespace std;
#include<algorithm>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define INF 1e9
#define LINF 1e17
#define ll long long
#define MOD (int)(1e9+7)

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

double dir(int x, int y, int a, int b) {
	return sqrt((x - a)*(x - a) + (y - b)*(y - b));
}

int main() {

	int x1, y1, r, x2, y2, x3, y3;

	cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;
	if ((x1 - r >= x2) && (x1 + r <= x3) && (y1 - r >= y2) && (y1 + r <= y3))cout << "NO" << endl;
	else cout << "YES" << endl;
	if ((dir(x1,y1,x2,y2)<=r)&& (dir(x1, y1, x3, y2) <= r)&& (dir(x1, y1, x2, y3) <= r)&& (dir(x1, y1, x3, y3) <= r))cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}