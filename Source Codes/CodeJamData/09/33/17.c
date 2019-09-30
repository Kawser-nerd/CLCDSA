#include<stdio.h>
#include<string.h>

int used[5],s[5],q,p,uz[101],mincost=10000,prison[5];

void solve()
{
	int i,cost=0,j;

	memset(uz,0,sizeof(uz));
	for(i=0;i<q;i++)
	{
		uz[prison[s[i]]]=1;
		for(j=prison[s[i]]-1;j>=1;j--)
		{
			if(uz[j]==1)
				break;
			cost++;
		}
		for(j=prison[s[i]]+1;j<=p;j++)
		{
			if(uz[j]==1)
				break;
			cost++;
		}
	}
	if(cost<mincost)
		mincost=cost;
}
		
				
void back(int k)
{
	int i;

	if(k==q)
		solve();
	else
	{
		for(i=0;i<q;i++)
		{
			s[k]=i;
			if(!used[i])
			{
				used[i]=1;
				back(k+1);
				used[i]=0;
			}
		}
	}
}

int main()
{
	FILE *f=fopen("prison.in","r");
	FILE *g=fopen("prison.out","w");
	int t,i,j;

	fscanf(f,"%i",&t);
	for(i=0;i<t;i++)
	{
		mincost=10000;
		memset(used,0,sizeof(used));
		fscanf(f,"%i%i",&p,&q);
		for(j=0;j<q;j++)
			fscanf(f,"%i",&prison[j]);
		back(0);
		fprintf(g,"%s%i%s%i\n","Case #",i+1,": ",mincost);
	}
	fclose(f);
	fclose(g);
	return 0;
}






			

	