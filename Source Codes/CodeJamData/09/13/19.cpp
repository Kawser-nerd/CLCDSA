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

#define PROB_LETTER "C"
#define INTYPE "large"

#define SQR(x) ((x)*(x))

typedef long long lld;
typedef unsigned long long llu;

vector<string> splitString(string s);
string readLine(FILE *inFile);

double dp[100];

lld choose(lld n, lld k)
{
	k = min(k, n-k);

	if (k < 0)
		return 0;

	vector<lld> v;
	for(lld i = 1; i <= k; i++)
		v.push_back(i);

	lld res = 1;

	for(lld i = n; i >= n-k+1; i--)
	{
		res *= i;

		for(int j = 0; j < v.size(); j++)
		{
			if (res % v[j] == 0)
			{
				res /= v[j];
				v.erase(v.begin() + j);
				j--;
			}
		}
	}

	return res;
}

int c, n;

double calc(int k)
{
	if (k == c)
		return 0.0;

	if (dp[k] == -1)
	{
		double res = 0.0;

		lld totalvals = choose(c, n);

		for(int i = 1; i <= n; i++)
		{
			if (k+i > c)
				continue;
			double prob = double(choose(k, n-i)) * double(choose(c-k, i)) / double(totalvals);
			res += prob * (1.0 + calc(k+i));
		}

		if (k >= n)
		{
			double prob0 = double(choose(k, n)) * double(choose(c-k, 0)) / double(totalvals);
			res += prob0;
			res /= (1.0-prob0);
		}

		dp[k] = res;
	}
	return dp[k];
}



string findResult(FILE *inFile)
{
	string instr = readLine(inFile);
	sscanf(instr.c_str(), "%d %d", &c, &n);

	for(int i = 0; i < 100; i++)
		dp[i] = -1;

	stringstream ss;
	
	ss << calc(0);

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
