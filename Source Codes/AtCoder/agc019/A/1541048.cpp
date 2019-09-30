#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<vector>
#include <map>
#include <stack>
#include <set>
#include <list>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<climits>
#include<list>
#include <functional>
#include <utility>
#include <numeric>
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)(v).size())
#define PI 3.14159265
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int  main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	///////////////////////////////////////////
ll q,h,s,d,n;
cin>>q>>h>>s>>d>>n;
q*=4;
h*=2;
ull mn=min(q,(min(h,s)));
if(n&1)
{
    if(d>=2*mn)
        cout<<n*mn<<endl;
    else cout<<((n-1)/2)*d+mn<<endl;

}
else
{if(d>=2*mn)
        cout<<n*mn<<endl;
    else cout<<((n)/2)*d<<endl;

}
	return 0;
}