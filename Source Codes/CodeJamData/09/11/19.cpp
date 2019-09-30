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

#define PROB_LETTER "A"
#define INTYPE "large"

#define SQR(x) ((x)*(x))

typedef long long lld;
typedef unsigned long long llu;

vector<string> splitString(string s);
string readLine(FILE *inFile);

#define MAXVAL 20000000
bool happy[11][MAXVAL];


int digsum(int n, int base)
{
	int res = 0;

	while(n)
	{
		res += SQR(n % base);
		n /= base;
	}

	return res;
}

bool calchappy(int n, int base)
{
	set<int> seen;

	while(n != 1)
	{
		if (seen.count(n))
			return false;
		seen.insert(n);
		n = digsum(n, base);
	}

	return true;
}

string findResult(FILE *inFile)
{
	vector<string> v = splitString(readLine(inFile));

	vector<int> bases;

	for(int i = 0; i < v.size(); i++)
	{
		int val;
		sscanf(v[i].c_str(), "%d", &val);
		bases.push_back(val);
	}

	int res = -1;
	for(int i = 2; i < MAXVAL; i++)
	{
		bool good = true;
		for(int j = 0; j < bases.size(); j++)
		{
			if (!happy[bases[j]][i])
			{
				good = false;
				break;
			}
		}
		if (good)
		{
			res = i;
			break;
		}
	}

	stringstream ss;

	ss << res;

	return ss.str();
}

int main()
{
	for(int i = 0; i < 11; i++)
	{
		for(int j = 0; j < MAXVAL; j++)
			happy[i][j] = false;
	}

	for(int i = 2; i < 11; i++)
	{
		happy[i][1] = true;

		for(int j = 2; j < 2000; j++)
		{
			happy[i][j] = calchappy(j, i);
		}

		for(int j = 2000; j < MAXVAL; j++)
			happy[i][j] = happy[i][digsum(j, i)];
	}

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
