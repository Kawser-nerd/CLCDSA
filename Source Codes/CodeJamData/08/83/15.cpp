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
		
		long long res = 1;
		long long mod = 1000000009;
		int n;
		cin >> n;
		vector<vector<int> > neighbours(n);
		long long colors;
		cin >> colors;
		int x, y;
		for(int i = 0; i <n - 1; i++)
		{
			cin >> x >> y;
			neighbours[x - 1].push_back(y -1 );
			neighbours[y - 1].push_back(x -1 );
		}
		set<pair<int, int> > vis;
		set<pair<int, int> > handled;
		queue<pair<int, int> > toProcess;
		toProcess.push(make_pair(x - 1, y - 1));
		vis.insert(make_pair(x - 1, y - 1));
		vis.insert(make_pair(y - 1, x - 1));

		bool b = false;
		pair<int, int> cur;
		while(!toProcess.empty())
		{
			cur = toProcess.front();
			toProcess.pop();
			handled.insert(make_pair(cur.second, cur.first));
			handled.insert(cur);

			long long cnt = colors;
			for(int i = 0; i < neighbours[cur.first].size(); i++)
			{
				if(neighbours[cur.first][i] == cur.second)
					continue;
				if(vis.find(make_pair(cur.first, neighbours[cur.first][i])) == vis.end())
				{
					vis.insert(make_pair(cur.first, neighbours[cur.first][i]));
					vis.insert(make_pair(neighbours[cur.first][i], cur.first));
					toProcess.push(make_pair(cur.first, neighbours[cur.first][i]));
					continue;
				}
				if(handled.find(make_pair(cur.first, neighbours[cur.first][i])) == handled.end())
					continue;
				cnt--;
				for(int j = 0; j < neighbours[neighbours[cur.first][i]].size(); j++)
				{
					if(neighbours[neighbours[cur.first][i]][j] == cur.first)
						continue;
					if(handled.find(make_pair(neighbours[cur.first][i], neighbours[neighbours[cur.first][i]][j])) != handled.end())
						cnt--;
				}
			}
			for(int i = 0; i < neighbours[cur.second].size(); i++)
			{
				if(neighbours[cur.second][i] == cur.first)
					continue;
				if(vis.find(make_pair(cur.second, neighbours[cur.second][i])) == vis.end())
				{
					vis.insert(make_pair(cur.second, neighbours[cur.second][i]));
					vis.insert(make_pair(neighbours[cur.second][i], cur.second) );
					toProcess.push(make_pair(cur.second, neighbours[cur.second][i]));
					continue;
				}
				if(handled.find(make_pair(cur.second, neighbours[cur.second][i])) == handled.end())
					continue;
				cnt--;
				for(int j = 0; j < neighbours[neighbours[cur.second][i]].size(); j++)
				{
					if(neighbours[neighbours[cur.second][i]][j] == cur.second)
						continue;
					if(handled.find(make_pair(neighbours[cur.second][i], neighbours[neighbours[cur.second][i]][j])) != handled.end())
						cnt--;
				}
			}
			if(cnt <= 0)
			{
				cout << 0 << endl;
				b = true;
				break;
			}
			else
				res = (res * cnt) % mod;
			
		}
		if(!b)
			cout << res % mod << endl;
		
	}
	return 0;
}
