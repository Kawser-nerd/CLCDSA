#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[101],t[101];
	scanf("%s%s",s,t);
	int lens=strlen(s),lent=strlen(t);
	int i,k,temp;
	for(i=0;i <= lens-2;i++)
		{
		for(k=0;k <= lens-2-i;k++)
			{
			if(s[k] > s[k+1])
				{
				temp = s[k];
				s[k] = s[k+1];
				s[k+1] = temp;
				}
			}
		}
	for(i=0;i <= lent-2;i++)
		{
		for(k=0;k <= lent-2-i;k++)
			{
			if(t[k] < t[k+1])
				{
				temp = t[k];
				t[k] = t[k+1];
				t[k+1] = temp;
				}
			}
		}
	s[lens]=0;
	int check=1;
	i=0;
	while(check==1 && i <= lent-1)
		{
		if(s[i] < t[i]){break;}
		else if(s[i] == t[i])
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
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",s,t);
  ^