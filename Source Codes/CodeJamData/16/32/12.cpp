#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include<iomanip>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <bitset>
using namespace std;
#define MOD 1000000007
string s[55];
int main(void){
	ifstream cin("B-large.in");
	ofstream cout("output.txt");
	std::ios::sync_with_stdio(false);cin.tie(0);
	int t,T;
	int i,j,n;
	long long x;
	long long m;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n>>m;
		x=1;
		x=x<<(n-2);
		cout<<"Case #"<<t<<": ";
		if(x<m)
		{
			cout<<"IMPOSSIBLE\n";
		}
		else
		{
			cout<<"POSSIBLE\n";
			for(i=0;i<n;i++)
			{
				s[i]="";
				for(j=0;j<n;j++)
					s[i]+='0';
			}
			for(i=1;i<n;i++)
			{
				for(j=i+1;j<n;j++)
					s[i][j]='1';
			}
			m--;
			j=n-1;
			s[0][j]='1';
			j--;
			for(;j>0;j--)
			{
				if(m%2==1)
				{
					s[0][j]='1';
				}
				m/=2;
			}
			for(i=0;i<n;i++)
				cout<<s[i]<<'\n';
		}
	}
	system("pause");
	return 0;
}