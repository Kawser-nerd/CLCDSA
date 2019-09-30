#include<stdio.h>
#include<string.h>
#include<memory.h>
#define BASE 10000
char a[512];
char b[32]="welcome to code jam";
int d[512][32];
int main()
{
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");

	int i, j;
	int t, tc;
	fscanf(fp, "%d\n", &tc);
	for(t=1;t<=tc;t++)
	{
		fgets(a, 505, fp);
		memset(d, 0, sizeof(d));
		if(a[0]=='w') d[0][0]=1;
		for(i=1;a[i];i++)
		{
			d[i][0]+=d[i-1][0];
			if(b[0]==a[i]) d[i][0]++;
			for(j=1;j<=18;j++)
			{
				d[i][j]+=d[i-1][j];
				if(b[j]==a[i]) d[i][j]+=d[i-1][j-1];
				d[i][j]%=BASE;
			}
		}
		fprintf(ofp, "Case #%d: %04d\n", t, d[i-1][18]);
	}
	return 0;
}
