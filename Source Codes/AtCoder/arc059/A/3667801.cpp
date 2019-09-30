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
	int n,i,a[105],num=0;
	double sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	int avg;
	if(sum>0) avg=(int)(sum/n+0.5);
	else avg=(int)(sum/n-0.5);
	for(i=0;i<n;i++){
		num+=((a[i]-avg)*(a[i]-avg));
	}
	printf("%d\n",num);
}