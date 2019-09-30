#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
//#include<string>
//#include<sstream>
using namespace std;

int main(){
	int n;
	long long sum;
	scanf("%d",&n);
	sum=800*n-200*(n/15);
	printf("%lld\n",sum);
}