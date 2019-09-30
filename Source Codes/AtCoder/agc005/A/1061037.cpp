//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define INF 2e9
typedef long long ll;
ll n;
char q[211111];
string s;
int main()
{
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]=='T'&&n>0&&q[n]=='S')
			n--;
		else
			q[++n]=s[i];
	}
	cout<<n;
}