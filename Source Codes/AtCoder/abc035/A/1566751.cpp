#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

#define REP(i,n) for(int i=0;(i)<(n);(i)++)
#define ll long long

int main() {
	double a,b;
	cin >> a >> b;
	

	cout << (a/b==4.0/3.0?"4:3":"16:9") << endl;
	return 0;
}