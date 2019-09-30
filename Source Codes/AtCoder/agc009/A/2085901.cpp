#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <functional>


int descending_compare(const void *a, const void *b) {
	if (*(int*)a > *(int*)b) {
		return -1;
	}
	else if (*(int*)a == *(int*)b) {
		return 0;
	}
	else {
		return 1;
	}
}

int ascending_compare(const void *a, const void *b) {
	if (*(int*)a < *(int*)b) {
		return -1;
	}
	else if (*(int*)a == *(int*)b) {
		return 0;
	}
	else {
		return 1;
	}
}

//greatest common divisor
unsigned long  gcd(unsigned long x, unsigned long y) {
	if (y == 0) {
		return x;
	}
	else if (x > y) {
		return gcd(y, x % y);
	}
	else {
		return gcd(x, y % x);
	}
}



long long factorial(int x) {
	long long rtn = 1;
	int i;
	for (i = x; i > 1; i--) {
		rtn = (rtn*i);
	}
	return rtn;
}

/*
int struct_ascending_compare(const void *p, const void *q) {
return ((struct_name*)p)->member_name - ((struct_name*)q)->member_name;
}*/

long long a[100005];
long long b[100005];

int main(void) {
	int n;
    long long cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%lld %lld", &a[i], &b[i]);
    }
    for (int i = n - 1; i >= 0; i--){
        a[i] += cnt;
        if (a[i] % b[i] != 0) cnt += b[i] - a[i] % b[i];
    }
    printf("%lld\n", cnt);
}