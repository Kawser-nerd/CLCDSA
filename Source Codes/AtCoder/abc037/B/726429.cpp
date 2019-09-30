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

int a[100];

void change(int a[], int l,int r,int t){
		for(int i=l-1; i<r; i++){
			a[i] = t;
		}
		return;
}


int main(){

	int n,q;
	scanInt(n);

	rep(i,n){
		a[i] = 0;
	}

	scanInt(q);

	int l, r, t;
	rep(i,q){
		scanInt(l);
		scanInt(r);
		scanInt(t);
		change(a, l,r, t);
	}

	rep(i,n){
		printf("%d\n", a[i]);
	}

	return 0;
}