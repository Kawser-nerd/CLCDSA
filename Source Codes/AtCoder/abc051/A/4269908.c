#include<stdio.h>
#include<string.h>
int main() {
	char a[100];
	scanf("%s",a);
	int n=strlen(a);
	for(int i=0;i<n;i++){
		if(a[i]==','){
			a[i]=' ';
		}
	}
	printf("%s",a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",a);
  ^