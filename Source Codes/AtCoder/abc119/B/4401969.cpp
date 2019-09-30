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
double sum;

int main(){
	scanf("%ld", &n);
	for(int i = 0; i < n; i++){
		double x;
		char s[3];
		scanf("%lf %s", &x, s);
		if(s[0] == 'J'){
			sum += x;
		}else{
			sum += x * 380000.0;
		}
	}
	printf("%lf\n", sum);
	return 0;
}