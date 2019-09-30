#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int D,I,M,N;
int original[101];
int best[101][300];

int calc(int pos, int color)
{
	if (best[pos][color] >= 0) return best[pos][color];
	if (pos >= N) return 0;

	int i,j,k,r;
	best[pos][color] = 1000000;

	r = calc(pos+1, color) + D;
	if (r < best[pos][color]) best[pos][color] = r;
	
	for(i=0; i<=255; i++)
	{
		if (abs(color-i) > M) continue;
		r = calc(pos+1, i) + abs(original[pos]-i);
		if (r < best[pos][color]) best[pos][color] = r;
	}

	for(i=0; i<=255; i++)
	{
		if (i == color) continue;
		if (abs(color-i) <= M)
		{
			r = calc(pos, i) + I;
//			printf("insert %d %d %d %d\n", pos, color, i, r);
			if (r < best[pos][color]) best[pos][color] = r;
		}
	}
//	cout << pos << ' ' << color << ' ' << best[pos][color] << endl;
	return best[pos][color];	
}

int main()
{
	int i,j,k;
	int cc,ca;
	cin >> ca;
	for(cc=1;cc<=ca;cc++)
	{
		cin >> D >> I >> M >> N;
		for(i=0; i<N; i++)
			cin >> original[i];
		int r = 1000000;
		memset(best, 0xff, sizeof(best));
		for(i=0; i<255; i++)
		{
			int nr = calc(0, i);
			if (nr < r) r = nr;
		}
		printf("Case #%d: %d\n", cc, r);
	}
}
