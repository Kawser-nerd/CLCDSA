#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

struct vendor{double x, m;};
vendor a[210];

int n;
double d;

const double tol=1e-8;

bool works(double t)
{
	int i;
	double lst=a[1].x-t-d;
	for(i=1;i<=n;i++)
	{
		double s=max(lst+d, a[i].x-t); //first location
		double e=s+(a[i].m-1)*d;
		if(e-a[i].x>t) return false;
		lst=e;
	}
	return true;
}

int main()
{
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");
	
	int t, tc;
	double s, e, mid;
	int iter;
	int i;
	fscanf(fp, "%d", &tc);
	for(t=1;t<=tc;t++)
	{
		fscanf(fp, "%d%lf", &n, &d);
		double tot=0.0;
		for(i=1;i<=n;i++)
		{
			fscanf(fp, "%lf%lf", &a[i].x, &a[i].m);
			tot+=a[i].m;
		}
		s=0.0; e=tot*d+1.0;
		for(iter=1;iter<=100 && e-s>tol;iter++)
		{
			mid=(s+e)/2.0;
			if(works(mid)) e=mid;
			else s=mid;
		}
		fprintf(ofp, "Case #%d: %.8lf\n", t, (s+e)/2.0);
	}

	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "cat ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
