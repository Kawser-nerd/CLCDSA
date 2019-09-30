#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <complex>
#include <cassert>

using namespace std;

const int MAX_N = 100 + 10;

int n, src[MAX_N][MAX_N], srcDeg[MAX_N];
int m, trgt[MAX_N][MAX_N], trgtDeg[MAX_N];

struct Tree {
	int deg, maxDepth, totNode, adj[MAX_N];
} srcTree[MAX_N], trgtTree[MAX_N];

void traverse(int vt, int adj[MAX_N][MAX_N], int * deg, Tree * data, int vtPnt)
{
	Tree & cur = data[vt];
	cur.deg = 0;
	cur.maxDepth = 0;
	cur.totNode = 1;
	for (int i = 0; i < deg[vt]; ++i)
		if (adj[vt][i] != vtPnt)
		{
			cur.adj[cur.deg++] = adj[vt][i];
			traverse(adj[vt][i], adj, deg, data, vt);
			cur.maxDepth = max(cur.maxDepth, data[adj[vt][i]].maxDepth + 1);
			cur.totNode += data[adj[vt][i]].totNode;
		}
//	printf("node %d: (%d) \n", vt, vtPnt);
//	for (int i = 0; i < cur.deg; ++i)
//		printf(" %d ", cur.adj[i]);
//	printf("\n");
}

inline void buildTree(int vt, int adj[MAX_N][MAX_N], int * deg, Tree * data)
{
	traverse(vt, adj, deg, data, -1);
}

// ### Matching
namespace Matching {
int degY[MAX_N], adjY[MAX_N][MAX_N], my[MAX_N];
bool vx[MAX_N];
bool aug(int y)
{
	for (int i = 0, cx; i < degY[y]; ++i)
	{
		cx = adjY[y][i];
		if (vx[cx])
			continue;
		vx[cx] = true;
		if (my[cx] == -1 || aug(my[cx]))
		{
			my[cx] = y;
			return true;
		}
	}
	return false;
}

bool canMatch(int leftCnt, int rightCnt)
{
	for (int i = 0; i < leftCnt; ++i)
		my[i] = -1;
	for (int i = 0; i < rightCnt; ++i)
	{
		fill(vx, vx + leftCnt, false);
		if (!aug(i))
			return false;
	}
	return true;
}
};
// ### Matching

inline bool canMatch(int src, Tree * srcTree, int dest, Tree * destTree)
{
	Tree & srcNode = srcTree[src], & destNode = destTree[dest];
	if (srcNode.deg < destNode.deg || srcNode.maxDepth < destNode.maxDepth || srcNode.totNode < destNode.totNode)
		return false;
	if (destNode.deg == 0) // leaf node
		return true;
	vector<int> * right = new vector<int>[destNode.deg];
	for (int i = 0; i < srcNode.deg; ++i)
		for (int j = 0; j < destNode.deg; ++j)
			if (canMatch(srcNode.adj[i], srcTree, destNode.adj[j], destTree))
				right[j].push_back(i);
	for (int i = 0; i < destNode.deg; ++i)
	{
		Matching::degY[i] = 0;
		for (vector<int>::iterator iter = right[i].begin(); iter != right[i].end(); ++iter)
			Matching::adjY[i][Matching::degY[i]++] = *iter;
	}
	delete [] right;
	return Matching::canMatch(srcNode.deg, destNode.deg);
}

inline bool solve()
{
	int bestCnt = -1, bestNode = -1;
	for (int i = 0; i < m; ++i)
		if (trgtDeg[i] > bestCnt)
		{
			bestCnt = trgtDeg[i];
			bestNode = i;
		}
	assert(bestNode != -1);
	buildTree(bestNode, trgt, trgtDeg, trgtTree);
	for (int i = 0; i < n; ++i)
	{
		//printf("###########\n");
		buildTree(i, src, srcDeg, srcTree);
		if (canMatch(i, srcTree, bestNode, trgtTree))
			return true;
	}
	return false;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 0; caseNo < cases; ++caseNo)
	{
		scanf("%d", &n);
		fill(srcDeg, srcDeg + n, 0);
		for (int i = 1, s, t; i < n; ++i)
		{
			scanf("%d %d", &s, &t);
			--s; --t;
			src[s][srcDeg[s]++] = t;
			src[t][srcDeg[t]++] = s;
		}
		scanf("%d", &m);
		fill(trgtDeg, trgtDeg + m, 0);
		for (int i = 1, s, t; i < m; ++i)
		{
			scanf("%d %d", &s, &t);
			--s; --t;
			trgt[s][trgtDeg[s]++] = t;
			trgt[t][trgtDeg[t]++] = s;
		}
		printf("Case #%d: %s\n", caseNo + 1, solve() ? "YES" : "NO");
		cerr << "Case #" << caseNo << endl;
	}
	return 0;
}



