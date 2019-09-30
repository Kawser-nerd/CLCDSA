#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>

const int INF = 1000000009;
const long LINF = 1123456789012345678;

long n;
long a[3];
long l[8];

long dfs(long depth, std::vector<long> b){
	if(depth == n){//attachment ended
		std::sort(b.begin(), b.end());
		long ret = 0;
		for(int i = 0; i < 3; i++){
			if(b[i] == 0){//nothing can't be added
				return LINF;
			}
			ret += std::abs(b[i] - a[i]);
		}
		return ret;
	}
	long ret = LINF;
	for(int i = 0; i < 3; i++){
		std::vector<long> c = b;
		c[i] += l[depth];
		if(c[i] == l[depth]){
			ret = std::min(dfs(depth+1, c), ret);
		}else{
			ret = std::min(dfs(depth+1, c) + 10, ret);
		}
	}
	ret = std::min(dfs(depth+1, b), ret);
	return ret;
}

int main(){
	scanf("%ld", &n);
	for(int i = 0; i < 3; i++){
		scanf("%ld", &a[i]);
	}
	std::sort(a, a+3);
	for(int i = 0; i < n; i++){
		scanf("%ld", &l[i]);
	}
	printf("%ld\n", dfs(0, std::vector<long>(3, 0)));
	return 0;
}