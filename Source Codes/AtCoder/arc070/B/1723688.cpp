# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <numeric>
#include <tuple>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 1000000000 + 7;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);

int a[5011];
bitset<5011> dp[5011];

int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 0; i<n; i++) cin >> a[i];
	sort(a, a + n);
	int left = 0, right = n - 1;
	int ans = n;
	while (left <= right){
		int mid = (left + right) >> 1;
		dp[0].reset();
		dp[0].set(0, 1);
		for (int i = 1; i <= n; i++){
			dp[i] = dp[i - 1];
			if (i - 1 != mid&&a[i - 1] <= k) dp[i] |= (dp[i - 1] << a[i - 1]);
		}
		bool pos = 0;
		for (int i = max(0, k - a[mid]); i < k; i++)
		{
			pos |= dp[n][i];
		}
		if (pos)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans << '\n';
}