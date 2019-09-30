#include <stdio.h>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


typedef vector <int> vi;
typedef vector <string> vs;
typedef vector <double> vd;
typedef vector <vi> vvi;
typedef long long LL;
typedef vector <LL> vll;
typedef pair<int,int> pii;


vs token(string s, string d)
{
	vs res;
	string t;
	int pos;
	while (true)
	{
		pos = s.find( d );
		if (pos == -1) break;
		t = s.substr(0, pos);
		s = s.substr(pos + d.length());

		if (t != "") res.push_back( t );
	}
	if (s != "") res.push_back( s );
	return res;
}


vs token(string s)
{
	return token(s, " ");
}


vi s2vi(string s, string d)
{
	vs tmp = token(s, d);
	vi res;
	int i;
	for (i=0; i<tmp.size(); i++)
		res.push_back( atoi(tmp[i].c_str()) );
	return res;
}


vi s2vi(string s)
{
	return s2vi(s, " ");
}

///////////////////////////////////////////////////////


int tc, ntc;

int n, m;
vector <pii> a;
vector <pii> b;
char buf[1000];

#define INF 100000000

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);

	scanf("%d",&ntc);
	int i;
	int p, q;
	for (tc=1; tc<=ntc; tc++)
	{
		scanf("%d",&n);
		a.clear();
		b.clear();


		for (i=0; i<n; i++)
		{
			scanf("%d %d %s",&p,&q,buf);
			if (buf[0] == 'B') a.push_back( make_pair(p,q) );
			else b.push_back( make_pair(p,q));
			gets( buf );
		}

		int a1 = INF, a2 = -INF, b1 = INF, b2 = -INF;
		for (i=0; i<a.size(); i++)
		{
			a1 = min(a1, a[i].first);
			a2 = max(a2, a[i].first);

			b1 = min(b1, a[i].second);
			b2 = max(b2, a[i].second);
		}

		scanf("%d",&m);

		printf("Case #%d:\n",tc);
		fprintf(stderr,"Case #%d:\n",tc);

		int x1, y1, x2, y2;

		while (m--)
		{
			scanf("%d %d",&p,&q);
			if (p>=a1 && p<=a2 && q>=b1 && q<=b2)
			{
				printf("BIRD\n");
				continue;
			}

			x1 = min(a1, p);
			x2 = max(a2, p);
			y1 = min(b1, q);
			y2 = max(b2, q);

			for (i=0; i<b.size(); i++)
			{
				if (b[i].first >= x1 && b[i].first <= x2 && b[i].second >= y1 && b[i].second <= y2)
					break;				
			}

			if (i < b.size()) printf("NOT BIRD\n");
			else printf("UNKNOWN\n");

			if (i < b.size()) fprintf(stderr,"NOT BIRD\n");
			else fprintf(stderr,"UNKNOWN\n");


		}
	}
	
	return 0;
}