#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#define N 1100000
#define L 1000000
#define eps 1e-7
#define inf 1e9+7
#define db double
#define ll long long
#define ldb long double
using namespace std;
inline int read()
{
    char ch=0;
    int x=0,flag=1;
    while(!isdigit(ch)){ch=getchar();if(ch=='-')flag=-1;}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*flag;
}
int main()
{
	ll a=read(),b=read(),c=read();
	if(c<=b+1)
	{
		cout<<b+c;
		return 0;
	}
	else
	{
		if(c-b<=a+1)cout<<b+c;
		else cout<<2*b+a+1;
		return 0;
	}
	return 0;
}