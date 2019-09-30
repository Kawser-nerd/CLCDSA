#include <stdio.h>
#include <string.h>

int main(void)
{
	int s[4];
	int i,j,temp;

	for(i=0;i<=3;i++){scanf("%d",&s[i]);}
	if(s[1]<=s[2] || s[3]<=s[0]){printf("0");}
	else
	{
		for(i=0;i<=2;i++)
			{
			for(j=0;j<=2-i;j++)
				{
				if(s[j]>s[j+1])
					{
					temp=s[j];
					s[j]=s[j+1];
					s[j+1]=temp;
					}}}
		
	int time=s[2]-s[1];
	printf("%d",time);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<=3;i++){scanf("%d",&s[i]);}
                    ^