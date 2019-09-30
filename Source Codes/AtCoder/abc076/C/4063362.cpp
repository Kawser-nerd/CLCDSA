#include<stdio.h>
#include<string.h>
int check(char *p1,char *p2)			//p1?input,p2????? 
{
	int len=strlen(p1),i;
	for(i=0;i<len;i++)
	{
		if(p1[i]!='?')
		{
			if(p1[i]!=p2[i])return 0;
		}
	}
	return 1;
}
void print(char *p)
{
	int len=strlen(p),i;
	for(i=0;i<len;i++)
	{
		if(p[i]=='?')
		{
			printf("a");
		}
		else
		{
			printf("%c",p[i]);
		}
	}
	printf("\n");
}
int main()
{
	int i,j,k;
	char input[51];
	char insert[51];
	char temp[51];						//?????? 
	while(scanf("%s",input)!=-1)
	{
		scanf("%s",insert);
		int len1=strlen(input);
		int len2=strlen(insert);
		int count=0;
		
		for(i=len1-len2;i>=0;i--)
		{
			strcpy(temp,input);				//??input???? 
			strcpy(&temp[i],insert);
			temp[i+len2]=input[i+len2];	//?'\0'?? 
			if(check(input,temp))
			{
				count++;
				print(temp);
				break;
			}
		}
		if(count==0)printf("UNRESTORABLE\n");
	}
 }