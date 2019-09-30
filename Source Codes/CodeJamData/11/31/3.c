#include<stdio.h>
int main()
{
	int test,t=0,row,col,flag=0,i,j;
		char ch[100][100];
	scanf("%d",&test);
	while(test--)	
	{
		flag=0;
		scanf("%d%d",&row,&col);
		for(i=0;i<row;i++)
			scanf("%s",ch[i]);
	 	for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(ch[i][j]=='#' && ch[i][j+1]=='#' && ch[i+1][j]=='#' && ch[i+1][j+1]=='#')
				{	
					ch[i][j]='/';
					ch[i][j+1]='\\';
					ch[i+1][j]='\\';
					ch[i+1][j+1]='/';
				}
				else if(ch[i][j]=='#'){
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		printf("Case #%d: \n",++t);
		if(flag==1)
			printf("Impossible\n");
		else
		{
			for(i=0;i<row;i++)
				printf("%s\n",ch[i]);
		}
	}
	return 0;
}
