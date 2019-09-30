#include <stdio.h>

int main(){
	char s[4];
	scanf("%s",s);
	int i,j;
	for(i = 0;i<4;i++)
		s[i] -= 0x30;

	for(i = 0;i<(1<<(4-1));i++){
		int tmp[3] = {0};
		int sum = s[0];
		for(j = 0;j<=2;j++){
			if(i&(1<<j)){
				sum -= s[j+1];	
				tmp[j] = 1;
			}else
				sum += s[j+1];
		}
		if(sum == 7){
			for(j = 0;j<=2;j++){
				printf("%d",s[j]);
				if(tmp[j] == 1)
					printf("-");
				else
					printf("+");
			}
			printf("%d=7\n",s[3]);
			break;
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^