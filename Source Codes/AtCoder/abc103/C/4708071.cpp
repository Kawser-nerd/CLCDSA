#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
typedef long long LL;
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	vector<int>array;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		ans += temp;
	}
	printf("%d\n", ans - n);
	return 0;

}