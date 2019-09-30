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
	int k,s;
	scanf("%d%d",&k,&s);
	int i,j,b,sum=0;
	for(i=0;i<=k;i++){
		for(j=0;j<=k&&j<=s-i;j++){
			if(s-i-j<=k) sum++;
		}
	}
	printf("%d\n",sum);
}