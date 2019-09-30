#include<stdio.h>
int main(void)
{
	int i;
	char a[13];
	scanf("%s",&a);
	if(a[0]>'Z'){
		a[0]=a[0]-32;
	}
	i=1;
	while(a[i]!=0){
		if(a[i]<'a'){
			a[i]=a[i]+32;
		}
		i++;
	}
	printf("%s\n",a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[13]’ [-Wformat=]
  scanf("%s",&a);
        ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&a);
  ^