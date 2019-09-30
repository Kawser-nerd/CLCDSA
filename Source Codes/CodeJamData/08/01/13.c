//---------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>


//---------------------------------------------------------------------------

int n, s, q;
char se[102][102];

char query[101];
int main(int argc, char* argv[])
{
	FILE *fi, *fo;
	int i, j, k, f, u, ans;
	fi=fopen (argv[1], "r");
	fscanf(fi, "%d" , &n);

	fo=fopen (argv[2], "w");
	for (i = 0; i <n; i++)
	{
		ans=0;
		u=0;
		fscanf(fi, "%d\n" , &s);
		for (j = 0; j <s; j++) 
		{
			fgets((char *)&se[j], 100, fi);
			se[j][101]=0;
		}

		fscanf(fi, "%d\n" , &q);
		for (j = 0; j <q; j++) 
		{
			fgets((char *)&query, 100, fi);
			for (k = 0; k <s; k++) 
			{
				f=-1;
				if (strcmp(query, se[k])==0) 
				{
					f=k;
					break;
				}
			}
			if (f>-1)
			{
				if (se[f][101]==0) 
					u++;
				se[f][101]=1;
				
				if (u==s) 
				{
					for (k = 0; k <s; k++) 
						se[k][101]=0;
					se[f][101]=1;
					ans++;
					u=1;

				}
			}
		}		
		fprintf(fo, "Case #%d: %d\n", i+1, ans);
	}
	fclose(fi);
	fclose(fo);
	return 0;

}
//---------------------------------------------------------------------------
