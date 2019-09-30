#include <stdio.h>
#include <string.h>
int min(int a,int b){
	int min = a;
	if(min>b)min=b;
	return min;
}
int main(void){
	int num0=0;
	int num1=0;
	char s[100000];
	scanf("%s",s);
	int n = strlen(s);
	int i;
	for(i=0;i<n;i++){
		if(s[i]=='0'){
			num0++;
		}else if (s[i]=='1'){
			num1++;
		}
	}
	int ans = min(num0,num1)*2;
	//printf("num0 = %d\n",num0);
	//printf("num1 = %d\n",num1);
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^