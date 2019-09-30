#include<stdio.h>
#include<stdlib.h>

FILE *fin, *fout;

typedef struct
{
	int s, w, t;
}intersectie;

intersectie a[21][21];
int v[50][50], n, m;

int cross(int i, int j, int t, int dir)
{
	intersectie x;
	x = a[i/2][j/2];
	if(i%2==0 && dir==0) return 2;
	if(i%2==1 && dir==2) return 2;
	if(j%2==0 && dir==3) return 2;
	if(j%2==1 && dir==1) return 2;
	if(dir==0 || dir==2)
	{
		if(t<x.t)
        {
			if(x.t-t > x.w) return 1;
			return x.t-t+1;
		}
		t-=x.t;
        t %= x.s+x.w;
		if(t<x.s) return 1;
		return x.s+x.w-t+1;
	}
	if(t<x.t)
    {
		if(x.t-t <= x.w) return 1;
		return x.t-x.w-t+1;
	}
	t -= x.t;
	t %= x.s+x.w;
	if(t>x.s) return 1;
	return x.s-t+1;
}	

void cauta(int i, int j)
{
	int s;
	if(i==0 && j==2*m-1) return;
	if(i>0) 
	{
		s = cross(i, j, v[i][j], 0);
		if(v[i-1][j] > v[i][j]+s || v[i-1][j]==-1)
		{
			v[i-1][j] = v[i][j]+s;
			cauta(i-1, j); 
		}
	}
	if(j<2*m-1) 
	{
		s = cross(i, j, v[i][j], 1);
		if(v[i][j+1] > v[i][j]+s || v[i][j+1]==-1)
		{
			v[i][j+1] = v[i][j]+s;
			cauta(i, j+1); 
		}
	}
	if(i<2*n-1) 
	{
		s = cross(i, j, v[i][j], 2);
		if(v[i+1][j] > v[i][j]+s || v[i+1][j]==-1)
		{
			v[i+1][j] = v[i][j]+s;
			cauta(i+1, j); 
		}
	}
	if(j>0) 
	{
		s = cross(i, j, v[i][j], 3);
		if(v[i][j-1] > v[i][j]+s || v[i][j-1]==-1)
		{
			v[i][j-1] = v[i][j]+s;
			cauta(i, j-1); 
		}
	}
}

int main()
{
    int t, i, j, k;
	fin = fopen("date.in", "rt");
    fout = fopen("date.out", "wt");
    fscanf(fin,"%i",&t);
    for(k=1; k<=t; k++)
	{
		fscanf(fin, "%i %i", &n, &m);
		for(i=0; i<n; i++)
			for(j=0; j<m; j++) 
            {
                fscanf(fin, "%i %i %i", &a[i][j].s, &a[i][j].w, &a[i][j].t);
                a[i][j].t %= a[i][j].s+a[i][j].w;
            }
        for(i=0; i<2*n; i++)
            for(j=0; j<2*m; j++) v[i][j] = -1;
		v[2*n-1][0] = 0;
        cauta(2*n-1, 0);
		fprintf(fout, "Case #%i: %i\n", k, v[0][2*m-1]);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
		
			
		
	
		
