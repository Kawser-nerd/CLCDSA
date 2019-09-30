#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,s;
int main()
{
	cin>>n;
	for (i=1;s<n;i++) s+=i;
	cout<<i-1;
	return 0;
}