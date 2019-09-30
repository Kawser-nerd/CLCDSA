#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int N, D;
int d[10001], l[10001];
int f[10001];

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> N;
		for(i=0; i<N; i++)
			cin >> d[i] >> l[i];
		cin >> D;
		memset(f, 0, sizeof(f));

		f[0] = d[0];
		int ok = 0;
		for(i=0; i<N; i++)
		{
			if (f[i] == 0) break;
			if (d[i] + f[i] >= D)
			{
				ok = 1;
				break;
			}
			for(j=i+1; j<N; j++)
			{
				if (d[j] > d[i] + f[i]) break;
				int n = d[j] - d[i];
				if (n > f[j]) f[j] = n;
				if (f[j] > l[j]) f[j] = l[j];
			}
		}
		printf("Case #%d: ", cc);
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
}
