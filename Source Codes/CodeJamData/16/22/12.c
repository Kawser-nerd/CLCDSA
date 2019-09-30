#include <stdio.h>

long long strval(const char* s,char tail)
{
	long long v=0;
	while (*s)
	{
		v*=10;
		if (*s=='?') v+=tail-'0';
		else v+=(*s)-'0';
		s++;
	}
	return v;
}

long long mindif,minc,minj;

void cmptail(char* cscore,char* jscore,int tail)
{
	char ctail=(tail&1)?'0':'9';
	char jtail=(tail&2)?'9':'0';
	long long cval=strval(cscore,ctail);
	long long jval=strval(jscore,jtail);
	long long dif=cval-jval;dif=dif>0?dif:-dif;
	if (mindif>dif || (mindif==dif && cval<minc) || (mindif==dif && cval==minc && jval<minj))
	{
		mindif=dif;
		minc=cval;
		minj=jval;
	}
}

void solve(char* cscore,char* jscore)
{
	mindif=0x7fffffffffffffffLL;
	int i=0;
	for (;cscore[i];i++)
	{
		char c=cscore[i],j=jscore[i];
		char cp[4],jp[4];
		int p=0;
		if (c=='?' && j=='?')
		{
			cp[0]='0';cp[1]='1';cp[2]='0';cp[3]='1';
			jp[0]='0';jp[1]='1';jp[2]='1';jp[3]='0';
			p=4;
		}
		else if (c=='?')
		{
			cp[p]=j;jp[p++]=j;
			if (j!='0') {cp[p]=j-1;jp[p++]=j;}
			if (j!='9') {cp[p]=j+1;jp[p++]=j;}
		}
		else if (j=='?')
		{
			cp[p]=c;jp[p++]=c;
			if (c!='0') {cp[p]=c;jp[p++]=c-1;}
			if (c!='9') {cp[p]=c;jp[p++]=c+1;}
		}
		else
		{
			cp[0]=c;
			jp[0]=j;
			p=1;
		}
		if (p)
		{
			while (p--)
			{
				cscore[i]=cp[p];
				jscore[i]=jp[p];
				cmptail(cscore,jscore,0);
				cmptail(cscore,jscore,1);
				cmptail(cscore,jscore,2);
				cmptail(cscore,jscore,3);
			}
			cscore[i]=cp[0];
			jscore[i]=jp[0];
		}
	}
	sprintf(cscore,"%0*lld",i,minc);
	sprintf(jscore,"%0*lld",i,minj);
}

int main()
{
	int cases;scanf("%d",&cases);
	for (int cs=1;cs<=cases;cs++)
	{
		char c[20],j[20];scanf(" %s %s\n",c,j);
		solve(c,j);
		printf("Case #%d: %s %s\n",cs,c,j);
	}
}