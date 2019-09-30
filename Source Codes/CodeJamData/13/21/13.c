#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
int A,N;
int motes[101];

int best;

int main()
{
	int i,j,k;
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> A >> N;
		for(i=0; i<N; i++) cin >> motes[i];
		sort(motes, motes+N);
		best = N;
		int step = 0;
		long long cur = A;
		int p = 0;

		while(p < N)
		{
			while(cur > motes[p] && p < N)
			{
				cur += motes[p]; p++;
			}
			if(p >= N) break;
			if (step + (N-p) < best) best = step + (N-p);
			if (cur <= 1) break;
			if (p == N-1)
			{
				step++;
				break;
			}
			while(cur <= motes[p])
			{
				cur += cur-1; step++;
			}
		}
		if (step + (N-p) < best) best = step + (N-p);
		printf("Case #%d: %d\n", cc, best);
	}
}
