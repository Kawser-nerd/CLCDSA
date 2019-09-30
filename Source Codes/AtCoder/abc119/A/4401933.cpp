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

#define int long

const int INF = 1000000009;
const long LINF = 1123456789012345678;

std::string s;

signed main(){
	std::cin >> s;
	if(s[5] == '1' || s[6] > '4'){
		printf("TBD\n");
	}else{
		printf("Heisei\n");
	}
	return 0;
}