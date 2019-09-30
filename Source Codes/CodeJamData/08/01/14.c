#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
using namespace std;
int S,Q;
int query[1001];
int best[1001][101];

int calc(int p, int s)
{
	if (p == Q)
		return 0;
	if (best[p][s] >= 0) return best[p][s];
	int& r = best[p][s];
	if (s != query[p])
	{
		r = calc(p+1, s);
//		cout << p << ' ' << s << ' ' << r << endl;
		return r;
	}
	r = 1000000;
	for(int i=0; i<S; i++)
	{
		if (i == s) continue;
		int t = calc(p+1, i) + 1;
		if (t < r) r = t;
	}
//		cout << p << ' ' << s << ' ' << r << endl;
	return r;
}

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	map<string,int> sname;
	for(cc=1;cc<=ca;cc++)
	{
		sname.clear();
		char buf[1024];
		scanf("%d", &S);
		fgets(buf, 1024, stdin);
		for(i=0;i<S;i++)
		{
			fgets(buf, 1024, stdin);
			if (buf[strlen(buf)-1] == '\r' || buf[strlen(buf)-1] == '\n')
				buf[strlen(buf)-1] = 0;
			if (buf[strlen(buf)-1] == '\r' || buf[strlen(buf)-1] == '\n')
				buf[strlen(buf)-1] = 0;
			sname[buf] = i;
		}
		scanf("%d", &Q);
		fgets(buf, 1024, stdin);
		for(i=0;i<Q;i++)
		{
			fgets(buf, 1024, stdin);
			if (buf[strlen(buf)-1] == '\r' || buf[strlen(buf)-1] == '\n')
				buf[strlen(buf)-1] = 0;
			if (buf[strlen(buf)-1] == '\r' || buf[strlen(buf)-1] == '\n')
				buf[strlen(buf)-1] = 0;
//			if (sname.find(buf) == sname.end())
//				cout << "WARNING" << endl;
			query[i] = sname[buf];	
		}
//		cout << S << ' ' << Q << endl;
		for(i=0; i<Q; i++) for(j=0; j<S; j++) best[i][j] = -1;
		int r = 1000000;
		for(k=0; k<S; k++)
		{
			int t = calc(0, k);
//			cout << k << ' ' << t << endl;
			if (t < r) r = t;
		}
		printf("Case #%d: %d\n", cc, r);
	}
}
