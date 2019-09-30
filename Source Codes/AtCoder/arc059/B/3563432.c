#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(void)
{
	//?????
	
	char s[100010];
	int i,j,k;
	int len;
	int alphabet[30];
	int abets[30];
	int flag=0;
	
	
	//????????
	scanf("%s",&s);
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	len=strlen(s);
	for(i=0;i<len;i++){
		for(j=0;j<26;j++){
			if(s[i]=='a'+j){
				if(abets[j]==0){
					alphabet[j]=1;
					abets[j]=i+1;
				}else{
					flag=j+1;
					break;
				}
			}else if(alphabet[j]==1){
				alphabet[j]=0;
			}else{
				abets[j]=0;
			}
//			printf("%c alphabet=%d,abets=%d\n",'a'+j,alphabet[j],abets[j]);
		}
		if(flag!=0){
			printf("%d %d",abets[j],i+1);
			return 0;
		}
	}
	
	
	
//	printf("??????\n");
	
	//??
	
	
	printf("-1 -1");
	
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100010]’ [-Wformat=]
  scanf("%s",&s);
        ^
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&s);
  ^