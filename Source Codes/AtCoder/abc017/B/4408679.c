#include <stdio.h>
#include <string.h>
int main (){
	int k=0;
	char s[1001];
	scanf ("%s",s);
	for (int i=strlen(s)-1;i>-1;){
	if(s[i-1]=='c' && s[i]=='h')
	{
		i=i-2;
		}
	else if(s[i]=='o' || s[i]=='k' || s[i]=='u')
	{
	i--;
		}
		else{
			k=1;
			break;
			}
		}	
	if(k==0)
	{
	printf ("YES\n");	
	}
	else
	{
		printf ("NO\n");
	}
	return 0;
			} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%s",s);
  ^