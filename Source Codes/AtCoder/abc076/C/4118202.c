#include<stdio.h>
#include<string.h>
int main()
{   
	int l1,l2,i,j,k,t,m;
   	char S[100],T[50];
   	scanf("%s",S);
   	scanf("%s",T);
   	l1=strlen(S);
   	l2=strlen(T);
   	for(i=l1-1;i>=0;i--)
	{
			for(j=i,m=0;j<i+l2;j++,m++) 
			{
				if(S[j]=='?'||S[j]==T[m])
				continue;
				else
				break;
			} 
			if(j==i+l2)
			{
				for(k=i,m=0;k<i+l2;k++,m++)
				{
					S[k]=T[m];  
				}
				for(k=0;k<l1;k++)
				if(S[k]=='?')
					S[k]='a';
				printf("%s",S);
				return 0;
			}
	}
	printf("UNRESTORABLE\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",S);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",T);
     ^