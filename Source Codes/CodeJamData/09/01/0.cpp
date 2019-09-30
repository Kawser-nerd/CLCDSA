#include<stdio.h>
#include<memory.h>
#include<string.h>
int n, m, r;
char dat[6000][32];
char a[1024];
bool pos[32][32];
int ans;
int main()
{
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");

	int i, j, tc;
	int cnt;
	fscanf(fp, "%d%d%d", &r, &n, &m);
	for(i=1;i<=n;i++) fscanf(fp, "%s", &dat[i][1]);
	for(tc=1;tc<=m;tc++)
	{
		fscanf(fp, "%s", &a[1]);
		memset(pos, false, sizeof(pos));
		cnt=0;
		for(i=1;a[i];i++)
		{
			cnt++;
			if(a[i]=='(')
			{
				for(j=i+1;a[j]!=')';j++) pos[cnt][a[j]-'a'+1]=true;
				i=j;
			}
			else pos[cnt][a[i]-'a'+1]=true;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=r;j++)
			{
				if(!pos[j][dat[i][j]-'a'+1]) break;
			}
			if(j>r) ans++;
		}
		fprintf(ofp, "Case #%d: %d\n", tc, ans);
	}
	return 0;
}
