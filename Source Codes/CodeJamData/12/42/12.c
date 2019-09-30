#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int R[1001];
double ans[1001][2];
vector<int> seq;

int test(double x, double y, int p)
{
	int i,j,k;
	double r = R[seq[p]];
	double r1;
	for(i=0; i<p; i++)
	{
		double x1 = ans[i][0]; double y1 = ans[i][1];
		r1 = R[seq[i]];

		if ((x1-x)*(x1-x) + (y1-y)*(y1-y) < (r+r1)*(r+r1))
			return 0;
	}

	return 1;
}

int main()
{
	int N,W,L;
	int i,j,k;
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> N >> W >> L;
		for(i=0; i<N; i++)
			cin >> R[i];

		seq.clear();
		for(i=0; i<N; i++) seq.push_back(i);
		
		int step;
		for(step=0; step < 1000000; step++)
		{
			random_shuffle(seq.begin(), seq.end());

			ans[0][0] = ans[0][1] = 0.0;

			for(i=1; i<N; i++)
			{
				double x = W; double y = L;
				
				if (!test(x,y,i)) break;	
				for(j=0; j<1000; j++)
				{
					if (!test(x*0.95, y, i))
						break;
					x*=0.95;
				}
				for(j=0; j<1000; j++)
				{
					if (!test(x, y*0.95, i))
						break;
					y*=0.95;
				}
				ans[i][0] = x; ans[i][1] = y;
			}
			if (i >= N) break;
		}
		if (step >= 1000000)
		{
			printf("fail\n");
			continue;
		}
		double rr[1001][2];
		for(i=0; i<N; i++)
		{
			rr[seq[i]][0] = ans[i][0];
			rr[seq[i]][1] = ans[i][1];
		}

		printf("Case #%d:", cc);
		for(i=0; i<N; i++)
			printf(" %.6lf %.6lf", rr[i][0], rr[i][1]);
		printf("\n");
	}
}
