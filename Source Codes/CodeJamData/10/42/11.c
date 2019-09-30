#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int cons[2000], P;
int price[2000];
long long best[2000][20];
vector<int> ff[2000];

int tf[2000];

long long calc(int p, int f)
{
	int i,j,k;

	long long&r = best[p][f];
	if (r >= 0) return r;

	if (p >= (1<<(P-1)))
	{
		for(i=0; i<ff[p].size(); i++)
			if (P-f > cons[ff[p][i]])
				break;
		if (i >= ff[p].size())
		{
			r = 0;
			return r;
		}

		for(i=0; i<ff[p].size(); i++)
			if (P-f-1 > cons[ff[p][i]])
				break;
		if (i >= ff[p].size())
		{
			r = price[p];
			return r;
		}

		r = 1000000000ll;
//		cout << p << ' ' << f << ' ' << r << endl;
		return r;
	}

	r = price[p] + calc(p*2, f+1) + calc(p*2+1, f+1);
	r = min(r, calc(p*2, f) + calc(p*2+1, f));

//	cout << p << ' ' << f << ' ' << r << endl;
	return r;
}

int main()
{
	int i,j,k;
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		memset(best, 0xff, sizeof(best));
		cin >> P;
		for(i=0; i<(1<<P); i++)
			cin >> cons[i];
		for(i=(1<<(P-1)); i>=1; i/=2)
			for(j=0; j<i; j++)
				cin >> price[i+j];
		for(i=1; i<(1<<P); i++)
			ff[i].clear();
//		for(i=1; i<(1<<P); i++)
//		{
//			cout << price[i] << endl;
//			ff[i].clear();
//		}

		for(i=0; i<(1<<P); i++)
			ff[1].push_back(i);
		for(i=1; i<(1<<(P-1)); i++)
		{
			for(j=0; j<ff[i].size()/2; j++)
				ff[i*2].push_back(ff[i][j]);
			for(;j<ff[i].size(); j++)
				ff[i*2+1].push_back(ff[i][j]);
		}

//		for(i=0; i<ff[6].size(); i++)
//			cout << ff[6][i] << ' ';
//		cout << endl;
		long long r = calc(1, 0);
		printf("Case #%d: %d\n", cc, r);
	}
}
