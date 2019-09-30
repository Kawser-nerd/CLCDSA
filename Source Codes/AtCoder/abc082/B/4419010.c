#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[101],t[101];
	int ns[101],nt[101];
	scanf("%s%s",s,t);
	int lens=strlen(s),lent=strlen(t);
	int i,k,temp;
	for(i=0;i <= lens-1;i++)
		{ns[i] = s[i];}
	for(i=0;i <= lent-1;i++)
		{nt[i] = t[i];}
	for(i=0;i <= lens-2;i++)
		{
		for(k=0;k <= lens-2-i;k++)
			{
			if(ns[k] > ns[k+1])
				{
				temp = ns[k];
				ns[k] = ns[k+1];
				ns[k+1] = temp;
				}
			}
		}
	for(i=0;i <= lent-2;i++)
		{
		for(k=0;k <= lent-2-i;k++)
			{
			if(nt[k] < nt[k+1])
				{
				temp = nt[k];
				nt[k] = nt[k+1];
				nt[k+1] = temp;
				}
			}
		}
	ns[lens]=0;
/*	for(i=0;i <= lens-1;i++){printf("%d ",ns[i]);}
	printf("\n");
	for(i=0;i <= lent-1;i++){printf("%d ",nt[i]);}
	printf("\n"); */
	int check=1;
	i=0;
	while(check==1 && i <= lent-1)
		{
		if(ns[i] < nt[i]){break;}
		else if(ns[i] == nt[i])
			{
			if(i == lent-1){check=0;}
			else{i++;}
			}
		else{check=0;}
		}
	if(check==0){printf("No\n");}
	else{printf("Yes\n");}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",s,t);
  ^