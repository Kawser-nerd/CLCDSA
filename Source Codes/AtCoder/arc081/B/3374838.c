#include <stdio.h>
#include <math.h>


int main(void)
{
	//?????
	int n;
	char s1[55];
	char s2[55];
	int i,j;
	int before=0;
	int now=0;
	long long int count;
	
	//????????
	scanf("%d",&n);
	scanf("%s\n",&s1);
	scanf("%s",&s2);
	
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	
	for(i=0;i<n;i++){
		if(i==0){
			if(s1[0]==s2[0]){
				count=3;
				i++;
				before=0;
			}else{
				count=6;
				i++;
				i++;
				before=1;
			}
			if(n==1){
				break;
			}
		}
		
		if(s1[i]==s2[i]){
			now=0;
		}else{
			now=1;
			i++;
		}
		
		if(before==0){
			count=count*2%1000000007;
		}else if(now==1){
			count=count*3%1000000007;
		}
		
		before=now;
//		printf("i=%d,count=%lld\n",i,count);
	}
	
	
//	printf("??????\n");
	
	//??
	
	printf("%ld",count);
	
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[55]’ [-Wformat=]
  scanf("%s\n",&s1);
        ^
./Main.c:20:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[55]’ [-Wformat=]
  scanf("%s",&s2);
        ^
./Main.c:68:9: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%ld",count);
         ^
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s\n",&s1);
  ^
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&s2);
  ^