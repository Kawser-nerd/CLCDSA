#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void doCase()
{
	int N, M;
	
	scanf("%d %d", &N, &M);
	
	vector<vector<int> > field(N, vector<int>(M));
	
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++)
		{
			int v;
			scanf("%d", &v);
			field[i][j] = v;
		}
	}
	
	vector<int> rowMax(N, 0);
	vector<int> colMax(M, 0);
	
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++)
		{
			rowMax[i] = max(rowMax[i], field[i][j]);
			colMax[j] = max(colMax[j], field[i][j]);
		}
	}
	
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++)
		{
			if (field[i][j] < rowMax[i] && field[i][j] < colMax[j])
			{
				printf("NO\n");
				return;
			}
		}
	}
	
	printf("YES\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i=1; i<=T; i++)
	{
		printf("Case #%d: ", i);
		doCase();
	}
	
	return 0;
}
