#include <stdio.h>
#include <string.h>
int main(){
	char a[100001];
	scanf ("%s",a);
	if (a[0]=='a' && a[1]==0){
		printf ("-1\n");
		}
		else
		{
			printf ("a\n");
		}
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%s",a);
  ^