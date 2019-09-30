//---------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//---------------------------------------------------------------------------


static int comp(const void *p1, const void *p2)
{
	return ((int *)p1)[0]-((int *)p2)[0];
}


int main(int argc, char* argv[])
{
	FILE *fi, *fo;
	int i, j, h, m;
	int n, na, nb, t, f, k;
	int tt[202][3];
	int tr[202][2];
	int tc[2];

	fi=fopen (argv[1], "r");
	fo=fopen (argv[2], "w");

	fscanf(fi, "%d" , &n);

	for (i = 0; i <n; i++)
	{
		tc[0]=0;
		tc[1]=0;
		fscanf(fi,"%d\n%d %d\n", &t, &na, &nb);
		for(j=0; j<na+nb; j++)
		{
			fscanf(fi,"%d:%d", &h, &m);
			tt[j][0]=h*60+m;
			fscanf(fi,"%d:%d", &h, &m);
			tt[j][1]=h*60+m;
			tt[j][2]=(j<na?0:1);
		}
		qsort(tt[0], na+nb, sizeof(int*)*3, comp);
		if (na+nb==0)
		{
			fprintf(fo, "Case #%d: 0 0\n", i);
			continue;
		}

		tr[tc[0]+tc[1]][0]=tt[0][1];
		tr[tc[0]+tc[1]][1]=1-tt[0][2];
		
		tc[tt[0][2]]++;

		for (j=1; j < na+nb; j++)
		{
			f=-1;
			for (k = 0; k < tc[0]+tc[1]; k++) 
			{
				if ((tr[k][0]+t<=tt[j][0])&&(tr[k][1]==tt[j][2])) 
				{
					f=k;
					break;
				}		
			}

			if (f>-1) 
			{
				tr[f][0]=tt[j][1];
				tr[f][1]=1-tt[j][2];
			
			}
			else
			{
				tr[tc[0]+tc[1]][0]=tt[j][1];
				tr[tc[0]+tc[1]][1]=1-tt[j][2];
				tc[tt[j][2]]++;
			}
		}

		fprintf(fo, "Case #%d: %d %d\n", i+1,tc[0],tc[1]);
	}


	fclose(fi);
	fclose(fo);
	return 0;

}
//---------------------------------------------------------------------------
