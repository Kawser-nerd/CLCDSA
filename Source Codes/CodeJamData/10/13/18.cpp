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

const int lim=1000000;
int a[1048576];
int bs[1048576], be[1048576];

long long f_intersect(int s1, int e1, int s2, int e2)
{
	return max(0, min(e1, e2)-max(s1, s2)+1);
}

int main()
{
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");

	int i, j;
	a[0]=0;
	for(i=1;i<=lim;i++) a[i]=i-a[a[i-1]];
	for(i=1;i<=lim;i++) bs[i]=a[i-1]+1;
	for(i=j=1;i<=lim;i++)
	{
		for(;j<=lim && bs[j]<=i;j++);
		be[i]=j-1;
	}
	int t, tc;
	fscanf(fp, "%d", &tc);
	long long ans, loses;
	int s1, e1, s2, e2;
	for(t=1;t<=tc;t++)
	{
		fscanf(fp, "%d%d%d%d", &s1, &e1, &s2, &e2);
		loses=0;
		for(i=s1;i<=e1;i++) loses+=f_intersect(s2, e2, bs[i], be[i]);
		ans=(long long)(e1-s1+1)*(long long)(e2-s2+1)-loses;
		fprintf(ofp, "Case #%d: %lld\n", t, ans);
	}

	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "type ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
