#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<functional>
#include<cmath>
#include<algorithm>
typedef  long long ll;
 
int main() {
	int n, a, b,sum = 0,dig = 0;
	int f = 0;
	int count = 0;
	int ans = 0;
	std::cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		f = i;
		while (f!=0) {
			dig = f % 10;
			sum = sum + dig;
			f = f / 10;
		}
		if (sum >= a && sum <= b) {
			ans += i;
		}
		sum = 0;
	}
	std::cout << ans << std::endl;
}