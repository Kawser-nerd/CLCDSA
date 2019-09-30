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
	char s[2];
	int i;
	while( (s[0]=getchar())!=-1){
		if(s[0]=='0'){
			num0++;
		}else if (s[0]=='1'){
			num1++;
		}
	}
	int ans = min(num0,num1)*2;
	//printf("num0 = %d\n",num0);
	//printf("num1 = %d\n",num1);
	printf("%d",ans);
	return 0;
}