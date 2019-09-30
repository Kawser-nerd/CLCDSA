#include<stdio.h>
#include<string.h>
int l,d,n,i,j,k,ti,sel[26],use[50000];
char dict[50000][20],str[2000];
int main()
{
	scanf("%d%d%d",&l,&d,&n);
	for (i=0;i<d;i++) scanf("%s",dict[i]);
	for (ti=1;ti<=n;ti++)
	{
		scanf("%s",str);
		printf("Case #%d: ",ti);
		memset(use,0,sizeof(use));
		for (i=j=0;str[i];j++)
		{
			memset(sel,0,sizeof(sel));
			if (str[i]=='(')
			{
				for (k=i+1;str[k]!=')';k++) sel[str[k]-'a']=1;
				i=k+1;
			}
			else
			{
				sel[str[i]-'a']=1;
				i++;
			}
			for (k=0;k<d;k++)
				if (sel[dict[k][j]-'a']) use[k]+=(1<<j);
		}
		for (i=j=0;i<d;i++)
			if (use[i]==(1<<l)-1) j++;
		printf("%d\n",j);
	}
	return 0;
}
