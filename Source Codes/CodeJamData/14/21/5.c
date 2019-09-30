#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int i,j,k,m,n,p,q,tmp;
	int T,t,step;
	char s[200];
	char str[200][200];
	int rep[200][200];
	int win;
		
	fscanf(stdin, "%d", &T);
	for(t=1;t<=T;t++)
	{
		fscanf(stdin, "%d", &n);
		for(i=0;i<n;i++)
		{
			fscanf(stdin, "%s", s);
			//printf("%s\n", s);
			
			m=strlen(s);
			k=0;
			for(j=0;j<m;j++) rep[i][j]=0;
			
			for(j=0;j<m;j++)
			{
				if(j==0)
				{
					str[i][k]=s[j];
					rep[i][k]=1;
				}
				else if (s[j]==s[j-1])
				{
					rep[i][k]++;
				}
				else 
				{
					k++;
					str[i][k]=s[j];
					rep[i][k]=1;
				}
			}
			k++;
			str[i][k]='\0';
		}
		
		win=1; step=0;
		for(i=1;i<n;i++) if(strcmp(str[i],str[i-1])!=0) win=0;
		
		if(win==1)
		{		
			/*for(i=0;i<n;i++)
			{	
				printf("%s\n", str[i]);
				for(j=0;j<strlen(str[i]);j++)
				printf("%d", rep[i][j]);
				printf("\n");
			}*/
		
			m=strlen(str[0]);
			for(j=0;j<m;j++)
			{
				for(i=0;i<n;i++)
				for(k=0;k<i;k++)
				if(rep[i][j]>rep[k][j]) 
				{
					tmp=rep[i][j];
					rep[i][j]=rep[k][j];
					rep[k][j]=tmp;
				}
			}
			
			/*for(i=0;i<n;i++)
			{	
				printf("%s\n", str[i]);
				for(j=0;j<strlen(str[i]);j++)
				printf("%d", rep[i][j]);
				printf("\n");
			}*/
			
			p = n/2;
			for(j=0;j<m;j++)
			for(i=0;i<n;i++)
			{
				q = rep[i][j] - rep[p][j];
				if(q<0) q=-q;
				step += q;
			}
		}
		
		if(win==1) printf("Case #%d: %d \n", t, step);
		if(win==0) printf("Case #%d: Fegla Won\n", t);
	}

	return 0;
}
			
		