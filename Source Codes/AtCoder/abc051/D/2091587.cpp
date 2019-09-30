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

int e[105][105];
int d[105][105];
int eb[105][105];


int main(void) {
	int INF = 1000000;
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++)
		{
			e[i][j] = INF;
			d[i][j] = INF;
			eb[i][j] = 1;
		}
	}
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[a][b] = c;
		e[b][a] = c;
		d[a][b] = c;
		d[b][a] = c;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] < e[i][j] && e[i][j] != INF) {
				ans++;
			}
		}
	}
	
	printf("%d\n", ans/2);
	return 0;
}