#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 5010
using namespace std;

ll a,b,x;

int main()
{
	int i,j;
	cin>>a>>b>>x;
	cout<<b/x-a/x+(bool)(a%x==0);
	
}