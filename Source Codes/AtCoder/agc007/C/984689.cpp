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
	double n, d1, x, ans = 0;
	cin >> n >> d1 >> x;
    d1 = d1 + d1 + x;
    x*= 4;
    while(n){
        ans += (d1 * n + x * n * (n - 1) / 2) / 2 / n;
        d1 += d1 / n + 3 * x / 2 / n;
        x += 2 * x / n;
        n--;
    }
    cout << fixed << setprecision(10) << ans << endl;
	return 0;
}