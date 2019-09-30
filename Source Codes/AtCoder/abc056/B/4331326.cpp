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
	int w,a,b;
	scanf("%d%d%d",&w,&a,&b);
	int num=abs(a-b);
	num=num-w;
	if(num>=0){
		printf("%d\n",num);
	}
	else{
		printf("0\n");
	}
}