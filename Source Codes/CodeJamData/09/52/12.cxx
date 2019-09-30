#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");


int mod = 10009;

int ans[11][16];

vector<string> dict;
int vals[100][26];

int ret[11];

int m =0;
int fun[4];
int n;

void sol()
{
	cout << m << endl;
	int i,j,k;
	int a,b;
	memset(ans,0,sizeof(ans));
	for(i=0; i<(1<<m); i++)
		ans[0][i]=0;
	ans[0][0]=1;
	for(int x=1; x<=10; x++)
	{
		for(i=0; i<(1<<m); i++)
		{
			for(j=0; j<(1<<m); j++)
			{
				if( (i|j)>i)
					continue;
				int tot = 0;
				for(a=0; a<n; a++)
				{
					k=1;
					for(b=0; b<m; b++)
					{
						if( ((1<<b)&j)>0)
						{
							k*=vals[a][fun[b]];
							k%=mod;
						}
					}
					tot+=k;
					tot%=mod;
				}
				tot*=ans[x-1][i-j];
				tot%=mod;
				ans[x][i]+=tot;
				ans[x][i]%=mod;
			}
			if(x==1)
				cout << x << " " << i << " " << ans[x][i] << endl;
		}
	}
	for(i=0; i<=10; i++)
	{
		ret[i]+=ans[i][(1<<m)-1];
		ret[i]%=mod;
	}
	return;
}
				
				

int main(void)
{
	int ttt;
	cin >> ttt;
	int ct = 0;
	
	while(ttt>0)
	{
		ct++;
		ttt--;
		int i,j,k;
		int K;
		string s;
		cin >> s >> K;
		string t;
		cin >> n;
		dict.resize(0);
		for(i=0; i<n; i++)
		{
			for(j=0; j<26; j++)
				vals[i][j]=0;
			cin >> t;
			dict.push_back(t);
			for(j=0; j<t.size(); j++)
			{
				vals[i][t[j]-'a']++;
			}
		}
		for(i=0; i<=10; i++)
			ret[i]=0;
		while(s.size()>0)
		{
			k=0;
			while(k<s.size() && s[k]!='+')
			{
				fun[k]=s[k]-'a';
				k++;
			}
			m=k;
			if(s[k]=='+')
			{
				string t(s,k+1,10000);
				s=t;
			}
			else
			{
				string t;
				s=t;
			}
			sol();
		}
			
		
		
		cout << "Case #" << ct << ":";
		fout << "Case #" << ct << ":";
		for(i=1; i<=K; i++)
		{
			cout <<  " " << ret[i];
			fout << " "<<  ret[i];
		}
		cout << endl;
		fout << endl;
		
	}

	
	return 0;
}

