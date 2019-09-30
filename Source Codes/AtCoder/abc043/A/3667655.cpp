#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<string>
//#include<string>
//#include<sstream>
using namespace std;
int main()
{
	int n,i;
	long long sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) sum+=i;
	printf("%lld\n",sum); 
}