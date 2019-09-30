#include<iomanip>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int N; double D,X;

inline int gi()
{
	char ch; int ret = 0,f = 1;
	do ch = getchar(); while (!(ch >= '0'&&ch <= '9')&&ch != '-');
	if (ch == '-') f = -1,ch = getchar();
	do ret = ret*10+ch-'0',ch = getchar(); while (ch >= '0'&&ch <= '9');
	return ret*f;
}

inline double calc(int n,double d,double x)
{
	if (n == 0) return 0;
	else return calc(n-1,(2*d+2*n*d+5*x)/(2*n),(2*x)/n+x)+d+(2*n-1)*x/2;
}

int main()
{
	//freopen("F.in","r",stdin);
	//freopen("F.out","w",stdout);
	N = gi(); D = gi(); X = gi();
	cout << fixed << setprecision(10) << calc(N,D,X) << endl;
	return 0;
}