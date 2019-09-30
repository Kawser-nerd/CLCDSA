#include <algorithm>
#include <vector>
using namespace std;
#include <stdio.h>
#include <string.h>

FILE *Fin = fopen("A-large.in","r");
FILE *Fou = fopen("a.out","w");
//FILE *Fin = stdin;
//FILE *Fou = stdout;

int n,m;
int n1[1000], n2[1000];

int main()
{
	int i,j,k,caseN,t;
	fscanf(Fin,"%d",&caseN);
	for (t=0; t<caseN; t++)
	{
		fscanf(Fin,"%d",&n);
		for (i=0; i<n; i++)
			fscanf(Fin,"%d",n1+i);
		for (i=0; i<n; i++)
			fscanf(Fin,"%d",n2+i);
		sort(n1, n1+n);
		sort(n2, n2+n);
		long long ans = 0;
		for (i=0; i<n; i++)
			ans += (long long)n1[i]*(long long)n2[n-1-i];
		fprintf(Fou,"Case #%d: %lld\n",t+1,ans);
	}
	return 0;
}

