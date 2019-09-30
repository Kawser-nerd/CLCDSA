#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define FR(i,a,n) for(int (i) = (a); (i) < (n); (i)++)
#define FOR(i,n) FR(i,0,n)
#define RF(i,a,n) for(int (i) = int(n)-1; (i) >= (a); (i)--)
#define ROF(i,n) RF(i,0,n)
map<string,int> MAP;
bool basic[11000];
vector<int> ing[11000];

int resolve(string& n)
{
	if(MAP.count(n))
		return MAP[n];
	int res = MAP.size();
	MAP[n] = res;
	if(n[0]>='a' && n[0]<='z')
		basic[res] = true;
	return res;
}

int go(int i)
{
	if(basic[i])
		return 0;
	vector<int> times;
	int res = 0;
	FOR(j,ing[i].size())
		times.push_back(go(ing[i][j]));
	sort(times.begin(), times.end());
	int cur = 0;
	ROF(j,times.size())
	{
		res = max(res, times[j]+cur);
		if(!basic[ing[i][j]])
			cur++;
	}
	res = max(res, cur);
	return res;
}
int main()
{
	int TESTS;
	scanf("%d", &TESTS);
	FOR(tests,TESTS)
	{
		int N;
		scanf("%d", &N);
		MAP.clear();
		FOR(i,11000)
			ing[i].clear();
		memset(basic, 0, sizeof(basic));
		FOR(i,N)
		{
			string name;
			int M;
			cin >> name >> M;
			int id = resolve(name);
			FOR(j,M)
			{
				string ingre;
				cin >> ingre;
				int inid = resolve(ingre);
				ing[id].push_back(inid);
			}
		}
		printf("Case #%d: %d\n", tests+1, go(0)+1);
	}
	return 0;
}
