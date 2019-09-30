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

int mod=1e9+7;
int main(){
	int n;
	scanf("%d",&n);
	long long sum,i;
	sum=1;
	for(i=1;i<=n;i++){
		sum*=i;
		sum=sum%mod;
	}
	printf("%lld\n",sum);
}