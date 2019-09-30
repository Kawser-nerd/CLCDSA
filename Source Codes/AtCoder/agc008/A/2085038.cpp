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

int main(void) {
	int x, y;
    scanf("%d %d", &x, &y);
    int sx = -1*x;
    int sy = -1*y;
    int ans = 0;
    while (x != y && x != sy && sx != y && sx != sy){
        x++;
        sx++;
        ans++;
    }
    if (x == y){
        printf("%d\n", ans);
        return 0;
    }else if (x == sy){
        ans++;
    }else if (sx == y){
        ans++;
    }else if (sx == sy){
        ans += 2;
    }

    printf("%d\n", ans);
    return 0;
}