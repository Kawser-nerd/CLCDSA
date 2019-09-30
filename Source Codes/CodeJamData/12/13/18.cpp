#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

int n;
char side[51];
double vel[51], pos[51];
double INF = 1e100;
double eps = 1e-6;
bool linked[51][51];
bool G[51][51];
bool R[51][51];
int color[51];
bool wrong;

vector <double> keyTime;
int a[1000001], b[1000001], isAdd[1000001];

void dfs(int cur, int c)
{
	if(color[cur] != -1)
	{
		if(color[cur] != c)
			wrong = true;
		return;
	}
	color[cur] = c;
	for(int i = 1; i <= n; i++)
		if(G[cur][i])
			dfs(i, 1 - c);
}

bool crash(int t)
{
	if(isAdd[t])
	{
		R[a[t]][b[t]] = R[b[t]][a[t]] = true;
		G[a[t]][b[t]] = G[b[t]][a[t]] = true;
	}
	else
		R[a[t]][b[t]] = R[b[t]][a[t]] = false;
	/*cout << "t = " << t << endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cout << G[i][j];
		cout << endl;
	}*/
	for(int i = 1; i <= n; i++)
	{
		bool freeNode = true;
		for(int j = 1; j <= n; j++)
			if(i != j)
				if(R[i][j])
					freeNode = false;
		if(freeNode)
		{
			for(int j = 1; j <= n; j++)
				G[i][j] = G[j][i] = false;
		}
	}
	
	memset(color, 0xff, sizeof(color));
	wrong = false;
	for(int i = 1; i <= n; i++)
		if(color[i] == -1)
			dfs(i, 0);
	//cout << !wrong << endl << endl;;
	if(wrong)
		return true;
	return false;
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int CaseID = 1; CaseID <= TestCase; CaseID ++)
	{
		keyTime.clear();
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> side[i] >> vel[i] >> pos[i];
		double minTime = INF;
		
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(vel[i] > vel[j])
				{
					double t = pos[j] - pos[i] - 5.0;
					t /= vel[i] - vel[j];
					if(t > -eps)
					{
						a[(int)keyTime.size()] = i;
						b[(int)keyTime.size()] = j;
						isAdd[(int)keyTime.size()] = 1;
						keyTime.push_back(t);
					}
					
					t = pos[j] - pos[i] + 5.0;
					t /= vel[i] - vel[j];
					if(t > 0)
					{
						a[(int)keyTime.size()] = i;
						b[(int)keyTime.size()] = j;
						isAdd[(int)keyTime.size()] = 0;
						keyTime.push_back(t);
					}
				}

		for(int iteration = 1; iteration <= (int)keyTime.size(); iteration ++)
			for(int i = 0; i < (int)keyTime.size()-1; i++)
				if(keyTime[i] > keyTime[i+1] || (abs(keyTime[i] - keyTime[i+1]) < eps && isAdd[i] > isAdd[i+1]))
				{
					swap(keyTime[i], keyTime[i+1]);
					swap(a[i], a[i+1]);
					swap(b[i], b[i+1]);
					swap(isAdd[i], isAdd[i+1]);
				}
		
		memset(G, false, sizeof(G));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(i != j)
					if(side[i] != side[j])
						G[i][j] = true;

		memset(R, false, sizeof(R));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(i != j)
					if(abs(pos[i] - pos[j]) < 5.0)
						R[i][j] = true;

		for(int i = 1; i <= n; i++)
		{
			bool freeNode = true;
			for(int j = 1; j <= n; j++)
				if(i != j)
					if(R[i][j])
						freeNode = false;
			if(freeNode)
			{
				for(int j = 1; j <= n; j++)
					G[i][j] = G[j][i] = false;
			}
		}

		for(int i = 0; i < (int)keyTime.size(); i++)
			if(crash(i))
			{
				minTime = keyTime[i];
				break;
			}
		if(minTime == INF)
			cout << "Case #" << CaseID << ": " << "Possible" << endl;
		else
			cout << "Case #" << CaseID << ": " << minTime << endl;
	}
	return 0;
}

int main()
{
	#ifdef LOCAL_TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	//int START_TIME = clock();
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	int RUN_RESULT = MAIN();
	//#ifdef LOCAL_TEST
	//cout << endl;
	//cout << "[Time Used] " << clock() - START_TIME << " ms." << endl;
	//#endif
	return RUN_RESULT;
}
