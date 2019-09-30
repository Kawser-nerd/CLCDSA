#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int ca,cc;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		int n;
		vector<long long> va,vb;
		long long t;
		cin >> n;
		for(i=0; i<n; i++)
		{
			cin >> t;
			va.push_back(t);
		}
		for(i=0; i<n; i++)
		{
			cin >> t;
			vb.push_back(-t);
		}
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());
		long long r = 0;
		for(i=0; i<n; i++)
		{
//			fprintf(stderr, "%lld\n", r);
			r += va[i] * vb[i];
		}
		printf("Case #%d: %lld\n", cc, -r);
	}
}
