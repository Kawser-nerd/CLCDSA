#include <cstdio>
#include <vector>


using namespace std;

bool canReachWith[200][200];
bool canReachSelfType[200];
int contains[200][200];
bool keyDirect[200][200];
bool opened[200];
bool canViaOther[200];
int type[200];
int noKeys[200];
int N;
int todo[200];

void calcReach()
{
	for (int i=0; i<200; i++)
		for (int j=0; j<200; j++)
			canReachWith[i][j] = keyDirect[i][j];
	
	for (int k=0; k<200; k++)
		for (int i=0; i<200; i++)
			for (int j=0; j<200; j++)
				canReachWith[i][j] = canReachWith[i][j] || (canReachWith[i][k] && canReachWith[k][j]);
}

void calcKeyDirect()
{
	for (int i=0; i<200; i++)
		for (int j=0; j<200; j++)
			keyDirect[i][j] = false;
	
	for (int i=0; i<N; i++)
		for (int j=0; j<200; j++)
			keyDirect[type[i]][j] = keyDirect[type[i]][j] || (contains[i][j] != 0 && !opened[i]);
}

void calcViaOther()
{
	for (int i=0; i<200; i++)
	{
		bool otherPos = false;
		for (int j=0; j<200; j++)
		{
			if (noKeys[j] == 0 || i==j)
				continue;
			otherPos = otherPos || canReachWith[j][i];
		}
		canViaOther[i] = otherPos;
	}
}

void calcReachSelfType()
{
	for (int i=0; i<N; i++)
	{
		canReachSelfType[i] = false;
		for (int j=0; j<200; j++)
		{
			if (contains[i][j] == 0)
				continue;
			
			if (j == type[i])
				canReachSelfType[i] = true;
			canReachSelfType[i] = canReachSelfType[i] || canReachWith[j][type[i]];
		}
	}
}

int pickNext()
{
	for (int i=0; i<N; i++)
	{
		if (opened[i] || noKeys[type[i]] == 0)
			continue;
			
		if (noKeys[type[i]] > 1)
			return i;
		
		if (todo[type[i]] == 1 || canViaOther[type[i]] || canReachSelfType[i])
			return i;
	}
	
	return -1;
}

void doCalc()
{
	calcKeyDirect();
	calcReach();
	calcViaOther();
	calcReachSelfType();
}

void doCase()
{
	int K;
	scanf("%d %d", &K, &N);
	
	for (int i=0; i<200; i++)
		noKeys[i] = 0;
	
	for (int i=0; i<N; i++)
		for (int j=0; j<200; j++)
			contains[i][j] = 0;
	
	for (int i=0; i<N; i++)
		opened[i] = false;
	
	for (int i=0; i<200; i++)
		todo[i] = 0;
	
	for (int i=0; i<K; i++)
	{
		int ck;
		scanf("%d", &ck);
		ck--;
		noKeys[ck]++;
	}
	
	for (int i=0; i<N; i++)
	{
		int Ki;
		scanf("%d %d", &type[i], &Ki);
		type[i]--;
		todo[type[i]]++;
		
		for (int j=0; j<Ki; j++)
		{
			int ck;
			scanf("%d", &ck);
			ck--;
			contains[i][ck]++;
		}
	}
	
	vector<int> sol;
	
	for (int i=0; i<N; i++)
	{
		doCalc();
		int next = pickNext();
		
		if (next == -1)
		{
			printf(" IMPOSSIBLE\n");
			return;
		}
		opened[next] = true;
		noKeys[type[next]]--;
		todo[type[next]]--;
		for (int i=0; i<200; i++)
			noKeys[i] += contains[next][i];
		sol.push_back(next);
	}
	
	for (int i=0; i<N; i++)
		printf(" %d", sol[i]+1);
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i=1; i<=T; i++)
	{
		printf("Case #%d:", i);
		doCase();
	}
	
	return 0;
}
