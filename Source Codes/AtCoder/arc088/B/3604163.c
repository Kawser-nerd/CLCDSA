#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
	//?????
	char s[100010];
	int len;
	int i,j;
	int flag=0;
	int ans;
	//????????
	scanf("%s",&s);
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	len=strlen(s);
	if(len%2==1){
		i=1;
		while(flag==0){
			if(s[len/2]!=s[len/2+i]||s[len/2]!=s[len/2-i]){
				i--;
				flag=1;
			}else{
				i++;
				if(2*i-1==len){
					i--;
					flag=1;
				}
			}
		}
		ans=len/2+i+1;
	}else{
		if(s[len/2-1]!=s[len/2]){
			ans=len/2;
		}else{
			i=1;
			while(flag==0){
				if(s[len/2]!=s[len/2+i]||s[len/2]!=s[len/2-i-1]){
					flag=1;
				}else{
					i++;
//					printf("i=%d\n",i);
					if(2*i==len+2){
						i--;
						flag=1;
					}
				}
			}
//			printf("i=%d\n",i);
			ans=len/2+i;
		}
	}
	
//	printf("??????\n");
	
	//??
	printf("%d",ans);
	
//	printf("???????\n");
	
} ./Main.c: In function ‘main’:
./Main.c:21:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100010]’ [-Wformat=]
  scanf("%s",&s);
        ^
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&s);
  ^