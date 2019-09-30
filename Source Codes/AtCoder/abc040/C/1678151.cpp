#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <map>
#include <set>
using namespace std;
const int INF = 1000000009;

int n;
int pole[100000];
int dp[100000];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &pole[i]);
	}
	dp[0] = 0;
	dp[1] = abs(pole[1]-pole[0]);
	for(int i = 2; i < n; i++){
		dp[i] = min(dp[i-2]+abs(pole[i-2]-pole[i]), dp[i-1]+abs(pole[i-1]-pole[i]));
	}
	printf("%d\n", dp[n-1]);
	return 0;
}