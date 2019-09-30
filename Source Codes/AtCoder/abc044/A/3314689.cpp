#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,k,x,y,sum;
int main(){
	cin>>n>>k>>x>>y;
	if(n>k)sum=(k*x)+y*(n-k);
	else sum=x*n;
	cout<<sum;
	return 0;
}