#include <stdio.h>
int main(void){
	int i=0,j=0;
	char a[11],b[11],c[11];
	scanf("%s%s%s",a,b,c);
	while(a[i]!='\0'){
		i++;
	}
	while(b[j]!='\0'){
		j++;
	}
	if(a[i-1]==b[0] && b[j-1]==c[0]) printf("YES\n");
	else printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s%s",a,b,c);
  ^