//
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <array>
#include <numeric>
#include <functional>

#define rep(i,n) for(int i=0;i<n;i++)
#define scanInt(i) scanf("%d", &i)

using namespace std;

int main(){

	int a,b,c;
	scanInt(a);
	scanInt(b);
	scanInt(c);

	int ret = c/std::min(a,b);
	printf("%d\n", ret);

	return 0;
}