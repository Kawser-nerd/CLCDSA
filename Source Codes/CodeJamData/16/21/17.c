#include <stdio.h>
#include <string.h>

int main()
{
	int i,j,k,m,n;
	int T,t;
	char s[2100];
	int c[100];
	int num[10];
	
	fscanf(stdin, "%d", &T);
	for(t=1;t<=T;t++)
	{
		fscanf(stdin, "%s", s);
		n=strlen(s);
		
		for(i=0;i<100;i++) c[i]=0;
		for(i=0;i<10;i++) num[i]=0;
		
		for(i=0;i<n;i++)
		{
			c[s[i]]++;
		}

		
		if(c['X']>0)
		{
			num[6]+=c['X'];
			c['S']-=c['X'];
			c['I']-=c['X'];
			c['X']=0;
		}

		if(c['Z']>0)
		{
			num[0]+=c['Z'];
			c['E']-=c['Z'];
			c['R']-=c['Z'];
			c['O']-=c['Z'];
			c['Z']=0;
		}
		
		if(c['S']>0)
		{
			num[7]+=c['S'];
			c['E']=c['E']-2*c['S'];
			c['V']-=c['S'];
			c['N']-=c['S'];
			c['S']=0;
		}
		
		if(c['V']>0)
		{
			num[5]+=c['V'];
			c['F']-=c['V'];
			c['I']-=c['V'];
			c['E']-=c['V'];
			c['V']=0;
		}		

		if(c['F']>0)
		{
			num[4]+=c['F'];
			c['O']-=c['F'];
			c['U']-=c['F'];
			c['R']-=c['F'];
			c['F']=0;
		}		

		if(c['W']>0)
		{
			num[2]+=c['W'];
			c['T']-=c['W'];
			c['O']-=c['W'];
			c['W']=0;
		}		

		if(c['O']>0)
		{
			num[1]+=c['O'];
			c['N']-=c['O'];
			c['E']-=c['O'];
			c['O']=0;
		}		

		if(c['R']>0)
		{
			num[3]+=c['R'];
			c['E']=c['E']-2*c['R'];
			c['T']-=c['R'];
			c['H']-=c['R'];
			c['R']=0;
		}

		if(c['T']>0)
		{
			num[8]+=c['T'];
			c['E']-=c['T'];
			c['I']-=c['T'];
			c['G']-=c['T'];
			c['H']-=c['T'];
			c['T']=0;
		}

		if(c['I']>0)
		{
			num[9]+=c['I'];
			c['E']-=c['I'];
			c['N']=c['N']-2*c['I'];
			c['I']=0;
		}
		
		printf("Case #%d: ", t);
		for(i=0;i<10;i++)
		for(j=0;j<num[i];j++) printf("%d", i);
		printf("\n");
	}
	
	return 0;
}