#include <vector>
#include <algorithm>
using namespace std;
#include <stdio.h>
#include <string.h>

FILE *Fin = fopen("B-large.in","r");
FILE *Fou = fopen("b.out","w");
//FILE *Fin = stdin;
//FILE *Fou = stdout;

#define MaxN 20000

int n,m,t;

bool check(int tot, int n1, int &ans)
{
	if (tot==0)
	{
		ans = 1;
		return true;
	}
	if (tot>n1*m) return false;
	for (int i=1; i<=n1; i++)
		if (tot%i==0 && tot/i<=m)
		{
			ans = i;
			return true;
		}
	return false;
}

int main()
{
	int i,j,k,caseN;
	fscanf(Fin,"%d",&caseN);
	for (int tt=1; tt<=caseN; tt++)
	{
		fscanf(Fin,"%d%d%d",&n,&m,&t);

		int ans,x1,y1,x2,y2;
		x2 = 0x7FFFFFFF;
		if (check(t, n, ans))
		{
			x2 = ans, x1 = x2;
			y2 = 0, y1 = 0+ t/ans;
		}
		else
		{
			for (i=1; i<=n; i++)
			{
				if ( t-i*m > (n-i)*m ) continue;
				for (j=1; j<=m; j++)
					if (check(t-i*j, n-i, ans))
					{
						x2 = ans, x1 = x2+i;
						y2 = -j, y1 = -j+ (t-i*j)/ans;
						goto FIND;
					}
			}
		}
FIND:
		fprintf(Fou,"Case #%d: ",tt);
		if (x2==0x7FFFFFFF)
			fprintf(Fou,"IMPOSSIBLE\n");
		else
		{
			fprintf(Fou,"%d %d %d %d %d %d\n",0,-y2,x1,y1-y2,x2,0);
		}
	}
	return 0;
}

