#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <string>
#include <ctime>

using namespace std;

#define rep(x, y, z) for(int x = (y), end##x = (z); x < end##x; x++)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL_DEBUG

#define DebugPrint(...) fprintf(stderr, __VA_ARGS__);

#else

#define DebugPrint(...)

#endif

typedef long long ll;
typedef pair<int, int> pii;

void test(int testNum);

void init()
{

}

int main()
{
	//
#ifdef LOCAL_DEBUG

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

#else

	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

#endif

	clock_t cl = clock();

	init();

	int tc;
	scanf("%d", &tc);

	rep(i, 0, tc)
	{
		test(i+1);
		DebugPrint("%d\n", i+1)
	}

#ifdef LOCAL_DEBUG

	fprintf(stderr, "\nTime used: %lf\n", (clock() - cl) / (double)CLOCKS_PER_SEC);

#endif

	return 0;
}

struct chest
{
	int neededKey;
	vector<int> keysInside;
	bool was;
	bool taken;
} chests[220];


int chestsCount;

vector<int> initialKeys;
vector<int> currentKeys;
vector<vector<int> > chestsForKeys;
vector<int> leftChestsForKeys;

bool canReach(int dest)
{
	queue<pii> bfsQueue;

	rep(i, 0, chestsCount)
	{
		chests[i].was = 0;
	}

	bool visitedKeys[220];
	memset(visitedKeys, 0, sizeof(visitedKeys));

	rep(i, 0, currentKeys.size())
	{
		if (currentKeys[i] > 0)
		{
			visitedKeys[i] = 1;
			bfsQueue.push(pii(i, 0));
		}
	}

	while (!bfsQueue.empty())
	{
		pii cur = bfsQueue.front();
		bfsQueue.pop();

		if (cur.second == 0)
		{
			vector<int> &chestIndexes = chestsForKeys[cur.first];
			rep(i, 0, chestIndexes.size())
			{
				int curInd = chestIndexes[i];
				chest &curChest = chests[curInd];
				if (curChest.was || curChest.taken)
				{
					continue;
				}
				curChest.was = 1;

				rep(j, 0, curChest.keysInside.size())
				{
					int curKey = curChest.keysInside[j];
					if (visitedKeys[curKey])
						continue;
					visitedKeys[curKey] = 1;
					bfsQueue.push(pii(curKey, 0));
				}
			}
		}
	}

	return visitedKeys[dest];
}

bool tryTake(int chestInd)
{
	chest &curChest = chests[chestInd];
	if (curChest.taken)
		return false;
	if (currentKeys[curChest.neededKey] == 0)
		return false;

	currentKeys[curChest.neededKey]--;

	rep(i, 0, curChest.keysInside.size())
	{
		currentKeys[curChest.keysInside[i]]++;
	}
	leftChestsForKeys[curChest.neededKey]--;

	curChest.taken = 1;

	if (currentKeys[curChest.neededKey] > 0)
		return true;
	if (leftChestsForKeys[curChest.neededKey] == 0)
		return true;

	if (canReach(curChest.neededKey))
		return true;

	curChest.taken = 0;

	currentKeys[curChest.neededKey]++;
	leftChestsForKeys[curChest.neededKey]++;
	rep(i, 0, curChest.keysInside.size())
	{
		currentKeys[curChest.keysInside[i]]--;
	}

	return false;
}

void test(int testNum)
{
	printf("Case #%d: ", testNum);

	map<int, int> neededKeys;

	initialKeys.clear();

	int K, N;
	scanf("%d%d", &K, &N);

	chestsForKeys.clear();
	chestsForKeys.resize(N);
	leftChestsForKeys.clear();
	leftChestsForKeys.resize(N, 0);

	vector<int> tk;

	rep(i, 0, K)
	{
		int cur;
		scanf("%d", &cur);
		tk.push_back(cur);
	}

	chestsCount = N;

	rep(i, 0, N)
	{
		int nk;
		chests[i].keysInside.clear();
		chests[i].taken = 0;
		scanf("%d", &nk);
		if (neededKeys.find(nk) == neededKeys.end())
			neededKeys.insert(pii(nk, neededKeys.size()));

		int ki;
		scanf("%d", &ki);

		chests[i].neededKey = neededKeys[nk];
		leftChestsForKeys[chests[i].neededKey]++;
		chestsForKeys[chests[i].neededKey].push_back(i);

		rep(j, 0, ki)
		{
			int ck;
			scanf("%d", &ck);
			chests[i].keysInside.push_back(ck);
		}
	}

	initialKeys.resize(neededKeys.size(), 0);

	rep(i, 0, K)
	{
		if (neededKeys.find(tk[i]) == neededKeys.end())
			continue;
		initialKeys[neededKeys[tk[i]]]++;
	}

	rep(i, 0, N)
	{
		vector<int> newKeysInside;
		chest &curChest = chests[i];

		rep(j, 0, curChest.keysInside.size())
		{
			if (neededKeys.find(curChest.keysInside[j]) == neededKeys.end())
				continue;
			int mappedKey = neededKeys[curChest.keysInside[j]];
			newKeysInside.push_back(mappedKey);
		}
		curChest.keysInside = newKeysInside;
	}
	
	currentKeys = initialKeys;

	vector<int> result;

	rep(i, 0, chestsCount)
	{
		bool foundChest = 0;
		rep(j, 0, chestsCount)
		{
			foundChest = tryTake(j);
			if (foundChest)
			{
				result.push_back(j);
				break;
			}
		}
		if (!foundChest)
		{
			result.clear();
			break;
		}
	}

	if (result.size() == 0)
	{
		printf("IMPOSSIBLE");
	}
	else
	{
		rep (i, 0, result.size())
		{
			printf("%d ", result[i] + 1);
		}
	}

	printf("\n");
}