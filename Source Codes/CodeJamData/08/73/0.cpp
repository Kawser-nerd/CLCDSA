#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

double probs[50][4];
double logProbs[50][4];
vector<double> culProbs;
vector<double> culProbs2;

double MIN = 1e-7;

int min(int a, int b)
{
	if (a < b) return a;
	return b;
}

int main()
{
	int numTest, numProb, numTry;
	scanf("%d", &numTest);
	int i, j, k, l;
	for (i = 0; i < numTest; i++)
	{
		scanf("%d %d", &numTry, &numProb);
		for (j = 0; j < numProb; j++)
		{
			for (k = 0; k < 4; k++)
			{
				scanf("%lf", &probs[j][k]);
				if (probs[j][k] < MIN)
					logProbs[j][k] = -1000;
				else
					logProbs[j][k] = log(probs[j][k]);
			}
		}
		culProbs.clear();
		culProbs.push_back(0.0);
		for (j = 0; j < numProb; j++)
		{
			culProbs2.clear();
			for (k = 0; k < culProbs.size(); k++)
			{
				for (l = 0; l < 4; l++)
					culProbs2.push_back(culProbs[k] + logProbs[j][l]);
			}
			sort(culProbs2.begin(), culProbs2.end(), greater<double>());
			culProbs.clear();
			for (k = 0; k < min(numTry, culProbs2.size()); k++)
			{
				culProbs.push_back(culProbs2[k]);
//				printf("%.3lf ", culProbs2[k]);
			}
//			printf("\n");
		}
		double answer = 0.0;
		for (j = 0; j < min(numTry, culProbs.size()); j++)
		{
			answer += exp(culProbs[j]);
		}
		printf("Case #%d: %.9lf\n", i+1, answer);
	}
	return 0;
}
