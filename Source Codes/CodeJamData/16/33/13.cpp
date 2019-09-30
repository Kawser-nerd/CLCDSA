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
	ifstream cin("C-large.in");
	ofstream cout("output.txt");
	std::ios::sync_with_stdio(false);cin.tie(0);
	int t,T;
	int i,j;
	int tt;
	int a,b,c;
	int num;
	int re,m,k;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>a>>b>>c>>m;
		re=min(a*b*c,a*b*m);
		cout<<"Case #"<<t<<": "<<re<<'\n';
		num=0;
		for(k=0;k<m;k++)
		{
			for(i=1;i<=a;i++)
				for(j=1;j<=b;j++)
				{
					tt=(i+j-1+k)%c;
					if(tt==0)
						tt=c;
					if(num<re)
					{
						num++;
						cout<<i<<' '<<j<<' '<<tt<<'\n';
					}
				}
		}
	}
	system("pause");
	return 0;
}