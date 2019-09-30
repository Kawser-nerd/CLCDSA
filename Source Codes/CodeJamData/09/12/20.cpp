#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

#define PROB_LETTER "B"
#define INTYPE "large"

#define SQR(x) ((x)*(x))

typedef long long lld;
typedef unsigned long long llu;

vector<string> splitString(string s);
string readLine(FILE *inFile);

vector<vector<pair<lld,pair<lld,lld> > > > grid;

// i,j,   0=SW 1=NW 2=SE 3=NE
typedef pair<pair<int,int>, int> node;
typedef pair<lld, node> dijnode;

lld nextwest(int i, int j, lld t)
{
	lld orig_t = t;
	lld s = grid[i][j].first;
	lld w = grid[i][j].second.first;
	lld start_t = grid[i][j].second.second;

	lld per = s+w;
	t -= start_t;
	t %= per;
	t += per;
	t %= per;

	if (t < s)
		return orig_t + (s-t) + 1;
	
	return orig_t + 1;
}

lld nextnorth(int i, int j, lld t)
{
	lld orig_t = t;
	lld s = grid[i][j].first;
	lld w = grid[i][j].second.first;
	lld start_t = grid[i][j].second.second;

	lld per = s+w;
	t -= start_t;
	t %= per;
	t += per;
	t %= per;

	if (t < s)
		return orig_t + 1;
	
	return orig_t + (s+w-t) + 1;
}

pair<node,lld> getneigh(int r, int c, int loc, lld t)
{
	return make_pair(make_pair(make_pair(r,c),loc),t);
}

vector<pair<node, lld> > getneighbors(node n, lld t)
{
	vector<pair<node, lld> > res;

	int r = n.first.first;
	int c = n.first.second;

	switch(n.second)
	{
	case 0: // down, left, up, right
		res.push_back(getneigh(r+1, c, 1, t+2));
		res.push_back(getneigh(r, c-1, 2, t+2));
		res.push_back(getneigh(r, c, 1, nextnorth(r,c,t)));
		res.push_back(getneigh(r, c, 2, nextwest(r,c,t)));
		break;
	case 1:
		res.push_back(getneigh(r, c, 0, nextnorth(r,c,t)));
		res.push_back(getneigh(r, c-1, 3, t+2));
		res.push_back(getneigh(r-1, c, 0, t+2));
		res.push_back(getneigh(r, c, 3, nextwest(r,c,t)));
		break;
	case 2:
		res.push_back(getneigh(r+1, c, 3, t+2));
		res.push_back(getneigh(r, c, 0, nextwest(r,c,t)));
		res.push_back(getneigh(r, c, 3, nextnorth(r,c,t)));
		res.push_back(getneigh(r, c+1, 0, t+2));
		break;
	case 3:
		res.push_back(getneigh(r, c, 2, nextnorth(r,c,t)));
		res.push_back(getneigh(r, c, 1, nextwest(r,c,t)));
		res.push_back(getneigh(r-1, c, 2, t+2));
		res.push_back(getneigh(r, c+1, 1, t+2));
		break;
	}

	for(int i = 0; i < res.size(); i++)
	{
		if (res[i].first.first.first < 0 || res[i].first.first.first >= grid.size() ||
			res[i].first.first.second < 0 || res[i].first.first.second >= grid[0].size())
		{
			res.erase(res.begin() + i);
			i--;
		}
	}

	return res;
}

lld dij(node start, node end)
{
	priority_queue<dijnode, vector<dijnode>, greater<dijnode> > pq;

	pq.push(make_pair(0, start));
	map<node, lld> best;
	best[start] = 0;

	while(pq.size())
	{
		dijnode nod = pq.top();
		pq.pop();

		if (nod.second == end)
			return nod.first;


		if (best.count(nod.second) &&
			nod.first > best[nod.second])
			continue;

		vector<pair<node, lld> > neighbors = getneighbors(nod.second, nod.first);

		for(int i = 0; i < neighbors.size(); i++)
		{
			lld dist = neighbors[i].second;

			if (!best.count(neighbors[i].first) ||
				dist < best[neighbors[i].first])
			{
				best[neighbors[i].first] = dist;
				pq.push(make_pair(dist, neighbors[i].first));
			}
		}
	}

	return -1;
}

string findResult(FILE *inFile)
{
	grid.clear();
	string vals = readLine(inFile);

	int n,m;
	sscanf(vals.c_str(), "%d %d", &n, &m);

	grid.resize(n, vector<pair<lld,pair<lld,lld> > >(m));

	for(int i = 0; i < n; i++)
	{
		vector<string> v = splitString(readLine(inFile));
		
		for(int j = 0; j < v.size(); j += 3)
		{
			int val1, val2, val3;
			string s1 = v[j], s2 = v[j+1], s3 = v[j+2];
			sscanf(s1.c_str(), "%d", &val1);
			sscanf(s2.c_str(), "%d", &val2);
			sscanf(s3.c_str(), "%d", &val3);
			grid[i][j/3] = make_pair(val1, make_pair(val2,val3));
		}
	}

	stringstream ss;

	ss << dij(make_pair(make_pair(n-1, 0), 0), make_pair(make_pair(0, m-1), 3));

	return ss.str();
}

int main()
{
	char *inFilename = PROB_LETTER "-" INTYPE ".in";
	char *outFilename = PROB_LETTER "-" INTYPE ".out";

	FILE *inFile = fopen(inFilename, "r");
	if (inFile == NULL)
	{
		printf("inFile does not exist!\n");
		system("PAUSE");
		return 1;
	}

	FILE *outFile = fopen(outFilename, "w");
	if (outFile == NULL)
	{
		printf("Failed to open outFile!\n");
		system("PAUSE");
		return 1;
	}

	char inBuffer[1000];
	fgets(inBuffer, 1000, inFile);

	int numCases;
	sscanf(inBuffer, "%d", &numCases);

	for(int i = 1; i <= numCases; i++)
	{
		string result = findResult(inFile);

		fprintf(outFile, "Case #%d: %s\n", i, result.c_str());
		printf("Done with case %d\n", i);
	}

	fclose(inFile);
	fclose(outFile);

	printf("Success!\n");
	system("PAUSE");
}

vector<string> splitString(string s)
{
	char *strBuffer = new char[s.size()+1];
	strcpy(strBuffer, s.c_str());
	vector<string> result;

	for(char *theStr = strtok(strBuffer, " "); theStr; theStr = strtok(NULL, " "))
		result.push_back(theStr);

	delete strBuffer;
	return result;
}

string readLine(FILE *inFile)
{
	static char inBuffer[1000000];
	fgets(inBuffer, 1000000, inFile);
	string result = inBuffer;
	if (result.empty())
		return result;
	if (result[result.size() - 1] == '\n')
		result.resize(result.size() - 1);
	return result;
}
