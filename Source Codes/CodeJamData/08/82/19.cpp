#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
using namespace std;

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		int n;
		cin >> n;
		map<string, int> m;
		vector<int> offers(n);
		vector<pair<int, int> > offersCoors(n);
		string str;
		int idx=  0;
		for(int i = 0; i < n; i++)
		{
			cin >> str >> offersCoors[i].first >> offersCoors[i].second;
			if(m.find(str) == m.end())
			{
				m[str] = idx++;
			}
			offers[i] = m[str];	
		}
		int minm = 10000000;
		for(int i = 0; i < idx; i++)
		{
			for(int j = i; j < idx; j++)
			{
				for(int k =  j; k < idx; k++)
				{
					vector<pair<int, int> > does;
					for(int p = 0; p < n; p++)
					{
						if(offers[p] == i || offers[p] == j || offers[p] == k)
							does.push_back(offersCoors[p]);
					}
					sort(does.begin(), does.end());
					int toCover = 1;
					int maxm;
					int p = 0;
					int cnt = 0;
					while(toCover <= 10000)
					{
						cnt ++;
						maxm = -1;
						while(p < does.size() && does[p].first <= toCover)
						{
							maxm = max(maxm, does[p].second);
							p++;
							
						}
						if(maxm == -1)
							break;
						else
							toCover = maxm + 1;
					}
					if(toCover > 10000)
					{
						minm = min(minm, cnt);
					}
				}
			}
		}
		if(minm < 100000)
			cout << minm << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
