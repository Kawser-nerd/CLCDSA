#include <Stdio.h>
#include <memory.h>
int l,d,n;
char word[5000][16];
char pos[5000][1000];
int posnum[16];
int sum;
int kuohao;
int p;
char ch;
int i,j,k,m;
char str[6000];
int flag;

void main()
{
    freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);

	
	scanf("%d %d %d",&l,&d,&n);
	for (i=0;i<d;i++)
	{
		scanf("%s",word[i]); 	
	}
	
	for (i=1;i<=n;i++)
	{
		//1 readin
		kuohao=0;
		p=-1;
		scanf("%s",str);
		memset(posnum,0,sizeof(posnum));
		for (j=0;j<strlen(str);j++)
		{
			if (str[j]=='(') { kuohao++; p++;}
			else if (str[j]==')') kuohao--;
			else 
			{
				if (kuohao==0)
				{
					p++;
					pos[p][posnum[p]++]=str[j];
				}
				else
				{
					pos[p][posnum[p]++]=str[j];
				}
			}
		}
		//2 match
		sum=0;
		for (j=0;j<d;j++)
		{//词
			for (k=0;k<l;k++)
			{//位
				flag=0;
				for (m=0;m<posnum[k];m++)
				{//可能的字母
					if (pos[k][m]==word[j][k]) 
					{
						flag=1;
						break;
					}
				}
				if (!flag) break;	
			}
			if (flag) sum++;
		}
		//3 print
		printf("Case #%d: %d\n",i,sum); 

	}
	
}
