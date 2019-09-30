#include <stdio.h>
#include <string.h>
int main(){
	char buf[256];
	scanf("%s",buf);
	//printf("%spp\n",buf);
	char *p;
	p = strcat(buf,"pp");
	printf("%s\n",buf);
	return 0;
 } ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",buf);
  ^