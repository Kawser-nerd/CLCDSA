#include<stdio.h>
#include<stdlib.h>

FILE *fin, *fout;

int h[100000][11];
int viz[100000];

int happy(int x, int b)
{
	if(h[x][b]==1) return 1;
	if(h[x][b]==-1) return -1;
	int nr[30], i=0, s=x;
	while(s!=0)
	{
		nr[++i] = s%b;
		s/=b;
	}
	nr[0]=i;
	for(i=1; i<=nr[0]; i++) s+=nr[i]*nr[i];
	if(h[s][b]==1)
	{	
		h[x][b] = 1;
		return 1;
	}
	if(h[s][b]==-1)
	{	
		h[x][b] = -1;
		return -1;
	}
	viz[x] = 1;
    if(viz[s]==0) h[x][b] = happy(s,b);
    else h[x][b] = -1;
	viz[x] = 0;
    return h[x][b];
}

int valid(int x, int *v)
{
	int i;
	for(i=1; i<=v[0]; i++)
		if(happy(x,v[i])==-1) return 0;
	return 1;
}

int main()
{
    int t, i, j, k, x, v[10], b;
	char s[30];
	fin = fopen("date.in", "rt");
    fout = fopen("date.out", "wt");
    fscanf(fin,"%i",&t);
    for(i=2; i<=10; i++) h[1][i] = 1;
    for(k=1; k<=t; k++)
	{
		fscanf(fin, "\n");
        fgets(s, 20, fin);
		i=0;
		j=0;
		x = 2;
		while(s[i]>='0' && s[i]<='9')
		{
			b = s[i]-'0';
			if(s[i+1]=='0') b = 10;
			v[++j] = b;
			i+=2;
		}
		v[0] = j;
		while(!valid(x,v)) x++;
		fprintf(fout, "Case #%i: %i\n", k, x);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
		
			
		
	
		
