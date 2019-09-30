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

double solve(int n, double d1, double dSum, double x){
    double d2 = d1 + x, d2n_1 = d1 + (2 * n - 2) * x, d2n = d1 + (2 * n - 1) * x;
    cout<<n<<' '<<d1<<' '<<dSum<<endl;
    if(!n){ return 0; }
    return dSum / 2 / n + solve(n - 1, d1 + d1 / n + 5.0 / 2 / n * x, dSum - (d1 + d2 + d2n_1 + d2n) / 2 / n, x + 2 * x / n);
}

int main(){
	double n, d1, x, ans = 0;
	cin >> n >> d1 >> x;
    // cout << fixed << setprecision(10) << solve(n, d1, d1 * 2 * n + 2 * n * x * (2 * n - 1) / 2, x) << endl;

    // double dSum = d1 * 2 * n + 2 * n * x * (2 * n - 1) / 2;
    // while(n){
    //     ans += dSum / 2 / n;
    //     double d2 = d1 + x, d2n_1 = d1 + (2 * n - 2) * x, d2n = d1 + (2 * n - 1) * x;
    //     dSum -= (d1 + d2 + d2n_1 + d2n) / 2 / n;
    //     d1 += d1 / n + 5.0 / 2 / n * x;
    //     x += 2 * x / n;
    //     n--;
    // }

    d1 = d1 + d1 + x;
    x*= 4;
    double dSum = d1 * n + x * n * (n - 1) / 2;
    while(n){
        // cout<<d1<<' '<<dSum<<endl;
        ans += dSum / 2 / n;
        double dn = d1 + x * (n - 1);
        dSum -= (d1 + dn) / 2 / n;
        d1 += d1 / n + 3 * x / 2 / n;
        x += 2 * x / n;
        n--;
    }
    // cout<<dSum<<endl;
    cout << fixed << setprecision(10) << ans << endl;
	return 0;
}