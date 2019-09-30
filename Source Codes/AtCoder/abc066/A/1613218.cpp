#include<cstdio>
#include<map>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(){
	int a[3];cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	cout<<a[0]+a[1]<<endl;
	return 0;
}