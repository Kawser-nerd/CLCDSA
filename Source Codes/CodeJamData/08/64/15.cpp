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
vi con[200];
vi con2[200];

int dp[200][200];

bool xcon[200][200];
bool used[200];
int matched[200];
int nn, mm;

int NA, NB;
bool match(int b)
{
	int i;
	for (i=0; i<NA; i++) if (xcon[b][i] && !used[i])
	{
		used[i] = true;
		if (matched[i] == -1 || match( matched[i] ))
		{
			matched[i] = b;
			return true;
		}
	}
	return false;
}

bool ok(int a, int pa, int b, int pb)
{
	int& res = dp[a][b];
	if (res != -1) return res;

	int i, j;
	int aa, bb;

	int nb=con2[b].size(), na=con[a].size();
	if (pb != -1) nb--;
	if (pa != -1) na--;
	

	for (i=0; i<con2[b].size(); i++)
	{
		bb = con2[b][i];
		if (bb == pb) continue;

		for (j=0; j<con[a].size(); j++)
		{
			aa = con[a][j];
			if (aa == pa) continue;
			ok(aa, a, bb, b);
		}
	}

	if (nb > na) return res = 0;

	for (i=0; i<na; i++) for (j=0; j<nb; j++)
		xcon[i][j] = false;

	bool ha = false, hb = false;
	for (i=0; i<con2[b].size(); i++)
	{
		bb = con2[b][i];
		if (bb == pb) {hb = true; continue;}

		ha = false;
		for (j=0; j<con[a].size(); j++)
		{
			aa = con[a][j];
			if (aa == pa) {ha = true; continue;}

			xcon[i-hb][j-ha] = ok(aa,a,bb,b);
		}
	}

	NA = na;
	NB = nb;

	for (j=0; j<na; j++) matched[j] = -1;
	for (i=0; i<nb; i++)
	{
		for (j=0; j<na; j++) used[j] = false;
		if (!match( i )) return res = 0;
	}
	return res = 1;
}

int main()
{
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);

	scanf("%d",&ntc);
	int i;
	int a, b;
	for (tc=1; tc<=ntc; tc++)
	{
		scanf("%d",&n);
		for (i=0; i<n; i++) con[i].clear();
		for (i=0; i<n-1; i++)
		{
			scanf("%d %d",&a,&b);
			a--; b--;

			con[a].push_back( b );
			con[b].push_back( a );
		}

		scanf("%d",&m);
		for (i=0; i<m; i++) con2[i].clear();
		for (i=0; i<m-1; i++)
		{
			scanf("%d %d",&a,&b);
			a--; b--;
			con2[a].push_back( b );
			con2[b].push_back( a );
		}


		for (i=0; i<n; i++)
		{
			memset(dp, -1, sizeof(dp));
			if (ok(i, -1, 0, -1)) break;
		}
		
		printf("Case #%d: ",tc);
		if (i < n) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}