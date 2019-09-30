#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

const int N = 2001;
const long long INF = 1e9 + 1;

int main()
{
	int n, X;
	cin >> n >> X;
	int al[N];
	long long min = INF;
	int pos;
	for(int i = 0; i != n; ++i){
		cin >> al[i];
	}
	long long ans = 0;
	long minc[N][2];
	for(int i = 0; i != n; ++i){
		minc[i][0] = al[i];
		ans += minc[i][0];
	}
	for(int k = 1; k != n; ++k){
		long long tmp = 0;
		for(int i = 0; i != n; ++i){
			minc[i][1] = MIN(minc[i][0], al[(i - k + n) % n]);
			tmp += minc[i][1];
		}
		tmp += k * X;
		if(tmp < ans){
			ans = tmp;
		}
		for(int i = 0; i != n; ++i){
			minc[i][0] = minc[i][1];
		}
	}
	cout << ans << endl;
}