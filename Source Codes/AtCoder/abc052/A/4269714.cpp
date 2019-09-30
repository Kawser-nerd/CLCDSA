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
	long long a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	if(a*b>c*d){
		printf("%lld\n",a*b);
	}
	else printf("%lld\n",c*d);
}