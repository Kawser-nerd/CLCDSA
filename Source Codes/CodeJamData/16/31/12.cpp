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
int a[33];
int main(void){
	ifstream cin("A-large.in");
	ofstream cout("output.txt");
	std::ios::sync_with_stdio(false);cin.tie(0);
	int t,T;
	int i,n;
	int sum,themax;
	int num;
	char re1,re2;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n;
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		cout<<"Case #"<<t<<": ";
		while(sum>0)
		{
			themax=0;
			num=0;
			for(i=0;i<n;i++)
			{
				themax=max(themax,a[i]);
			}
			if(themax>1)
			{
				for(i=0;i<n;i++)
				{
					if(a[i]==themax)
					{
						sum--;
						if(num==0)
						{
							re1='A'+i;
							a[i]--;
							num=1;
						}
						else
						{
							re2='A'+i;
							a[i]--;
							num=2;
							break;
						}
					}
				}
			}
			else
			{
				if(sum==2)
				{
					for(i=0;i<n;i++)
					{
						if(a[i]==themax)
						{
							sum--;
							if(num==0)
							{
								re1='A'+i;
								a[i]--;
								num=1;
							}
							else
							{
								re2='A'+i;
								a[i]--;
								num=2;
								break;
							}
						}
					}
				}
				else
				{
					for(i=0;i<n;i++)
					{
						if(a[i]==themax)
						{
							sum--;
							re1='A'+i;
							a[i]--;
							num=1;
							break;
						}
					}
				}
			}
			if(num==1)
				cout<<re1<<' ';
			else
				cout<<re1<<re2<<' ';
		}
		cout<<'\n';
	}
	system("pause");
	return 0;
}